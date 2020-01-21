/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:32:30 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 21:11:36 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

char	***read_validate(char *file);
int		tetr_count(char *file);
int		map_validation(char *str);
int		tetr_validation(char *str, int *hash, int *con, int *empty);
char	**tetr_to_string(char *file, int count);

char	***map_create(int count, int size);
void	map_fill(char ***map, char **str);
void	map_cleanrow(char ***map);
void	map_cleancol(char ***map);
int		col_clean(char ***map, int blocks, int rows, int fill);

void	solution(char ***map);
int		blocks_count(char ***map);
char	**solve_create(int size);
int		backtracking(char **solve, char ***map, int vars);
int		insert_check(char **solve, char **map, int i, int j);

void	insert_row(char **solve, char **map, int i, int j);
void	clean_row(char **solve, char **map, int i, int j);
void	solve_output(char **solve);
int		**solve_free(char **solve);
void	map_free(char ***map);

char	error(void);

#endif
