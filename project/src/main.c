/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:23:06 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/20 23:00:11 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		c;
	char	*all;
	t_list	*res;

	if (argc != 2 && write(1, "usage: ./fillit [map.fillit]\n", 29))
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1 && write(1, "error\n", 6))
		return (0);
	c = ft_read_counter(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	str = ft_read(fd, c);
	if (ft_validate(str) == 0 && write(1, "error\n", 6))
	{
		free(str);
		return (0);
	}
	res = list_maker(str);
	all = ft_create_box(res, ft_counter_termitos(str));
	ft_putstr(all);
	return (0);
}
