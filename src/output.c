/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:30:53 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 21:18:35 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetr_free(char ***tetr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetr[i])
	{
		while (tetr[i][j])
		{
			free(tetr[i][j]);
			++j;
		}
		j = 0;
		free(tetr[i]);
		++i;
	}
	free(tetr);
}

int		**solve_free(char **solve)
{
	int i;

	i = 0;
	while (solve[i])
	{
		free(solve[i]);
		++i;
	}
	free(solve);
	solve = NULL;
	return (0);
}

void	solve_output(char **solve)
{
	int	i;

	i = 0;
	while (solve[i])
	{
		ft_putendl(solve[i]);
		++i;
	}
}

char	**solve_create(int size)
{
	int		rows;
	int		fill;
	char	**solve;

	rows = 0;
	fill = 0;
	solve = (char**)malloc(sizeof(char*) * (size + 1));
	while (rows < size)
	{
		solve[rows] = (char*)malloc(sizeof(char) * (size + 1));
		while (fill < size)
			solve[rows][fill++] = '.';
		solve[rows][fill] = 0;
		fill = 0;
		++rows;
	}
	solve[rows] = NULL;
	return (solve);
}

int		blocks_count(char ***tetr)
{
	int	blocks;

	blocks = 0;
	while (tetr[blocks])
		++blocks;
	return (blocks);
}
