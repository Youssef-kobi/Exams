#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_op(char c)
{
	return c == '+' || c == '*' || c == '-' || c == '/' || c == '%';
}

int		ft_digit(char c)
{
	return c >= '0' && c <= '9';
}

int		ft_space(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

int ft_valide(char *s)
{
	while (*s)
	{
		if(!ft_digit(*s) && !ft_space(*s) && !ft_op(*s))
			return 0;
		s++;
	}
	return 1;
}

int ft_calc(int *stack ,int i ,char op)
{
	int a = stack[i - 1];
	int b = stack[i];

	if( i < 1 || ((op == '/' || op == '%') && !b))
		return 0;
	switch (op)
	{
	case '*':
		stack[i - 1] = a *b;
		break;
	case '/':
		stack[i - 1] = a  / b;
		break;
	case '-':
		stack[i - 1] = a -b;
		break;
	case '+':
		stack[i - 1] = a + b;
		break;
	case '%':
		stack[i - 1] = a % b;
		break;
	}
	stack[i]=0;
	return 1;
}

int rpn_calc(char *s)
{
	int stack[1024] = {0};
	int i = -1;
	if(!ft_valide(s))
		return 0;
	while(*s)
	{
		if (ft_digit(*s) || (ft_op(*s) && ft_digit(*(s + 1))))
		{
			stack[++i]=atoi(s);
			if (ft_op(*s))
				s++;
			while(ft_digit(*s))
				s++;
		}
		else if (ft_op(*s) && !ft_calc(stack , i--,*s))
			return 0;
		s++;
	}
	if(i)
		return 0;
	printf("%d", stack[0]);
	return 1;
}

int main(int ac, char **av)
{
	if(ac !=2 || !rpn_calc(av[1]))
		printf("Error\n");
	return 0;
}