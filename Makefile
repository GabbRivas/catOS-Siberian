# Root Makefile
include makefile.inc

OVMFDIR = tools/ovmf
IMGSIZE = 64M  # 64MB FAT32 image

.PHONY: all buildImg qemu clean

all: buildImg

buildImg: build
	@echo "Creating bootable disk image..."
	@dd if=/dev/zero of=iso/$(OSNAME).img bs=$(IMGSIZE) count=1
	@mkfs.fat -F 32 iso/$(OSNAME).img
	@mmd -i iso/$(OSNAME).img ::/EFI ::/EFI/BOOT
	@mcopy -i iso/$(OSNAME).img -s $(ACTUAL_BUILD_DIR)/EFI/BOOT/* ::/EFI/BOOT/
	@echo "Disk image created at iso/$(OSNAME).img"

qemu: buildImg
ifeq ($(ARCH),x86_64)
	@echo "Starting QEMU for x86_64..."
	@qemu-system-x86_64 \
		-drive if=pflash,format=raw,readonly=on,file=$(OVMFDIR)/OVMF_CODE.4m.fd \
		-drive if=pflash,format=raw,file=$(OVMFDIR)/OVMF_VARS.4m.fd \
		-drive file=iso/$(OSNAME).img,format=raw,media=disk \
		-net none \
		-serial mon:stdio
else ifeq ($(ARCH),aarch64)
	@echo "Starting QEMU for AArch64..."
	@qemu-system-aarch64 \
		-machine virt \
		-cpu cortex-a72 \
		-drive if=pflash,format=raw,file=$(OVMFDIR)/OVMF_CODE.4m.fd \
		-drive file=iso/$(OSNAME).img,format=raw,media=disk \
		-net none \
		-serial mon:stdio
else
	$(error Unsupported architecture for QEMU: $(ARCH))
endif

clean:
	@rm -rf iso/$(OSNAME).img
	@rm -rf $(ACTUAL_BUILD_DIR)
	@echo "Cleaned build artifacts and disk image"
