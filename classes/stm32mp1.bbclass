# Use systemd as init system
VIRTUAL-RUNTIME_init_manager = "systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
VIRTUAL-RUNTIME_initscripts = ""
DISTRO_FEATURES_append = " systemd"

DISTRO_FEATURES_remove = " \
	wayland \
	irda \
	ppp \
	pcmcia \
	smbfs \
	pci \
	3g \
	nfc \
"

IMAGE_INSTALL_append = " \
	i2c-tools u-boot-env openssh-sftp-server \
"

IMAGE_FEATURES_append = " \
	ssh-server-dropbear \
"
