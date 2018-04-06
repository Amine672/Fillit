/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:51:01 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/26 05:49:07 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		get_tab(t_coord tetris)
{
	int x;
	int i;
	int y;

	i = 0;
	y = 0;
	tetris.tab = (char **)malloc(sizeof(char *) * tetris.lon);
	while (y < tetris.lon)
	{
		x = 0;
		tetris.tab[y] = (char *)malloc(sizeof(char ) * (tetris.lar));
		while (x < tetris.lar)
		{
			if (y == tetris.key[i] && x == tetris.key[i + 4])
			{
				tetris.tab[y][x] = '#';
				i++;
			}
			else
				tetris.tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tetris);
}

t_coord		get_key(t_coord tetris)
{
	int i;
	int xmin;
	int ymin;

	i = 0;
	ymin = ft_min(tetris, 0);
	xmin = ft_min(tetris, 4);
	tetris.lar = (ft_max(tetris, 4) - xmin + 1);
	tetris.lon = (ft_max(tetris, 0) - ymin + 1);
	while (i < 4)
	{
		tetris.key[i] -= ymin;
		tetris.key[i + 4] -= xmin;
		i++;
	}
	tetris = get_tab(tetris);
	return (tetris);
}

t_coord		get_coord(char ***str, int nb)
{
	t_coord	tetris;
	int		y;
	int		x;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (y < 4)
	{
		if (str[nb][y][x] == '#')
		{
			tetris.key[i] = y;
			tetris.key[i + 4] = x;
			i++;
		}
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
	}
	tetris = get_key(tetris);
	return (tetris);
}

t_coord		*get_ntetris(char ***str, int total)
{
	t_coord	*tetris;
	int		i;
	char	c;

	i = 0;
	c = 'A';
	tetris = (t_coord *)malloc(sizeof(t_coord) * (total * 2));
	while (i < total)
	{
		tetris[i] = get_coord(str, i);
		tetris[i].value = c++;
		i++;
	}
	tetris[total + 1].value = '\0';
	return (tetris);
}

t_coord		*get_tetris(char *s, int total)
{
	char	***str;
	t_coord	*tetris;
	int		nb;
	int		y;

	nb = 0;
	y = 0;
	str = (char ***)malloc(sizeof(char **) * total);
	while (nb < total)
	{
		y = 0;
		str[nb] = (char **)malloc(sizeof(char *) * 4);
		while (y < 4)
		{
			str[nb][y] = ft_strsub(s, nb * 21 + y * 5, 4);
			y++;
		}
		nb++;
	}
	tetris = get_ntetris(str, total);
	return (tetris);
}
