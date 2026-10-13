#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_put_repeated_string(char c, int n)
{
    int i;
    
    i = 1;
    while (i <= n)
    {
        write(1, &c, 1);
        i++;
    }
}

void    ft_print_begin_end_line(int x)
{
    if (x == 1)
    {
        ft_putchar('o');
    }
    else
    {
        ft_putchar('o');
        ft_put_repeated_string('-', x-2);
        ft_putchar('o');
    }
}

void ft_print_middle_line(int x)
{
    if (x==1)
    {
        ft_putchar('|');   
    }
    else
    {
        ft_putchar('|');
        ft_put_repeated_string(' ', x-2);
        ft_putchar('|');
    }
}

void ft_print_all_middle_line(int x, int y)
{
    if (y >=3)
    {
        int i;
        
        i = 1;
        while (i <= y-2)
        {
            ft_print_middle_line(x);
            ft_putchar('\n');
            i++;
        }
    }
}


void    rush(int x, int y)
{
    if (y == 1)
    {
        ft_print_begin_end_line(x);
    }
    else
    {
        ft_print_begin_end_line(x);
        ft_putchar('\n');
        ft_print_all_middle_line(x, y);
        ft_print_begin_end_line(x);
    }
}

int main()
{
    char *p;
    char str[2];
    
    str[0] = '0';
    str[1] = '0';
    str[2] = '\0';
    p = str;
    rush(0, 5);
    return (0);
    
}

