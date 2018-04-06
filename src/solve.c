/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 05:23:51 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/26 05:55:00 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*create_map(int size)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->size = size;
	map->map = (char **)ft_memalloc(sizeof(char *) * size);
	while (i < size)
	{
		map->map[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		draw_tetris(t_coord tetris, t_map *map, int x, int y)
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
				map->map[y + j][x + i] = tetris.value;
			j++;
		}
		i++;
	}
}

int			can_draw(t_coord tetris, t_map *map, int x, int y)
{
	int i;
	int j;
	int check;

	i = 0;
	check = 0;
	while (i < tetris.lar)
	{
		j = 0;
		while (j < tetris.lon)
		{
			if (tetris.tab[j][i] == '#' && map->map[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	draw_tetris(tetris, map, x, y);
	return (1);
}

int			solve_map(t_map *map, t_coord *tetris, int total)
{
	int x;
	int i;
	int y;

	i = 0;
	y = 0;
	if (!(tetris[i].value))
		return (1);
	while (y < map->size - tetris[i].lon + 1)
	{
		x = 0;
		while (x < map->size - tetris[i].lar + 1)
		{
			if (can_draw(tetris[i], map, x, y))
			{
				if (solve_map(map, &tetris[i + 1], total))
					return (1);
				else
					free_tetris(tetris[i], map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map		*solve(t_coord *tetris, int total)
{
	t_map	*map;
	int		size;

	if ((tetris[0].lon == 4 || tetris[0].lar == 4) && total == 1)
		size = 4;
	else
		size = ft_hsqrt(total * 4);
	map = create_map(size);
	while (!solve_map(map, tetris, total))
		map = create_map(size++);
	return (map);
}
