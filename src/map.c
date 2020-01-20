/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:58:42 by yberries          #+#    #+#             */
/*   Updated: 2020/01/20 23:00:40 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		col_clean(char ***map, int blocks, int cols, int fill)
{
	int dots;

	dots = 0;
	while (map[blocks][cols])
	{
		if (map[blocks][cols][fill] == '.')
			++dots;
		++cols;
	}
	if (dots == cols)
	{
		cols = 0;
		while (map[blocks][cols])
		{
			dots = fill;
			while (map[blocks][cols][dots])
			{
				map[blocks][cols][dots] = map[blocks][cols][dots + 1];
				++dots;
			}
			++cols;
		}
		--fill;
	}
	return (fill);
}

void	map_cleancol(char ***map)
{
	int blocks;
	int cols;
	int fill;

	blocks = 0;
	cols = 0;
	fill = 0;
	while (map[blocks])
	{
		while (map[blocks][cols][fill])
		{
			fill = col_clean(map, blocks, cols, fill);
			++fill;
		}
		++blocks;
		cols = 0;
	}
}

void	map_cleanrow(char ***map)
{
	int blocks;
	int rows;
	int fill;

	blocks = 0;
	rows = 0;
	while (map[blocks])
	{
		while (map[blocks][rows])
		{
			if (!ft_strcmp(map[blocks][rows], "...."))
			{
				free(map[blocks][rows]);
				fill = rows--;
				while (map[blocks][fill++])
					map[blocks][fill - 1] = map[blocks][fill];
			}
			++rows;
		}
		rows = 0;
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

char	***map_create(int count, int size, char c)
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
				map[blocks][rows][dots++] = c;
			++rows;
		}
		map[blocks][rows] = NULL;
		++blocks;
		rows = 0;
	}
	map[blocks] = NULL;
	return (map);
}
