include ../makefile.inc

ifeq ($(ARCH),x86_64)
    TARGET          = x86_64-pc-win32-coff
    EFI_OUTPUT_NAME = BOOTX64.EFI
    ENTRY_POINT     = efiApi
else ifeq ($(ARCH),aarch64)
    TARGET          = aarch64-pc-win32-coff
    EFI_OUTPUT_NAME = BOOTAA64.EFI
    ENTRY_POINT     = efiApi
else
    $(error Unsupported architecture: $(ARCH))
endif

BOOT_BUILD_DIR   = $(ACTUAL_BUILD_DIR)/boot
ROOT_OUTPUT_DIR  = ../$(ACTUAL_BUILD_DIR)
EFI_OUTPUT_DIR   = $(ROOT_OUTPUT_DIR)/EFI/BOOT
CONFIGURATION_OUTPUT_DIR   = $(ROOT_OUTPUT_DIR)/BOOT
COMPLEMENTARY_DEPENDENCIES = /complementary

LIB_SRCS         = $(wildcard lib/dependencies/*.c)
APP_SRCS         = $(wildcard app/*.c)
ALL_SRCS         = $(LIB_SRCS) $(APP_SRCS)
OBJS             = $(patsubst %.c,$(BOOT_BUILD_DIR)/%.o,$(ALL_SRCS))

CC              = clang
LD              = lld-link

CFLAGS          = -target $(TARGET) \
                  -fno-stack-protector \
                  -ffreestanding \
                  -fshort-wchar \
                  -mno-red-zone \
                  -Wall \
                  -Wextra \
                  -Iinclude \
                  -I../include \
                  -O2

LDFLAGS         = -subsystem:efi_application \
                  -nodefaultlib \
                  -entry:$(ENTRY_POINT) \
                  -lldmingw \

all: setup complementary efi

efi: $(EFI_OUTPUT_DIR)/$(EFI_OUTPUT_NAME)

setup:
	@mkdir -p $(BOOT_BUILD_DIR)/lib/dependencies
	@mkdir -p $(BOOT_BUILD_DIR)/app
	@mkdir -p $(EFI_OUTPUT_DIR)
	@mkdir -p $(CONFIGURATION_OUTPUT_DIR)

external:

$(BOOT_BUILD_DIR)/%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(EFI_OUTPUT_DIR)/$(EFI_OUTPUT_NAME): $(OBJS)
	@echo "Linking EFI executable: $@"
	@$(LD) $(LDFLAGS) -out:$@ $(OBJS)

clean:
	@rm -rf $(BOOT_BUILD_DIR)
	@rm -f $(EFI_OUTPUT_DIR)/$(EFI_OUTPUT_NAME)

.PHONY: all setup efi clean
