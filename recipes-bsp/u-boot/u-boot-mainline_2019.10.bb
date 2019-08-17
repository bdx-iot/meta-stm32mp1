require recipes-bsp/u-boot/u-boot.inc
require u-boot-stm-common.inc

DESCRIPTION = "U-Boot Mainline to test stm32mp1"

DEPENDS_append = " bc-native dtc-native"

PROVIDES += "u-boot"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(stm*)"
