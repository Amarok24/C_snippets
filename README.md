# c_snippets
My C snippet collection. Most of it is old-school code (C89/C90, C99), so it should be fairly well portable to most systems, even old computers.

## Compilation of source code with GCC

If you run into troubles when compiling, you might want to tell the GNU C Compiler (GCC) what C standard to use for compilation; here are two very basic examples:

```sh
gcc -std=c90 somefile.c -o outputexecutable
gcc -std=c99 somefile.c -o outputexecutable
```

If the math library is used (if you see `#include <math.h>` somewhere on top of the C source), you have to explicitly tell GCC to link the math library (this has historical reasons which I don't understand). Simply put `-lm` (link math) at the end of the compile line:

```sh
gcc -std=c99 somefile.c -o outputexecutable -lm
```

To reduce file size of the executable use the `-s` flag (remove all symbol table information).
