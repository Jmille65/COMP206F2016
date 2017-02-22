//
// Must compile the library prior to this file.
// Compile command: gcc week10_ctypes_main.c -lweek10_ctypes_sample -L. -o week10_ctypes_main
//

#include "week10_ctypes_sample.h"
#include <stdio.h>

void main()
{
	char test[100] = "Hello world.";

	printf( "%s\n", test );

	modString(test);

	printf( "%s\n", test );

}
