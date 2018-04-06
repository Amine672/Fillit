/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:15:38 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/26 05:58:26 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_max(t_coord tetris, int i)
{
	int	max;
	int	y;

	y = i + 3;
	max = tetris.key[i];
	while (i < y)
	{
		if (max < tetris.key[i + 1])
			max = tetris.key[i + 1];
		i++;
	}
	return (max);
}

void		free_tetris(t_coord tetris, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetris.lar)
	{
		j = 0;
		while (j < tetris.lon)
		{
			if (tetris.tab[j][i] == '#')
				map->map[y + j][x + i] = '.';
			j++;
		}
		i++;
	}
}

int			ft_min(t_coord tetris, int i)
{
	int	min;
	int	y;

	y = i + 3;
	min = tetris.key[i];
	while (i < y)
	{
		if (min > tetris.key[i + 1])
			min = tetris.key[i + 1];
		i++;
	}
	return (min);
}

void		print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}

int			ft_hsqrt(int nb)
{
	int size;

	size = 2;
	while (size * size < nb)
		size++;
	return (size);
}
