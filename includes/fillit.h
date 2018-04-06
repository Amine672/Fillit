/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:44:47 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/26 06:40:51 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 546
# include "../libft/libft.h"
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

typedef struct		s_coord
{
	int				lar;
	int				lon;
	char			value;
	int				key[8];
	char			**tab;

}					t_coord;

typedef struct		s_map
{
	int				size;
	char			**map;
}					t_map;

int					ft_hsqrt(int s);
int					read_tetris(char *buf, int fd);
t_coord				*get_tetris(char *s, int total);
t_map				*solve(t_coord *tetris, int total);
void				print_map(t_map *map);
void				free_tetris(t_coord tetris, t_map *map, int x, int y);
int					ft_min(t_coord tetris, int i);
int					ft_max(t_coord tetris, int i);

#endif
