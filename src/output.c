/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:30:53 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 19:34:23 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_free(char ***map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			free(map[i][j]);
			++j;
		}
		j = 0;
		free(map[i]);
		++i;
	}
	free(map);
}

int		**row_free(char **row)
{
	int i;

	i = 0;
	while (row[i])
	{
		free(row[i]);
		++i;
	}
	free(row);
	row = NULL;
	return (0);
}

void	row_output(char **row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		ft_putendl(row[i]);
		++i;
	}
}

char	**row_create(int size)
{
	int		rows;
	int		fill;
	char	**row;

	rows = 0;
	fill = 0;
	row = (char**)malloc(sizeof(char*) * (size + 1));
	while (rows < size)
	{
		row[rows] = (char*)malloc(sizeof(char) * (size + 1));
		while (fill < size)
			row[rows][fill++] = '.';
		row[rows][fill] = 0;
		fill = 0;
		++rows;
	}
	row[rows] = NULL;
	return (row);
}

int		blocks_count(char ***map)
{
	int	blocks;

	blocks = 0;
	while (map[blocks])
		++blocks;
	return (blocks);
}
