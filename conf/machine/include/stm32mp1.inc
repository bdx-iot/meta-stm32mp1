require conf/machine/include/soc-family.inc

DEFAULTTUNE = "cortexa7thf-neon-vfpv4"

SOC_FAMILY = "stm32mp1"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-mainline"

UBOOT_SUFFIX = "img"
UBOOT_ENTRYPOINT = "0xC2000040"

SERIAL_CONSOLES = "115200;ttySTM0"
SERIAL_CONSOLES_CHECK = "${SERIAL_CONSOLES}"

KERNEL_IMAGETYPE ?= "zImage"

# Do not update fstab file when using wic images
WIC_CREATE_EXTRA_ARGS ?= "--no-fstab-update"

# Image
IMAGE_FSTYPES += "tar.bz2 wic wic.gz wic.bmap ext4 ext4.gz"

WKS_FILE_DEPENDS ?= " \
    virtual/bootloader \
    e2fsprogs-native \
    bmap-tools-native \
"

# Wic default support
WKS_FILE ?= "stm32mp1.wks"

# Define specific EXT4 command line:
#   - Create minimal inode number (as it is done by default in image_types.bbclass)
#   - Deactivate metadata_csum not supported by U-Boot
EXTRA_IMAGECMD_ext4 = "-i 4096 -O ^metadata_csum"
