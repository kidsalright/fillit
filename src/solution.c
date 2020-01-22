/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:43:28 by yberries          #+#    #+#             */
/*   Updated: 2020/01/22 16:02:07 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_row(char **solve, char **tetr, int r, int f)
{
	int rows;
	int fill;

	rows = 0;
	fill = 0;
	while (tetr[rows])
	{
		while (tetr[rows][fill])
		{
			if (tetr[rows][fill] != '.')
				solve[r + rows][f + fill] = '.';
			++fill;
		}
		fill = 0;
		++rows;
	}
}

void	insert_row(char **solve, char **tetr, int r, int f)
{
	int rows;
	int fill;

	rows = 0;
	fill = 0;
	while (tetr[rows])
	{
		while (tetr[rows][fill])
		{
			if (tetr[rows][fill] != '.')
				solve[r + rows][f + fill] = tetr[rows][fill];
			++fill;
		}
		fill = 0;
		++rows;
	}
}

int		insert_check(char **solve, char **tetr, int r, int f)
{
	int rows;
	int	fill;

	rows = 0;
	fill = 0;
	while (tetr[rows])
	{
		if (solve[r + rows] == 0)
			return (0);
		while (tetr[rows][fill])
		{
			if (solve[r + rows][f + fill] == 0)
				return (0);
			if (tetr[rows][fill] != '.' && solve[r + rows][f + fill] != '.')
				return (0);
			++fill;
		}
		fill = 0;
		++rows;
	}
	return (1);
}

int		backtracking(char **solve, char ***tetr, int blocks)
{
	int	rows;
	int	fill;

	rows = 0;
	fill = 0;
	if (tetr[blocks] == 0)
		return (0);
	while (solve[rows])
	{
		while (solve[rows][fill])
		{
			if (insert_check(solve, tetr[blocks], rows, fill))
			{
				insert_row(solve, tetr[blocks], rows, fill);
				if (!backtracking(solve, tetr, blocks + 1))
					return (0);
				clean_row(solve, tetr[blocks], rows, fill);
			}
			++fill;
		}
		++rows;
		fill = 0;
	}
	return (1);
}

void	solution(char ***tetr)
{
	int		min_size;
	char	**solve;

	min_size = ft_root(2, blocks_count(tetr) * 4);
	solve = solve_create(min_size);
	while (backtracking(solve, tetr, 0))
	{
		++min_size;
		solve_free(solve);
		solve = solve_create(min_size);
	}
	solve_output(solve);
	solve_free(solve);
	tetr_free(tetr);
}
