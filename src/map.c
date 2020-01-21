/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:58:42 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 18:14:18 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		col_clean(char ***map, int blocks, int rows, int fill)
{
	int dots;

	dots = 0;
	while (map[blocks][rows])
	{
		if (map[blocks][rows][fill] == '.')
			++dots;
		++rows;
	}
	if (dots == rows)
	{
		rows = 0;
		while (map[blocks][rows])
		{
			dots = fill;
			while (map[blocks][rows][dots])
			{
				map[blocks][rows][dots] = map[blocks][rows][dots + 1];
				++dots;
			}
			++rows;
		}
		--fill;
	}
	return (fill);
}

void	map_cleancol(char ***map)
{
	int blocks;
	int rows;
	int fill;

	blocks = 0;
	rows = 0;
	fill = 0;
	while (map[blocks])
	{
		while (map[blocks][rows][fill])
		{
			fill = col_clean(map, blocks, rows, fill);
			++fill;
		}
		++blocks;
		fill = 0;
	}
}

void	map_cleanrow(char ***map)
{
	int blocks;
	int dotrows;
	int rows;

	blocks = 0;
	dotrows = 0;
	while (map[blocks])
	{
		while (map[blocks][dotrows])
		{
			if (!ft_strcmp(map[blocks][dotrows], "...."))
			{
				free(map[blocks][dotrows]);
				rows = dotrows--;
				while (map[blocks][rows++])
					map[blocks][rows - 1] = map[blocks][rows];
			}
			++dotrows;
		}
		dotrows = 0;
		++blocks;
	}
}

void	map_fill(char ***map, char **str)
{
	int blocks;
	int rows;
	int	fill;

	blocks = 0;
	rows = 0;
	fill = 0;
	while (map[blocks])
	{
		while (map[blocks][rows])
		{
			while (map[blocks][rows][fill])
			{
				if (str[blocks][rows * 5 + fill++] == '#')
					map[blocks][rows][fill - 1] = str[blocks]\
						[rows * 5 + fill - 1] + 30 + blocks;
			}
			++rows;
			fill = 0;
		}
		++blocks;
		rows = 0;
	}
}

char	***map_create(int count, int size)
{
	char	***map;
	int		blocks;
	int		rows;
	int		dots;

	blocks = 0;
	rows = 0;
	map = (char***)malloc(sizeof(char**) * (count + 1));
	while (blocks < count)
	{
		map[blocks] = (char**)malloc(sizeof(char*) * (size + 1));
		while (rows < size)
		{
			dots = 0;
			map[blocks][rows] = ft_strnew(size);
			while (dots < size)
				map[blocks][rows][dots++] = '.';
			++rows;
		}
		map[blocks][rows] = NULL;
		++blocks;
		rows = 0;
	}
	map[blocks] = NULL;
	return (map);
}
