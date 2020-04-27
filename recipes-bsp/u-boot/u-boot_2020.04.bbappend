FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_stm32mp1 = " \
	file://0001-stm32mp1-Disable-ADC.patch \
	file://0002-stm32mp1-Replace-ENV_IS_EXT4-to-MMC.patch \
"

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
