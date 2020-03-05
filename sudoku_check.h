/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_check.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:38:01 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/16 14:38:03 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_CHECK_H
# define SUDOKU_CHECK_H

# include <stdlib.h>
# include "sudoku.h"

void	fill(int *tab, int size, int value);
t_bool	is_grid_valid(int **grid);
t_bool	is_row_valid(int row, int **grid);
t_bool	is_column_valid(int col, int **grid);
t_bool	is_box_valid(int box, int **grid);

#endif
