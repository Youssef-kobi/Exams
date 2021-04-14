#include<unistd.h>

int ft_isblank(char c)
{
    return (c== ' ' || c == '\t');
}

void  ft_rostring(char *s)
{
// hello word youssef
int i = 0;
int first_word=0;
while (s[i])
{
    while (ft_isblank(s[i]))
        i++;
    if (s[i] && first_word == 0)
    {
        while(s[i] && !ft_isblank(s[i++]))
            first_word++;
    }
    else
    {
        while(s[i] && !ft_isblank(s[i]))
            write(1,&s[i++],1);
        write(1," ",1);
    }    
}
    i = 0;
    while(ft_isblank(s[i]))
        i++;
    while (first_word--)
    {
        write(1,&s[i++],1);
    }
    
}

int main(int argc, char *argv[])
{
    if(argc >= 2)
        ft_rostring(argv[1]);
    return 0;
}
