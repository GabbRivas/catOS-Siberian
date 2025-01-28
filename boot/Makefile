include $(CURDIR)/../main.mk

# Ensure proper directory structure for object files
BIN_DIR := $(CURDIR)/../bin/$(ARCH)
BUILD_DIR := $(CURDIR)/../build/$(ARCH)
ENTRY_POINT := appEfiMain

ifeq ($(ARCH),x86_64)
    FILE_NAME := BOOTX64.EFI
else ifeq ($(ARCH),AARCH64)
    FILE_NAME := BOOTAA64.EFI
endif

CC := clang
CFLAGS := -target $(ARCH)-pc-win32-coff -nostdlib -fno-stack-protector -fshort-wchar -mno-red-zone -O2 -fuse-ld=lld -Wall -Wextra
LD := lld-link
LDFLAGS := -subsystem:efi_application -nodefaultlib -entry:$(ENTRY_POINT)

APP := app
DEPENDENCIES := appDependencies
LIBRARIES := appLibraries

SOURCE_FILES := $(wildcard $(APP)/*.c) $(wildcard $(DEPENDENCIES)/*.c) $(wildcard $(LIBRARIES)/*.c)
OBJ_FILES := $(patsubst %.c,$(BIN_DIR)/%.o,$(notdir $(SOURCE_FILES)))
DEP_FILES := $(patsubst %.c,$(BIN_DIR)/%.d,$(notdir $(SOURCE_FILES)))
OUTPUT_FILE := $(BUILD_DIR)/EFI/BOOT/$(FILE_NAME)

.PHONY: all clean

all: $(OBJ_FILES) $(OUTPUT_FILE)

$(OUTPUT_FILE): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)/EFI/BOOT
	$(LD) $(LDFLAGS) $^ -out:$@

$(BIN_DIR)/%.o: $(APP)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BIN_DIR)/%.o: $(DEPENDENCIES)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BIN_DIR)/%.o: $(LIBRARIES)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP_FILES)

clean:
	rm -rf $(OBJ_FILES) $(DEP_FILES) $(OUTPUT_FILE)
