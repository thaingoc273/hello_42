#include <stdlib.h>
#include "rush02.h"
#include <stdio.h>

int	main(void)
{
	t_dict	entry;
	
	entry.key = "10";
	entry.value = "ten";
	printf("Check header file %s", entry.value);
}
