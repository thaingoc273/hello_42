#include <stdio.h>

/* In c, when we write 0 at the begining of number, 
it is meant the number is in octal system */

int		main(void)
{
	int		n = 255;

	printf("Masking with 7 bits: %d\n", (n & 0177));
	printf("The max integer %d\n", (~0u >> 1));
	printf("The min integer %d\n", (1u << 31));
}
