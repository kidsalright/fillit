/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:43:28 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 19:35:06 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_row(char **row, char **map, int i, int j)
{
	int rows;
	int fill;

	rows = 0;
	fill = 0;
	while (map[rows])
	{
		while (map[rows][fill])
		{
			if (map[rows][fill] != '.')
				row[i + rows][j + fill] = '.';
			++fill;
		}
		fill = 0;
		++rows;
	}
}

void	insert_row(char **row, char **map, int i, int j)
{
	int rows;
	int fill;

	rows = 0;
	fill = 0;
	while (map[rows])
	{
		while (map[rows][fill])
		{
			if (map[rows][fill] != '.')
				row[i + rows][j + fill] = map[rows][fill];
			++fill;
		}
		fill = 0;
		++rows;
	}
}

int		insert_check(char **row, char **map, int i, int j)
{
	int rows;
	int	fill;

	rows = 0;
	fill = 0;
	while (map[rows])
	{
		if (row[i + rows] == 0)
			return (0);
		while (map[rows][fill])
		{
			if (row[i + rows][j + fill] == 0)
				return (0);
			if (map[rows][fill] != '.' && row[i + rows][j + fill] != '.')
				return (0);
			++fill;
		}
		fill = 0;
		++rows;
	}
	return (1);
}

int		backtracking(char **row, char ***map, int vars)
{
	int	rows;
	int	fill;

	rows = 0;
	fill = 0;
	if (map[vars] == 0)
		return (0);
	while (row[rows])
	{
		while (row[rows][fill])
		{
			if (insert_check(row, map[vars], rows, fill))
			{
				insert_row(row, map[vars], rows, fill);
				if (!backtracking(row, map, vars + 1))
					return (0);
				clean_row(row, map[vars], rows, fill);
			}
			++fill;
		}
		++rows;
		fill = 0;
	}
	return (1);
}

void	solution(char ***map)
{
	int		min_size;
	char	**row;
	int		i;
	int		j;

	i = 0;
	j = 0;
	min_size = ft_root(2, blocks_count(map) * 4);
	row = row_create(min_size);
	while (backtracking(row, map, 0))
	{
		++min_size;
		row_free(row);
		row = row_create(min_size);
	}
	row_output(row);
	row_free(row);
	map_free(map);
}
