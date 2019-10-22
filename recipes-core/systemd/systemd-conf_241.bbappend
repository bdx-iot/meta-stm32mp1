FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " \
	file://eth.network \
"

do_install_append_stm32mp1() {
	install -Dm 0644 ${WORKDIR}/eth.network ${D}${sysconfdir}/systemd/network/eth.network
}
