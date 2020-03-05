/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:57:35 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/15 15:57:36 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sudoku.h"
#include "sudoku_check.h"
#include "ft_string.h"

void	display(int **grid)
{
	t_coords c;

	c.y = 0;
	while (c.y < BOX_SIZE)
	{
		c.x = 0;
		while (c.x < BOX_SIZE)
		{
			ft_putchar('0' + grid[c.y][c.x]);
			if (c.x != BOX_SIZE - 1)
				ft_putchar(' ');
			c.x++;
		}
		ft_putchar('\n');
		c.y++;
	}
}

int		**create_grid(char **sudoku)
{
	int			**grid;
	t_coords	c;
	int			number;

	c.y = -1;
	grid = malloc(sizeof(int *) * BOX_SIZE);
	while (++c.y < BOX_SIZE && grid)
	{
		if (ft_strlen(sudoku[c.y]) != BOX_SIZE)
			return (0);
		if ((grid[c.y] = malloc(sizeof(int) * BOX_SIZE)) == 0)
			return (0);
		c.x = -1;
		while (++c.x < BOX_SIZE)
		{
			if (sudoku[c.y][c.x] > '0' && sudoku[c.y][c.x] <= '9')
				number = sudoku[c.y][c.x] - '0';
			else if (sudoku[c.y][c.x] == '.')
				number = 0;
			else
				return (0);
			grid[c.y][c.x] = number;
		}
	}
	return (grid);
}

int		equals(int **grid, int **grid2)
{
	t_coords c;

	c.y = 0;
	while (c.y < BOX_SIZE)
	{
		c.x = 0;
		while (c.x < BOX_SIZE)
		{
			if (grid[c.y][c.x] != grid2[c.y][c.x])
				return (0);
			c.x++;
		}
		c.y++;
	}
	return (1);
}

int		error(void)
{
	ft_putstr("Error\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		**grid;
	int		**grid2;
	int		resolved;

	argc--;
	argv++;
	if (argc != 9)
		return (error());
	grid = create_grid(argv);
	grid2 = create_grid(argv);
	if (grid == 0 || grid2 == 0 || !is_grid_valid(grid))
		return (error());
	resolved = resolve(0, grid);
	if (!resolved)
		return (error());
	resolve_reverse(BOX_SIZE * BOX_SIZE - 1, grid2);
	if (!equals(grid, grid2))
		return (error());
	display(grid);
	return (0);
}
