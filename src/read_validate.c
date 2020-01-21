/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:01:46 by yberries          #+#    #+#             */
/*   Updated: 2020/01/21 21:15:25 by yberries         ###   ########.fr       */
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
			error();
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

int		tetr_validation(char *str)
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
		if (!(tetr_validation(buf)) || res < 20)
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

char	**tetr_to_string(char *file, int count)
{
	int		fd;
	int		res;
	char	*buf;
	char	**str;
	int		i;

	i = 0;
	buf = ft_strnew(21);
	if (!(str = (char**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((res = read(fd, buf, 21)))
	{
		str[i] = ft_strdup(buf);
		++i;
	}
	free(buf);
	if (close(fd) == -1)
		return (0);
	return (str);
}

char	***read_validate(char *file)
{
	char	***tetr;
	int		count;
	char	**str;
	int		i;

	if (!(count = tetr_count(file)))
		error();
	if (!(str = tetr_to_string(file, count)))
		error();
	if (!(tetr = tetr_create(count, 4)))
		error();
	tetr_fill(tetr, str);
	tetr_cleanrow(tetr);
	tetr_cleancol(tetr);
	i = 0;
	while (i < count)
	{
		ft_strdel(&str[i]);
		++i;
	}
	free(str);
	return (tetr);
}
