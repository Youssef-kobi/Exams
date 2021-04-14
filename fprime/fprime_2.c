#include<stdlib.h>
#include<stdio.h>

void ft_prime(unsigned int nb)
{
  unsigned prime;
  if (nb == 1)
    printf("1");
  else
  {
    prime =2 ;
    while (nb > 1)
    {
      if( nb % prime == 0)
      {
        printf("%d",prime);
        nb /= prime;
        prime--;
        if(nb > 0)
          printf("*");
      }
      prime++;
    }
    
  }
}

int main(int ac ,char **av)
{
  if (ac == 2)
    ft_prime(atoi(av[1]));
  printf("\n");
  return 0;
}