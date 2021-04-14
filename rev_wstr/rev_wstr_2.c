#include<unistd.h>
int len(char *s)
{
  int i = 0;
  while (s[i])
    i++;
  return(i);
}

int ft_isblank(char c)
{
  return (c == ' ' || c == '\t');
}

void rev_wstr(char *s)
{
  int start;
  int end;
  int i;

  start = len(s) - 1;
  end = start;
// hello word youssef
//           ^start
  while (start >= 0)
  {
    end = start;
    while(start>=0 && !ft_isblank(s[start]))
       start--;
    start++;
    i = start;
    while (i <= end)
      write(1,&s[i++],1);
    if(start > 0)
      write(1," ",1);
    start -=2;
  }
  

}

int main(int ac , char **av)
{
  if(ac == 2 )
    rev_wstr(av[1]);
  
}