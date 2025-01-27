# Root Makefile

# Include the main variables
include main.mk

BUILD_DIR=build/$(ARCH)

# Bootloader target
bootloader:
	$(MAKE) -C boot

clean:
	$(MAKE) -C boot clean

.PHONY: img
img:
	# Create a blank disk image (1GB size)
	dd if=/dev/zero of=$(IMG_NAME) bs=1M count=1024

	# Format the image with FAT32 (required for EFI)
	mkfs.fat -F 32 $(IMG_NAME)

	# Copy the build directory contents into the image using mcopy
	mcopy -i $(IMG_NAME) $(BUILD_DIR) ::/


# QEMU target
qemu:
	qemu-system-x86_64 -bios ovmf/OVMF_CODE-pure-efi.fd \
	-drive file=iso/catOS-x86_64.img,format=raw,media=cdrom -boot d \
	-drive file=ovmf/OVMF_VARS-pure-efi.fd,if=pflash,format=raw \
	-vga virtio -display sdl
