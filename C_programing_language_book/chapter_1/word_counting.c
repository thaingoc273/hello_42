#include <stdio.h>

#define IN	1
#define OUT	0

int		main(void)
{
	int		c;
	int		count_line;
	int		count_word;
	int		count_character;
	int		state;

	count_line = 0;
	count_word = 0;
	count_character = 0;
	state = OUT;

	while ((c = getchar()) != EOF)
	{
		++count_character;
		if (c == '\n')
			++count_line;
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			++count_word;
		}
	}
	printf("Number lines: %d \nNumber words: %d\nNumber character: %d\n", count_line, count_word, count_character);
}
