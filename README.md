# MD

MD is a MakeDown file reader with:
- [x] Header styles
- [x] List support
- [x] check list support
- [x] under lines ( `========` )
- [x] highlighting support I.E
```
	*Hello, world!*
	`Hello, world!`
	***Hello, world!***
```
- [x] Basic Syntax Highlighting I.E highlight scripts in code highlights
***Warning Syntax highlighter doesn't know what comments are so don't type apostrophes in comments ( They can be escaped in strings )***


# Exp

![Wolf-Top](/images/wolf-top.png)

![Wolf-Bottom](/images/wolf-bottom.png)

# Styles

All styles are in the `./styles` directory.
You can set the `STYLE` variable in make for file name I.E
```
$ sudo make install STYLE=default
```

Or you can use `STYLEFILE` for full path to file I.E
```
$ sudo make install STYLEFILE=./styles/default.h
```

For more info about `Styling` read the `./doc/Styles.md` file.


# Required

[Git](https://git-scm.com/)

[GNU Make](https://www.gnu.org/software/make/)

[GCC](https://gcc.gnu.org/)

BinUtils - Usually preinstall on Linux

[LibAdvo](https://github.com/Noah-Arcouette/advo
)
***Optional***
To remove ADVO comment out `#define ADVO` and `#include <advo.h>` in selected style, or use `style`-noadvo.h instead


# Install

## With shell script
```
$ ./install.sh
```

## From make
```
$ sudo make install
```

## AUR

[MD](https://aur.archlinux.org/packages/md-git/) also is in the AUR at https://aur.archlinux.org/packages/md-git/

I would recommend using [trizen](https://github.com/trizen/trizen) to download

## Compile and Not Install
```
$ make mk

$ make build
```

## Uninstall

```
$ sudo make uninstall
```

# Tests

Test that the command is installed with

```
$ md -f
```

It should display something that looks like a face.


Test if application works

```
$ md -h
```

Should display the help message.


# See Also

## Styles

doxy, and desert are taken from https://github.com/googlearchive/code-prettify

default, moon, and tty-support made by [me](https://github.com/Noah-Arcouette/)


## Face

The face is of former president of the USA [Donald John Trump](https://www.donaldjtrump.com/)
