inherit populate_sdk_qt5

DISTRO_FEATURES_remove = "wayland"
DISTRO_FEATURES_append = " opengl"

IMAGE_INSTALL_append = " \
	packagegroup-qt5 \
	liberation-fonts \
"
