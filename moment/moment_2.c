#include<stdlib.h>
#include<stdio.h>

char    *moment(unsigned int duration)
{
    char *r = malloc(sizeof(char)* 4096)
    if(duration)
}

int main(int ac, char **av)
{
    if(ac == 2)
        printf("%s",moment(atoi(av[1])));
    return 0;
}
