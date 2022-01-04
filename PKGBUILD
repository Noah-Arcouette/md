pkgname="md"
pkgver="1.0.9"
pkgrel="1"
pkgdesc="Simple MarkDown Reader"

arch=("x86_64")

depends=("gcc")
optdepends=()
conflicts=()

license=("MIT")

giturl="https://raw.githubusercontent.com/Noah-Arcouette/md/master/src/"

source=(
	"${giturl}colors.h" 
	"${giturl}main.c"
	"${giturl}main.h"
	"${giturl}printer.c"
	"${giturl}printer.h"
	"${giturl}reader.c"
	"${giturl}reader.h"
	"${giturl}settings.c"
	"${giturl}settings.h"
)

sha256sums=(
	"SKIP"
	"SKIP"
	"SKIP"
	"SKIP"
	"SKIP"
	"SKIP"
	"SKIP"
	"SKIP"
	"SKIP"
)

package() {
	mkdir -p "${pkgdir}/usr/bin"
	gcc "${srcdir}/*.c" -o "${pkgdir}/md"

	chown root:root "${pkgdir}/md"
	chmod a+x "${pkgdir}/md"


}
