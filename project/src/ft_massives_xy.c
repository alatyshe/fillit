/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_massives_xy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:57:53 by dvynokur          #+#    #+#             */
/*   Updated: 2017/01/07 16:57:57 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**doing_array(int num_figures)
{
	int		i;
	char	**res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * num_figures + 1);
	if (!res)
		return (0);
	while (i < num_figures)
		if (!(res[i++] = (char *)malloc(sizeof(char) * 4 + 1)))
		{
			mem_free(res, i);
			return (0);
		}
	return (res);
}

char	**coordinats_row_x(char *str, char **our_massive_x)
{
	int		x;
	int		j;
	int		k;
	int		i;

	k = 0;
	i = -1;
	while (str[++i])
	{
		x = 0;
		j = 0;
		while ((str[i] != '\n' || str[i + 1] != '\n') && str[i + 1] != '\0')
		{
			if (str[i - 1] == '\n')
				x = 0;
			if (str[i] == '#')
				our_massive_x[k][j++] = x + '0';
			i++;
			x++;
		}
		if (j == 4)
			our_massive_x[k++][j] = '\0';
	}
	our_massive_x[k] = 0;
	return (our_massive_x);
}

char	**coordinats_row_y(char *str, char **our_massive_y)
{
	int		y;
	int		j;
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (str[i])
	{
		y = 0;
		j = 0;
		while ((str[i] != '\n' || str[i + 1] != '\n') && str[i] != '\0')
		{
			if (str[i] == '\n' && str[i - 1] != '\n')
				y++;
			if (str[i] == '#')
				our_massive_y[k][j++] = y + '0';
			i++;
		}
		if (j == 4)
			our_massive_y[k++][j] = '\0';
		i++;
	}
	our_massive_y[k] = 0;
	return (our_massive_y);
}

char	**full_array_for_x(char *str, int num_figures)
{
	char	**res;

	res = doing_array(num_figures);
	res = coordinats_row_x(str, res);
	res = nulling_coordinats(res);
	return (res);
}

char	**full_array_for_y(char *str, int num_figures)
{
	char	**res;

	res = doing_array(num_figures);
	res = coordinats_row_y(str, res);
	res = nulling_coordinats(res);
	return (res);
}
