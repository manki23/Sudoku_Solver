/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:37:37 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/16 14:37:52 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_check.h"

void	fill(int *tab, int size, int value)
{
	int i;

	i = -1;
	while (++i < size)
		tab[i] = value;
}

t_bool	is_grid_valid(int **grid)
{
	int i;

	i = -1;
	while (++i < BOX_SIZE)
		if (!is_row_valid(i, grid))
			return (0);
	i = -1;
	while (++i < BOX_SIZE)
		if (!is_column_valid(i, grid))
			return (0);
	i = -1;
	while (++i < BOX_SIZE)
		if (!is_box_valid(i, grid))
			return (0);
	return (1);
}

t_bool	is_row_valid(int row, int **grid)
{
	int col;
	int *numbers;
	int valid;

	valid = 1;
	numbers = malloc(sizeof(int) * BOX_SIZE);
	fill(numbers, BOX_SIZE, 0);
	col = -1;
	while (++col < BOX_SIZE)
	{
		if (grid[row][col] != 0)
		{
			if (numbers[grid[row][col] - 1])
			{
				valid = 0;
				break ;
			}
			else
				numbers[grid[row][col] - 1] = 1;
		}
	}
	free(numbers);
	return (valid);
}

t_bool	is_column_valid(int col, int **grid)
{
	int row;
	int *numbers;
	int valid;

	valid = 1;
	numbers = malloc(sizeof(int) * BOX_SIZE);
	fill(numbers, BOX_SIZE, 0);
	row = -1;
	while (++row < BOX_SIZE)
	{
		if (grid[row][col] != 0)
		{
			if (numbers[grid[row][col] - 1])
			{
				valid = 0;
				break ;
			}
			else
				numbers[grid[row][col] - 1] = 1;
		}
	}
	free(numbers);
	return (valid);
}

t_bool	is_box_valid(int box, int **grid)
{
	t_coords	max;
	t_coords	coords;
	int			*numbers;

	fill((numbers = malloc(sizeof(int) * BOX_SIZE)), BOX_SIZE, 0);
	max.y = (box / SIZE) * SIZE + SIZE - 1;
	max.x = (box % SIZE) * SIZE + SIZE - 1;
	coords.y = max.y - SIZE;
	while (++coords.y <= max.y)
	{
		coords.x = max.x - SIZE;
		while (++coords.x <= max.x)
			if (grid[coords.y][coords.x] != 0)
			{
				if (numbers[grid[coords.y][coords.x] - 1])
				{
					free(numbers);
					return (0);
				}
				else
					numbers[grid[coords.y][coords.x] - 1] = 1;
			}
	}
	free(numbers);
	return (1);
}
