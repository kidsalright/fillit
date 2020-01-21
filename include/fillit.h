/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:32:30 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 21:21:07 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

char	***read_validate(char *file);
int		tetr_count(char *file);
int		tetr_validation(char *str);
int		blocks_validation(char *str, int *hash, int *con, int *empty);
char	**tetr_to_string(char *file, int count);

char	***tetr_create(int count, int size);
void	tetr_fill(char ***tetr, char **str);
void	tetr_cleanrow(char ***tetr);
void	tetr_cleancol(char ***tetr);
int		col_clean(char ***tetr, int blocks, int rows, int fill);

void	solution(char ***tetr);
int		blocks_count(char ***tetr);
char	**solve_create(int size);
int		backtracking(char **solve, char ***tetr, int vars);
int		insert_check(char **solve, char **tetr, int i, int j);

void	insert_row(char **solve, char **tetr, int i, int j);
void	clean_row(char **solve, char **tetr, int i, int j);
void	solve_output(char **solve);
int		**solve_free(char **solve);
void	tetr_free(char ***tetr);

char	error(void);

#endif
