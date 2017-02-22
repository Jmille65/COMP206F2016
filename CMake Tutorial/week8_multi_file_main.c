#include <stdio.h>
//#include "week8_multi_file_swap.h"

extern void swap( int*, int *);

void main()
{
	int a = 5;
	int b = 6;
	swap( &a, &b );

	printf( "a is %d\nb is %d\n", a, b );

}
