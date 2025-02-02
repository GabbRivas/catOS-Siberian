#Central makefile

USB_DIRECTION=/dev/sda1
OVMFDIR=tools/ovmf

.PHONY:qemu

qemu_4m:
	sudo qemu-system-x86_64 -drive file=$(USB_DIRECTION) -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE.4m.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS.4m.fd" -net none

qemu:
	sudo qemu-system-x86_64 -drive file=$(USB_DIRECTION) -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net none
