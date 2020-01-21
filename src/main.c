/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:29:41 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 19:18:43 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	error(void)
{
	ft_putendl("error");
	exit(1);
}

int		main(int argc, char **argv)
{
	char ***map;

	if (argc == 2)
	{
		map = read_validate(argv[1]);
		solution(map);
	}
	else
	{
		ft_putendl("usage: ./fillit file.fillit");
		exit(1);
	}
	return (0);
}
