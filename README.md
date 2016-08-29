# xv6 tutorial

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also http://pdos.csail.mit.edu/6.828/2012/v6.html, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (entryother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people have made contributions:
    Russ Cox (context switching, locking)
    Cliff Frey (MP)
    Xiao Yu (MP)
    Nickolai Zeldovich
    Austin Clements

In addition, we are grateful for the patches contributed by Greg
Price, Yandong Mao, and Hitoshi Mitake.

The code in the files that constitute xv6 is
Copyright 2006-2012 Frans Kaashoek, Robert Morris, and Russ Cox.

ERROR REPORTS

If you spot errors or have suggestions for improvement, please send
email to Frans Kaashoek and Robert Morris (kaashoek,rtm@csail.mit.edu). 

BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run "make".
On non-x86 or non-ELF machines (like OS X, even on x86), you will
need to install a cross-compiler gcc suite capable of producing x86 ELF
binaries.  See http://pdos.csail.mit.edu/6.828/2012/tools.html.
Then run "make TOOLPREFIX=i386-jos-elf-".

To run xv6, you can use the Bochs or QEMU PC simulators. Bochs makes
debugging easier, but QEMU is much faster. To run in Bochs, run "make
bochs" and then type "c" at the bochs prompt. To run in QEMU, run
"make qemu".

To create a typeset version of the code, run "make xv6.pdf".  This
requires the "mpage" utility.  See http://www.mesa.nl/pub/mpage/.


## resources
 * [class website] [CW]
 * [lab website] [LW]
 * [xv6 BOOK] [XB]   Important! Please Read!!!
 * [xv6 source code reference] [XS]
 * [Official xv6] [OX]
 * [GDB commands] [GC]
 * [start with xv6] [SWX]

---
## login sledge

open your terminal, type: 
```sh
$ ssh your_cs_account@server.cs.edu
$ password:*
```

Example

```sh
$ ssh user@server.cs.edu
```

---

## Tutorials

 * [run xv6 & using gdb] [XV6T]   9 min 

In the tutorial, instead of typing gdb, you should type:
```sh
$ gdb q -iex "set auto-load safe-path /home/csgrads/sjin010/xv6-public/"
```


to your working directory.   Find your working path, type 
```
$pwd
```
in the terminal.


 
 * [xv6 syscalls] [SYSC]   ---  more detail tutorial. (eg: how to create a user file, how syscall works.).
 
---
## Tips 

#### How to exit xv6.
 open another terminal, find the process PID of running QEMU
```sh
$ ps aux | less | grep uname
```
uname is your cs account. eg: sjin010

Then kill that process

```sh
$ kill -9 PID
```

---


 
[CW]: <http://www.cs.ucr.edu/~nael/cs153/>
[LW]: <http://www.cs.ucr.edu/~nael/cs153/labs/xv6.html>
[XB]: <https://pdos.csail.mit.edu/6.828/2014/xv6/book-rev8.pdf>
[XS]: <https://pdos.csail.mit.edu/6.828/2014/xv6/xv6-rev8.pdf>
[OX]: <https://pdos.csail.mit.edu/6.828/2014/xv6.html>
[GC]: <https://pdos.csail.mit.edu/6.828/2014/labguide.html>
[SWX]: <https://pdos.csail.mit.edu/6.828/2014/labs/lab1/>
[XV6T]: <https://www.youtube.com/watch?v=ktkAlbcoz7o> 
[SYSC]: <https://www.youtube.com/watch?v=vR6z2QGcoo8&feature=youtu.be>
[MDX]: <https://www.youtube.com/watch?v=2rAnCmXaOwo&ebc=ANyPxKpfkJea41eDHt0nTPlWIZnbD7ohhOUacMxlo09ixCvGQVdWiY7qguoMn951IXtTAcXi002enio4TN9TUx0iLC0STdhanw>
 
