#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	COL	13
#define	ROW 2 

void	print_array(int mul_arr[ROW][COL]);
int		day_of_year(int year, int month, int day);
void	month_day(int year, int year_day, int *month, int *day);


static int		daytab[ROW][COL] = {
							{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
							{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

int		main(void)
{
	int		month;
	int		day;

	print_array(daytab);
	printf("Day of year: %d\n", day_of_year(2000, 1, 15));
	month_day(2000, 46, &month, &day);
	printf("Month: %d\n", month);
	printf("Day: %d\n", day);
}

int		day_of_year(int year, int month, int day)
{
	int		leap;
	int		i;

	i = 0;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	while (++i <= month)
		day += daytab[leap][i];
	return (day);
}

void	month_day(int year, int year_day, int *month, int *day)
{
	int		leap;
	
	*month = 0;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	while (year_day > daytab[leap][*month])
		year_day -= daytab[leap][++(*month)];
	*day = year_day;
}

void	print_array(int mul_arr[ROW][COL])
{
	int		i;
	int		j;

	i = 0;
	while (i  < ROW)
	{
		j = 1;
		while (j  < COL)
		{
			printf("%d ", mul_arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
