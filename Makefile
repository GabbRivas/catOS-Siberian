# Root Makefile

# Include the main variables
include main.mk

BUILD_DIR=build/$(ARCH)

# Bootloader target
bootloader:
	$(MAKE) -C boot

clean:
	$(MAKE) -C boot clean
	rm -rf $(IMG_NAME)

.PHONY: img
img:
	@echo "Creating disk image..."
	@if ! dd if=/dev/zero of=$(IMG_NAME) bs=1M count=1024; then \
		echo "Failed to create disk image"; exit 1; \
	fi
	@if ! mkfs.fat -F 32 $(IMG_NAME); then \
		echo "Failed to format disk image"; exit 1; \
	fi
	@if ! mmd -i $(IMG_NAME) ::/EFI ::/EFI/BOOT; then \
		echo "Failed to create directories in disk image"; exit 1; \
	fi
	@if ! mcopy -i $(IMG_NAME) $(BUILD_DIR)/EFI/BOOT/BOOTX64.EFI ::/EFI/BOOT/; then \
		echo "Failed to copy bootloader to disk image"; exit 1; \
	fi

# QEMU target
qemu:
	qemu-system-x86_64 -bios ovmf/OVMF_CODE.4m.fd \
	-drive file=img/catOS-x86_64.img,format=raw,media=cdrom -boot d \
	-drive file=ovmf/OVMF_VARS.4m.fd,if=pflash,format=raw \
	-vga virtio -display sdl

qemu-drive:
	qemu-system-x86_64 -bios /usr/share/edk2/x64/OVMF_CODE.4m.fd \
	-drive file=/dev/$(DEBUG_DRIVE),format=raw -boot d \
	-drive file=/usr/share/edk2/x64/OVMF_VARS.4m.fd,if=pflash,format=raw \
	-vga virtio -display sdl

.PHONY: all clean img qemu
