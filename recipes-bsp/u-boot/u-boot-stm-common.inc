# Copyright (C) 2019 Koncepto
# Released under the MIT license (see COPYING.MIT for the terms)

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=30503fd321432fc713238f582193b78e"
DESCRIPTION = "U-Boot Mainline to test stm32mp1"

require recipes-bsp/u-boot/u-boot.inc

DEPENDS_append = " bison-native bc-native dtc-native"

PROVIDES += "u-boot"

SRC_URI = " \
	git://gitlab.denx.de/u-boot/u-boot.git;protocol=https \
	file://0001-stm32mp1-Disable-ADC.patch \
	file://0001-stm32mp1-Replace-ENV_IS_EXT4-to-MMC.patch \
	file://0002-stm32mp1-Enable-redundant-environment.patch \
"

S = "${WORKDIR}/git"

UBOOT_MAKE_TARGET_append = " u-boot-initial-env"

do_install_append () {
	install -d ${D}/${sysconfdir}
	install -m 644 ${B}/u-boot-initial-env ${D}/${sysconfdir}/u-boot-initial-env
}

do_deploy_append () {
	install -d ${DEPLOYDIR}
	install -m 644 ${B}/u-boot-initial-env ${DEPLOYDIR}/u-boot-initial-env
}

PACKAGES =+ "${PN}-initial-env"
FILES_${PN}-initial-env = "${sysconfdir}/u-boot-initial-env"
PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(stm*)"
