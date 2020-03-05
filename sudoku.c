/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:57:48 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/15 15:57:49 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

t_bool	is_in_row(int number, int row, int **grid)
{
	int col;

	col = -1;
	while (++col < BOX_SIZE)
		if (grid[row][col] == number)
			return (1);
	return (0);
}

t_bool	is_in_column(int number, int col, int **grid)
{
	int row;

	row = -1;
	while (++row < BOX_SIZE)
		if (grid[row][col] == number)
			return (1);
	return (0);
}

t_bool	is_in_box(int number, int row, int col, int **grid)
{
	int y;
	int x;

	y = row - (row % SIZE) + SIZE - 1;
	x = col - (col % SIZE) + SIZE - 1;
	row = y - SIZE + 1;
	while (row <= y)
	{
		col = x - SIZE + 1;
		while (col <= x)
		{
			if (grid[row][col] == number)
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

t_bool	resolve(int pos, int **grid)
{
	int row;
	int col;
	int number;

	col = pos % (BOX_SIZE);
	row = pos / (BOX_SIZE);
	if (pos == BOX_SIZE * BOX_SIZE)
		return (1);
	if (grid[row][col] != 0)
		return (resolve(pos + 1, grid));
	number = 1;
	while (number <= BOX_SIZE)
	{
		if (!is_in_row(number, row, grid) &&
			!is_in_column(number, col, grid) &&
			!is_in_box(number, row, col, grid))
		{
			grid[row][col] = number;
			if (resolve(pos + 1, grid))
				return (1);
		}
		number++;
	}
	grid[row][col] = 0;
	return (0);
}

t_bool	resolve_reverse(int pos, int **grid)
{
	int row;
	int col;
	int number;

	col = pos % (BOX_SIZE);
	row = pos / (BOX_SIZE);
	if (pos == -1)
		return (1);
	if (grid[row][col] != 0)
		return (resolve_reverse(pos - 1, grid));
	number = BOX_SIZE;
	while (number > 0)
	{
		if (!is_in_row(number, row, grid) &&
			!is_in_column(number, col, grid) &&
			!is_in_box(number, row, col, grid))
		{
			grid[row][col] = number;
			if (resolve_reverse(pos - 1, grid))
				return (1);
		}
		number--;
	}
	grid[row][col] = 0;
	return (0);
}
