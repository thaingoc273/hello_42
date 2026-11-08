#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE		100
#define	NUMBER		'0'
#define	STACKSIZE	100
#define	ERROR		'E'

int		sp = 0;
double	val[BUFSIZE];
int		bufp = 0;
char	buf[BUFSIZE];

int		getop(char []);
void	push(double);
double	pop(void);
int		getch(void);
void	unget(char);

int		main(void)
{
	char	type;
	double	op2;
	char	s[BUFSIZE];

	while ((type = getop(s)) != EOF || type != ERROR)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error; division by zero");
				break;
			case '\n':
				printf("Value %.8g\n", pop());
				break;
			default:
				printf("Error: unknown operator");
				break;
		}
	}
	if (type == ERROR)
		printf("Error: error");
	return (0);
}

void	push(double f)
{
	if (sp < STACKSIZE)
		val[sp++] = f;
	else
		printf("Error: stack full, can't push %g\n", f);
}

double	pop(void)
{
	if (sp > 0)
		return (val[--sp]);
	else
	{
		printf("Error: stack empty \n");
		return (0.0);
	}
}

int		getch(void)
{
	if (bufp > 0)
		return (buf[--bufp]);
	else
		return (getchar());
}

void ungetch(char c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: the buffer is full\n");
	else
		buf[bufp++] = c;
}

int		check_operator(char c)
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return (0);
	return (1);
}

int getop(char s[])
{
	int			i;
	static char	buf = 0;
	char		c = ' ';

	i = 0;
	if (buf != 0)
	{
		c = buf;
		buf = 0;
	}
	if (c != ' ' && c!= '\t')
		return (ERROR);
	while ((c = getchar()) == ' ' || c == '\t')
		;
	s[0] = c;
	s[1] = '\0';
	if ((c < '0' || c > '9') && c != '.')
		return (c);
	i = 0;
	while (c >= '0' && c <= '9')
	{
		s[i++] = c;
		c = getchar();
	}
	if (c == '.')
	{
		s[i++] = '.';
		while ((c = getchar()) >= '0' && c <= '9')
			s[i++] = c;
	}
	s[i] = '\0';
	if (c != EOF)
		buf = c;
	return (NUMBER);
}
