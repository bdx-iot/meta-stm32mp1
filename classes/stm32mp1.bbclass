# Use systemd as init system
VIRTUAL-RUNTIME_init_manager = "systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
VIRTUAL-RUNTIME_initscripts = ""
DISTRO_FEATURES:append = " systemd"

DISTRO_FEATURES:remove = " \
	wayland \
	irda \
	ppp \
	pcmcia \
	smbfs \
	pci \
	3g \
	nfc \
"

IMAGE_INSTALL:append = " \
	i2c-tools u-boot-env openssh-sftp-server \
"

IMAGE_FEATURES:append = " \
	ssh-server-dropbear \
"
