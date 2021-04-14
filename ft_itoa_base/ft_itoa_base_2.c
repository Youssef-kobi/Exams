#include<stdio.h>
#include<stdlib.h>

char	*ft_itoa_base(int value, int base)
{
    char *s;
    int nb;
    int sign;
    int i;

    nb = (value< 0) ? (long) -value : value;
    sign = (value < 0 && base == 10) ? -1 : 0;
    i = sign == -1 ? 2 : 1;
    while(nb /= base >= 1)
        i++;
    s = malloc(sizeof(char ) * i + 1);
    s[i]= '\0';
    nb = (value< 0) ? (long) -value : value;
    while(i-- + sign)
    {
        s[i++]= (nb % base < 10) ? nb % base + '0' : nb % base + 'A' - 10;
        nb /= base ;
    }
    (i == 0) ? s[i]='-' : 0;
    return s;
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (1);
}