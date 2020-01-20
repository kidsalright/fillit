/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:32:30 by yberries          #+#    #+#             */
/*   Updated: 2020/01/20 22:31:00 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>

char	***read_validate(char *file);
int		tetr_count(char *file);
int		map_validation(char *str);
int		blocks_validation(char *str, int *hash, int *con, int *empty);
char	**tetr_to_string(char *file, int count);
char	***map_create(int count, int size, char c);
void	map_fill(char ***map, char **str);
void	map_cleanrow(char ***map);
void	map_cleancol(char ***map);
char	error(void);

#endif
