pkgname="md"
pkgver="1.0.9"
pkgrel="1"
pkgdesc="Simple MarkDown Reader"

arch=("x86_64")

depends=("gcc" "make")
optdepends=()
conflicts=()

license=("MIT")

giturl="https://raw.githubusercontent.com/Noah-Arcouette/md/master/"

source=(
	"${giturl}src/colors.h" 
	"${giturl}src/main.c"
	"${giturl}src/main.h"
	"${giturl}src/printer.c"
	"${giturl}src/printer.h"
	"${giturl}src/reader.c"
	"${giturl}src/reader.h"
	"${giturl}src/settings.c"
	"${giturl}src/settings.h"
	"${giturl}makefile"
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
	"SKIP"
)

package() {
	mkdir -p "${pkgdir}/usr/bin"

	make mk 
	make build
	mv ./md "${pkgdir}/usr/bin/md"

	chown root:root "${pkgdir}/usr/bin/md"
	chmod a+x "${pkgdir}/usr/bin/md"


}
