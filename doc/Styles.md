***FG_ANSI for foreground and BG_ANSI for background***
***Use bash 256 [color codes](https://raw.githubusercontent.com/seedform/color256/master/20160221144140.png)***

***You can also use FG_RGB and BG_RGB with hex color values***

***Use an empty string for no change in color***


# ERROR_C

Color of error messages


# DEF_C

Default text color


# B_C

Default background color


# H1_C - H3_C

Header 1-3 colors


# HU

Header Underline define for true / don't define for false


# CLC_C

Checked checklist color I.E ` - [x] list`
                                 ^

# CLU_C

Uncheck checklist color I.E ` - [x] list`
                                ^ ^

# UL_C and List Color

Underline color I.E
```
underline
=========
```

List color I.E
```
- list
> list
```


# HLB_C

Highlight background color


# HL_C

Highlight text color


# I

Italicize on define for true / don't define for false
```
*italicize*
***italicize***
```


# Basic Syntax Highlighting
## OP_C

Operator color
Operators: `*+-/$#;:?=><!&|^~%`


## INT_C

Integer color
Integers: `0123456789_.,\`

## PAR_C

Parentheses color
Parentheses: `{}[]()`

## STR_C

String color
Strings: `""''`


# ADVO

MD uses libadvo with vars
if you don't want to install ADVO comment out `ADVO`

## TEXTC
***Warning making color bold will make the entire line bold***

Box text color 
use libadvo docs for color definition info

## BOXC
***Warning making color bold will make the entire line bold***

Box border color 
use libadvo docs for color definition info

## BOX_TYPE_CIR
## BOX_TYPE_SBOX
## BOX_TYPE_BOX

Define one or none of these to define the box shape


# NAME

Style name

# BY

Style author
