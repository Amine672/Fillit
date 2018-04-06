/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:59:59 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/26 06:06:40 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_coord		*tetris;
	t_map		*map;
	int			fd;
	char		buf[BUF_SIZE];
	int			total;

	if (argc != 2)
		ft_exit("usage: fillit input_file");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_exit("error");
	if ((fd = read(fd, buf, BUF_SIZE)) < 0)
		ft_exit("error");
	if (fd % 21 != 20)
		ft_exit("error");
	total = read_tetris(buf, fd);
	tetris = get_tetris(buf, total);
	map = solve(tetris, total);
	print_map(map);
	close(fd);
	return (0);
}
