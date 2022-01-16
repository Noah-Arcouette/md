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
- [ ] basic HTML support

- [ ] Style creator

- [x] Linux support
- [x] Cygwin support


# Compatibility

## Required To Make ( Can be uninstalled after )

[Git](https://git-scm.com/)

[GNU Make](https://www.gnu.org/software/make/) - Not for Windows Native

[GCC](https://gcc.gnu.org/)

## Windows

[Cygwin](https://www.cygwin.com/) - Git

Native - Git

## Linux

[Ubuntu](https://ubuntu.com/) - Git

[Arch](https://archlinux.org/) - AUR or Git

Other - Git


# Install

***I suggest using `strip -s` on it ( not needed if downloading from the AUR )***

***Strip with `sudo strip -s /usr/bin/md` after installation***

Binary is placed in `/usr/bin/`

## Cygwin
```
$ make mk

$ make cyg
```

## Windows

```
> xcopy /S /I .\doc\ "C:\ProgramData\md"
> xcopy /S /-I .\face "C:\ProgramData\md\face"

> gcc .\src\*.c -o .\bin\md
```

output file in `.\bin\md.exe` move it to were ever you want

## Linux
```
$ make mk

$ make linux
```

## AUR

[MD](https://aur.archlinux.org/packages/md-git/) also is in the AUR at https://aur.archlinux.org/packages/md-git/

I would recommend using [trizen](https://github.com/trizen/trizen) to download

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
