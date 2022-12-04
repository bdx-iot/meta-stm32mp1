require linux-mainline-common.inc

LINUX_VERSION ?= "6.0.x"
KERNEL_VERSION_SANITY_SKIP="1"

BRANCH = "linux-6.0.y"

SRCREV = "${AUTOREV}"
SRC_URI = " \
    git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;branch=${BRANCH} \
    file://overlay.cfg \
"
