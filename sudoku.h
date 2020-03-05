/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:58:22 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/15 15:58:24 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# define SIZE 3
# define BOX_SIZE SIZE * SIZE

typedef int		t_bool;
typedef struct	s_coords {
	int x;
	int y;
}				t_coords;
t_bool			is_in_row(int number, int row, int **grid);
t_bool			is_in_column(int number, int col, int **grid);
t_bool			is_in_box(int number, int row, int col, int **grid);
t_bool			resolve(int pos, int **grid);
t_bool			resolve_reverse(int pos, int **grid);

#endif
