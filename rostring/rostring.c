#include <unistd.h>
#include <stdio.h>
#include <limits.h>
int ft_isblank(char c)
{
  return (c == ' '||c == '\t' );
}

void rostring(char *s)
{
  int i = 0;
  int length_first_word = 0;
  while (s[i])
    {
      // skip white spaces
      while (ft_isblank(s[i]))
	      i++;
      //get length of first word
      if(s[i] && !ft_isblank(s[i]))
	    {
        if(length_first_word == 0)
          {
            while(s[i] && !ft_isblank(s[i++]))
            length_first_word++;
          }
        else
          {
            while (s[i] && !ft_isblank(s[i]))
                write(1, &s[i++], 1);
            write(1," ",1);
          }
	    }
    }
  i =0;
  while(ft_isblank(s[i]))
    i++;
  while(length_first_word--)
    write(1,&s[i++],1);
}

int main(int ac , char **av)
{
  printf("%d",INT_MIN);
  if(ac > 1 && av[1])
    rostring(av[1]);
  write(1,"\n",1);
  return 0;

}
