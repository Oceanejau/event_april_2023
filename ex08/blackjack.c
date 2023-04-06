#include <stdio.h>

int main(int ac, char **av)
{
	int	res;
	int	x;

	x = 0;
	res = 0;
	if (ac != 2)
		return (-1);
	while (av[1][x] != '\0')
	{
		if (av[1][x] >= '2' && av[1][x] <= '9')
			res = (av[1][x] - 48 )+ res;
		else if (av[1][x] == 'T' || av[1][x] == 'J' || av[1][x] == 'D' || av[1][x] == 'K')
			res = res + 10;
		else if (av[1][x] == 'A')
		{
			if (res > 21)
				res++;
			else
				res+=11;
		}
		else
		{
			printf("%c: this character is not accepted\n", av[1][x]);
			return (-1);
		}
		x++;
	}
	if (res > 21)
	{
		x = 0;
		while (av[1][x] != '\0' && res > 21)
		{
			if (av[1][x] == 'A')
				res-=10;
			x++;
		}
	}
	if (res == 21)
		printf("Blackjack!\n");
	else
		printf("%d\n", res);
	return (0);
}
