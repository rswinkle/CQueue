CQUEUE
======
[![Contact me on Codementor](https://cdn.codementor.io/badges/contact_me_github.svg)](https://www.codementor.io/rswinkle)

This is a C89 queue library with specific support for ints, doubles, and strings
and a generic structure that supports all other types.  It is modeled after
my CVector library so see that for more info about the different types and
design notes.

The queues are circular like a ring buffer but can be extended 2 ways.  Using
the pushe functions instead of plain push will realloc if the queue is full
rather than doing nothing and returning 0 and calling the resize functions
with size >= the current length of the queue will of course realloc to that
size, moving data as necessary.


Building
========
I use premake so the command on linux is premake4 gmake which
will generate a build directory.  cd into that and run make
or make config=release.  I have not tried it on windows though
it should work (well I'm not sure about CUnit ...).

There is no compiler output of any kind, no errors or warnings.

It has been relatively well tested using Cunit tests which all pass.
I've also run it under valgrind and there are no memory leaks.


Usage
=====
To actually use the library just copy the appropriate c/h file pair(s) to your project
or just use cqueue.h.
To get a good idea of how to use the library and see it in action and how it should
behave, look at queue_tests.c


LICENSE
=======
CQueue is licensed under the MIT License. See LICENSE.


