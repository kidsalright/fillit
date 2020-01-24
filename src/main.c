/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:29:41 by yberries          #+#    #+#             */
/*   Updated: 2020/01/24 17:03:00 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putendl("error");
	exit(1);
}

int		get_size(int sqr)
{
	int i;

	i = 2;
	while (i * i < sqr)
		++i;
	return (i);
}

int		main(int argc, char **argv)
{
	char ***tetr;

	if (argc == 2)
	{
		tetr = read_validate(argv[1]);
		solution(tetr);
	}
	else
	{
		ft_putendl("usage: ./fillit file.fillit");
		exit(1);
	}
	return (0);
}
