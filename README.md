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

# Styles

All styles are in the `./styles` directory. 
You can set the `STYLE` variable in make for file name I.E
```
$ make build STYLE=default
```

Or you can use `STYLEFILE` for full path to file I.E
```
$ make build STYLEFILE=./styles/default.h
```

For more info about `Styling` read the `./doc/Styles.md` file.


# Compatibility

## Required To Make ( Can be uninstalled after )

[Git](https://git-scm.com/)

[GNU Make](https://www.gnu.org/software/make/) - Not on Windows Native

[GCC](https://gcc.gnu.org/)

BinUtils - Not on Windows Native - Usually preinstall on Linux

## Windows

[Cygwin](https://www.cygwin.com/) - Git

Native - Git

## Linux

[Ubuntu](https://ubuntu.com/) - Git

[Arch](https://archlinux.org/) - AUR or Git

Other - Git


# Install

Binary is placed in `/usr/bin/`

## Windows

```
> mkdir .\bin

> xcopy /S /I .\doc\ "C:\ProgramData\md"
> xcopy /S /-I .\face "C:\ProgramData\md\face"

> gcc .\src\*.c -o .\bin\md
```

output file in `.\bin\md.exe` move it to were ever you want

## Linux
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
