/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:43:28 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 21:18:38 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_row(char **solve, char **tetr, int i, int j)
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
				solve[i + rows][j + fill] = '.';
			++fill;
		}
		fill = 0;
		++rows;
	}
}

void	insert_row(char **solve, char **tetr, int i, int j)
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
				solve[i + rows][j + fill] = tetr[rows][fill];
			++fill;
		}
		fill = 0;
		++rows;
	}
}

int		insert_check(char **solve, char **tetr, int i, int j)
{
	int rows;
	int	fill;

	rows = 0;
	fill = 0;
	while (tetr[rows])
	{
		if (solve[i + rows] == 0)
			return (0);
		while (tetr[rows][fill])
		{
			if (solve[i + rows][j + fill] == 0)
				return (0);
			if (tetr[rows][fill] != '.' && solve[i + rows][j + fill] != '.')
				return (0);
			++fill;
		}
		fill = 0;
		++rows;
	}
	return (1);
}

int		backtracking(char **solve, char ***tetr, int vars)
{
	int	rows;
	int	fill;

	rows = 0;
	fill = 0;
	if (tetr[vars] == 0)
		return (0);
	while (solve[rows])
	{
		while (solve[rows][fill])
		{
			if (insert_check(solve, tetr[vars], rows, fill))
			{
				insert_row(solve, tetr[vars], rows, fill);
				if (!backtracking(solve, tetr, vars + 1))
					return (0);
				clean_row(solve, tetr[vars], rows, fill);
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
	int		i;
	int		j;

	i = 0;
	j = 0;
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
