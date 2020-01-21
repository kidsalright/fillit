/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:58:42 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 21:27:26 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		col_clean(char ***tetr, int blocks, int rows, int fill)
{
	int dots;

	dots = 0;
	while (tetr[blocks][rows])
	{
		if (tetr[blocks][rows][fill] == '.')
			++dots;
		++rows;
	}
	if (dots == rows)
	{
		rows = 0;
		while (tetr[blocks][rows])
		{
			dots = fill;
			while (tetr[blocks][rows][dots])
			{
				tetr[blocks][rows][dots] = tetr[blocks][rows][dots + 1];
				++dots;
			}
			++rows;
		}
		--fill;
	}
	return (fill);
}

void	tetr_cleancol(char ***tetr)
{
	int blocks;
	int rows;
	int fill;

	blocks = 0;
	rows = 0;
	fill = 0;
	while (tetr[blocks])
	{
		while (tetr[blocks][rows][fill])
		{
			fill = col_clean(tetr, blocks, rows, fill);
			++fill;
		}
		++blocks;
		fill = 0;
	}
}

void	tetr_cleanrow(char ***tetr)
{
	int blocks;
	int dotrows;
	int rows;

	blocks = 0;
	dotrows = 0;
	while (tetr[blocks])
	{
		while (tetr[blocks][dotrows])
		{
			if (!ft_strcmp(tetr[blocks][dotrows], "...."))
			{
				free(tetr[blocks][dotrows]);
				rows = dotrows--;
				while (tetr[blocks][rows++])
					tetr[blocks][rows - 1] = tetr[blocks][rows];
			}
			++dotrows;
		}
		dotrows = 0;
		++blocks;
	}
}

void	tetr_fill(char ***tetr, char **str)
{
	int blocks;
	int rows;
	int	fill;

	blocks = 0;
	rows = 0;
	fill = 0;
	while (tetr[blocks])
	{
		while (tetr[blocks][rows])
		{
			while (tetr[blocks][rows][fill])
			{
				if (str[blocks][rows * 5 + fill++] == '#')
					tetr[blocks][rows][fill - 1] = str[blocks]\
						[rows * 5 + fill - 1] + 30 + blocks;
			}
			++rows;
			fill = 0;
		}
		++blocks;
		rows = 0;
	}
}

char	***tetr_create(int count, int size)
{
	char	***tetr;
	int		blocks;
	int		rows;
	int		dots;

	blocks = 0;
	rows = 0;
	tetr = (char***)malloc(sizeof(char**) * (count + 1));
	while (blocks < count)
	{
		tetr[blocks] = (char**)malloc(sizeof(char*) * (size + 1));
		while (rows < size)
		{
			dots = 0;
			tetr[blocks][rows] = ft_strnew(size);
			while (dots < size)
				tetr[blocks][rows][dots++] = '.';
			++rows;
		}
		tetr[blocks][rows] = NULL;
		++blocks;
		rows = 0;
	}
	tetr[blocks] = NULL;
	return (tetr);
}
