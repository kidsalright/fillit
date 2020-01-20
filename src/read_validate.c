/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:01:46 by yberries          #+#    #+#             */
/*   Updated: 2020/01/20 15:15:45 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		blocks_validation(char *str, int *hash, int *con, int *empty)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '.')
			++(*empty);
		if (str[i] == '#')
		{
			if (i < 14 && str[i + 5] == '#')
				++(*con);
			if (i >= 5 && str[i - 5] == '#')
				++(*con);
			if (i >= 1 && str[i - 1] == '#')
				++(*con);
			if (i < 19 && str[i + 1] == '#')
				++(*con);
			++(*hash);
		}
		++i;
	}
	return (0);
}

int		map_validation(char *str)
{
	int	hash;
	int	empty;
	int	con;

	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' ||
			str[19] != '\n' || (str[20] != '\n' && str[20] != '\0'))
		return (0);
	hash = 0;
	con = 0;
	empty = 0;
	blocks_validation(str, &hash, &con, &empty);
	if ((empty != 12 || hash != 4) || con < 6)
		return (0);
	return (1);
}

int		tetr_count(char *file)
{
	int		fd;
	char	*buf;
	int		count;
	int		res;
	int		newres;

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	count = 0;
	buf = ft_strnew(21);
	while ((res = read(fd, buf, 21)))
	{
		if (!(map_validation(buf)) || res < 20)
			error();
		++count;
		newres = res;
	}
	free(buf);
	if (newres != 20)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (count);
}

char	***read_validate(char *file)
{
	int		count;

	if (!(count = tetr_count(file)))
		error();
	return (0);
}
