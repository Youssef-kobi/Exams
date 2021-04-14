#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i;
    int count;
    char *ptr;

    if(ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            av[1][i] == '>' ? ptr++ : ptr;
            av[1][i] == '<' ? ptr-- : ptr;
            av[1][i] == '+' ? (*ptr)++ : *ptr;
            av[1][i] == '-' ? (*ptr)-- : *ptr;
            if(av[1][i] == '.')
            {
                write(1,ptr,1);
            }
            i++;
            if(av[1][i] == '[' && !(*ptr))
            {
                count = 1;
                while(count)
                {
                    i++;
                    if(av[1][i] == '[')
                    {
                        count++;
                    }
                    if(av[1][i] == ']')
                    {
                        count--;
                    }
                }
            }
            if(av[1][i] == ']' && (*ptr))
            {
                count = 1;
                while(count)
                {
                    i--;
                    if(av[1][i] == '[')
                    {
                        count--;
                    }
                    if(av[1][i] == ']')
                    {
                        count++;
                    }
                }
            }
        }
    }
    else
    {
    write(1,"\n",1);
    }
    
    return(0);
}