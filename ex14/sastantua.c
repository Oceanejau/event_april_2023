#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		recurspace(int h)
{
	int x;

	x = 6;
	if (h == 1)
		return (6);
	if (h <= 0)
		return (0);
	while (--h)
	{
		if (h % 2)
			x = x + 1;
		else
			x = x + 2;
	}
	return (x + recurspace(h - 1));
}

int		calcspace(int h)
{
	int x;
	int y;

	x = 2;
	y = 0;
	while (y < h)
	{
		x = x + recurspace(h - y);
		y++;
	}
	return (x);
}

void	etoiles(int ftier[9], int size)
{
	ft_putchar('/');
	while (++ftier[8] < ftier[3])
	{
		if (ftier[2] == size - 1 && size + 3 - ftier[0] <= size + size % 2 &&
				ftier[8] < ftier[3] / 2 + ftier[3] % 2 +
				size % 2 + size / 2 - 1 &&
				ftier[8] > ftier[3] / 2 - ftier[3] % 2 -
				size % 2 - size / 2 + 1)
		{
			if (size > 4 && ftier[0] == size - size / 2 + (size % 2 ? 1 : 2) &&
					ftier[8] == ftier[3] / 2 + size / 2 - (size % 2 ? 1 : 2))
			{
				ft_putchar('$');
			}
			else
				ft_putchar('|');
		}
		else
			ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int		ftier[9];//tableau dimention 9

	ftier[2] = -1;//etages
	ftier[3] = 1;//etoiles
	ftier[1] = calcspace(size - 1);//nb d'espaces a print
	while (++ftier[2] < size)
	{
		ftier[0] = 0;//une ligne dans un etage
		while (ftier[0] != ftier[2] + 3)
		{
			ftier[1]--;
			ftier[8] = -1;//ompteur espace
			while (++ftier[8] <= ftier[1])
				ft_putchar(' ');
			ftier[8] = -1;
			etoiles(ftier, size);
			ftier[0]++;
			ftier[3] = ftier[3] + 2;
		}
		ftier[3] = ftier[3] + ftier[2] - ftier[2] % 2 + 4;
		ftier[1] = ftier[1] - ftier[2] / 2 - 2;
	}
}

int main(int ac, char **av)
{
	int	size;
	int	x;

	x = 0;
	if (ac != 2)
	{
		printf("Try again with this format:\n./sastantua size\n");
		return (-1);
	}
	while (av[1][x] != '\0')
	{
		if (av[1][x] < '0' || av[1][x] > '9')
		{
			printf("Only numbers accepted\n");
			return (-1);
		}
		x++;
	}
	size = atoi(av[1]);
	if (size == 0)
	{
		printf("Minimum size value must be 1, max is intmax\n");
		return (-1);
	}
	sastantua(size);
	return (0);
}

