#include <stdio.h>

int ft_check_character(char c, char *base)
{
	int	i;
	
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int ft_check_duplicate(char *base, int i)
{
    int j;
    int k;

    j = 0;
    while (j < i - 1)
    {
        k = j + 1;
        while (k < i)
        {
            if (base[j] == base[k])
                return (1);
            k++;
        }
        j++;
    }
    return (0);
}

int ft_check_base(char *base)
{
    int i;

    i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
            return (0);
        if (base[i] < '0' || base[i] > 'z')
            return (0);
        if (base[i] > '9' && base[i] < 'A')
            return (0);
        if (base[i] > 'Z' && base[i] < 'a')
            return (0);
        i++;
    }
    if (i < 2)
        return (0);
    if (ft_check_duplicate(base, i))
        return (0);
    return (i);
}

int ft_atoi_base(char *str, char *base)
{
    int i;
    int sgn;
    int val;

    i = 0;
    sgn = 1;
    val = 0;
	if (!ft_check_base(base))
		return (0);
    while (str[i] == ' ')
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sgn = -sgn;
        i++;
    }
    while (ft_check_character(str[i], base) != -1)
    {
        val = val * ft_check_base(base) + ft_check_character(str[i], base);
        i++;
    }
    return (val * sgn);
}

int main(void)
{
    char    *str;
    char    *str1;
    char    *str2;
    char    *str3;
	char	*base;

    str = " ---+--+1234ab567";
    str1 = "a";
    str2 = "a---+--+1234ab567";
    str3 = "---+--+a1234ab567";
    base = "0123456789a";
	printf("Extracted value: %d\n", ft_atoi_base(str, base));
    printf("Extracted value: %d\n", ft_atoi_base(str1, base));
    printf("Extracted value: %d\n", ft_atoi_base(str2, base));
    printf("Extracted value: %d\n", ft_atoi_base(str3, base));
}
