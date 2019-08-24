require conf/machine/include/soc-family.inc

DEFAULTTUNE = "cortexa7thf-neon-vfpv4"

SOC_FAMILY = "stm32mp1"

PREFERRED_PROVIDER_virtual/bootloader ??= "u-boot-mainline"
PREFERRED_PROVIDER_virtual/kernel ??= "linux-mainline"

# With kernels >=5.2  systemd-networkd is unable to bring up the link.
# So backport upstream systemd recipe (from Yocto master) in our warrior branch.
PREFERRED_VERSION_systemd = "242%"
PREFERRED_VERSION_systemd-conf = "242%"

UBOOT_SUFFIX = "img"
UBOOT_ENTRYPOINT = "0xC2000040"

SERIAL_CONSOLES = "115200;ttySTM0"
SERIAL_CONSOLES_CHECK = "${SERIAL_CONSOLES}"

KERNEL_IMAGETYPE ?= "zImage"

# Do not update fstab file when using wic images
WIC_CREATE_EXTRA_ARGS ?= "--no-fstab-update"

# Image
IMAGE_FSTYPES += "tar.bz2 wic wic.gz wic.bmap"

WKS_FILE_DEPENDS ?= " \
    virtual/bootloader \
    e2fsprogs-native \
    bmap-tools-native \
"

# Wic default support
WKS_FILE ?= "stm32mp1.wks"
