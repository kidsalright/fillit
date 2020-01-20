/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:29:41 by yberries          #+#    #+#             */
/*   Updated: 2020/01/20 13:44:17 by yberries         ###   ########.fr       */
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
	if (argc == 2)
	{
		printf("HAH \n");
		printf("%s", argv[1]);
	}
	else
		ft_putendl("wowstop");
	return (0);
}
