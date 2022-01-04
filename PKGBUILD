pkgname="md"
pkgver="1.0.9"
pkgrel="1"
pkgdesc="Simple MarkDown Reader"

arch=("x86_64")

depends=("gcc")
optdepends=()
conflicts=()

license=("MIT")

source=(
	"./src/colors.h" 
	"./src/main.c"
	"./src/main.h"
	"./src/printer.c"
	"./src/printer.h"
	"./src/reader.c"
	"./src/reader.h"
	"./src/settings.c"
	"./src/settings.h"
)

sha512sums=("SKIP")

package() {
	mkdir -p "${pkgdir}/usr/bin"
	gcc "${srcdir}/src/*.c" -o "${pkgdir}/md"

	chown root:root "${pkgdir}/md"
	chmod a+x "${pkgdir}/md"

	
}
