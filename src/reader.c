/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:22:40 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/26 05:53:34 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_form(char *str)
{
	int		i;
	int		nb;
	int		connex;

	connex = 0;
	i = -1;
	nb = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				connex++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				connex++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				connex++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				connex++;
			nb += 1;
		}
	}
	if (nb != 4 || (connex != 8 && connex != 6))
		ft_exit("error");
	return (0);
}

int		check_tetris(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i % 5 == 4 || i == 20)
		{
			if (str[i] != '\n')
				ft_exit("error");
			i++;
		}
		if (str[i + 1] == '\0')
			return (0);
		if (!(str[i] == '#' || str[i] == '.'))
			ft_exit("error");
		i++;
	}
	return (0);
}

int		read_tetris(char *buf, int fd)
{
	int		i;
	int		total;

	total = 0;
	i = 0;
	while (i <= fd)
	{
		check_tetris(ft_strsub(buf, i, 21));
		check_form(ft_strsub(buf, i, 21));
		total += 1;
		i += 21;
	}
	return (total);
}
