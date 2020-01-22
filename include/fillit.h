/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:32:30 by yberries          #+#    #+#             */
/*   Updated: 2020/01/22 17:02:40 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

char	error(void);
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
int		get_size(int sqr);
int		blocks_count(char ***tetr);
char	**solve_create(int size);
int		backtracking(char **solve, char ***tetr, int blocks);
int		insert_check(char **solve, char **tetr, int r, int f);
void	insert_row(char **solve, char **tetr, int r, int f);
void	clean_row(char **solve, char **tetr, int r, int f);
void	solve_output(char **solve);
int		**solve_free(char **solve);
void	tetr_free(char ***tetr);

#endif
