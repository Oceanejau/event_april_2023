#include <stdio.h>

int	main(int ac, char **av)
{
	int	size;
	int	tmp;
	int	x;
	int	y;
	int	pos;

	y = 1;
	if (ac < 2)
		return (-1);
	while (y < ac)
	{
		x = 0;
		size = 0;
		tmp = 0;
		while (av[y][x])
		{
			if (av[y][x] == ' ')
				tmp = 0;
			else
				tmp++;
			if (size < tmp)
				size = tmp;
			x++;
		}
		x = 0;
		if (size > 0)
		{
			while (x < size + 4)
			{
				printf("*");
				x++;
			}
			printf("\n");
			x = 0;
			while (av[y][x] == ' ')
				x++;
			pos = x;
			tmp = -1 ;
				while (av[y][x] != '\0')
			{
				if (av[y][x] == ' ')
				{
				printf("* ");
				while (pos != x)
				{
					printf("%c", av[y][pos]);
					pos++;
				}
				while (tmp < size)
				{
					printf(" ");
					tmp++;
				}
				printf("*\n");
				tmp = -1;
				while (av[y][x] == ' ' && av[y][x + 1] == ' ')
					x++;
				pos = x + 1;
			}
			else
				tmp++;
			x++;
			}
			if (tmp != -1)
			{
				printf("* ");
				while (pos != x)
				{
					printf("%c", av[y][pos]);
					pos++;
				}
				while (tmp < size)
				{
					printf(" ");
					tmp++;
				}
				printf("*\n");
				tmp = -1;
				while (av[y][x] == ' ' && av[y][x + 1] == ' ')
					x++;
				pos = x + 1;
			}
			x = 0;
			while (x < size + 4)
			{
				printf("*");
				x++;
			}
			printf("\n");
		}
		y++;
	}
	return (0);
}
