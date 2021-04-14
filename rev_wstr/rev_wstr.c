#include <unistd.h>
#include <stdio.h>

int ft_length(char *s)
{
  int length= 0;
  int i= 0;
  while(s[i++])
    length++;
  printf("%d",length);
  return length;
}

int ft_isblank(char c)
{
  return (c == ' ' || c == '\t');
}

void rev_wstr(char *s)
{

  // hello word youssef
  int start;
  // end aobut
  int end;
  int i;

  start = ft_length(s) - 1;
  end = start;
  i = start;

  while (start >= 0)
    {
      end = start;
      i = start;
      while(start>=0 && !ft_isblank(s[start]))
	      start--;
      start++;
      i = start;
      while (i <= end)
	      write(1,&s[i++],1);
      if(start > 0)
	      write(1," ",1);
      start -= 2;
    }
}

int main(int ac , char **av)
{
  if (ac == 2)
    rev_wstr(av[1]);
  write(1,"\n",1);
  return 0;
}
