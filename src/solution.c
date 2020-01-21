/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:43:28 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 17:58:00 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**free_row(char **row)
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
		free_row(row);
		row = row_create(min_size);
	}
	row_output(row);
	free_row(row);
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
