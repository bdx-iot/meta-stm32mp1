inherit populate_sdk_qt5

DISTRO_FEATURES:remove = "wayland"
DISTRO_FEATURES:append = " opengl"

IMAGE_INSTALL:append = " \
	packagegroup-qt5 \
	liberation-fonts \
"
