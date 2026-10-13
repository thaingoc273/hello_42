/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>

void    ft_print_number(int n)
{
    int divi;
    int sign;
    char c;

    divi = 1;
    if (n < 0)
    {
        sign = -1;
        write(1, "-", 1);
        while (n / divi < - 10)
            divi *= 10;
        divi = - divi;
    }
    else
    {
        sign = 1;
        while ( n / divi > 10)
            divi *= 10;
    }
    while (divi * sign > 0)
        {
            c = n / divi + '0';
            write(1, &c, 1);
            n = n % divi;
            divi = divi / 10;
        }
}

int main()
{
    ft_print_number(-1217309721);
    return 0;
}
