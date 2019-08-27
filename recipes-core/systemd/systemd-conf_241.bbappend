FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRCREV_stm32mp1 = "511646b8ac5c82f210b16920044465756913d238"

SRC_URI_append = " \
	file://eth.network \
"

do_install_append_stm32mp1() {
	install -Dm 0644 ${WORKDIR}/eth.network ${D}${sysconfdir}/systemd/network/eth.network
}
