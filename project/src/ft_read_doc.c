/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:41:22 by dvynokur          #+#    #+#             */
/*   Updated: 2017/01/03 17:36:34 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *str, int i)
{
	int		b;

	b = 0;
	while (b < 5)
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
		b++;
	}
	return (1);
}

int		hash_temp(char *res, int i)
{
	int m;

	m = 0;
	if (res[i - 1] == '#')
		m++;
	if (res[i + 1] == '#')
		m++;
	if (res[i - 5] == '#' && ft_check(res, i - 5))
		m++;
	if (res[i + 5] == '#' && ft_check(res, i))
		m++;
	return (m);
}

int		next_line(char *str, int i)
{
	int j;

	j = 0;
	while ((str[i] != '\n' || str[i - 1] != '\n') && str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	if (j != 4)
		return (0);
	return (1);
}

int		ft_hash(char *res)
{
	int i;
	int m;
	int n;

	i = -1;
	m = 0;
	n = 0;
	if (next_line(res, 0) == 0)
		return (0);
	while (res[++i])
	{
		if (res[i] == '#')
			m += hash_temp(res, i);
		if ((res[i] == '\n' && res[i + 1] == '\n') || (res[i + 1] == '\0'))
		{
			if (m != 6 && m != 8)
				return (0);
			m = 0;
		}
		if (res[i - 1] == '\n' && res[i - 2] == '\n')
			if (next_line(res, i) == 0)
				return (0);
	}
	return (1);
}

int		ft_validate(char *res)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (res[i])
	{
		if (res[i] != '.' && res[i] != '#' && res[i] != '\n')
			return (0);
		if (res[i] == '#')
			r++;
		if (res[i] == '\n')
			if (res[i + 5] != '\n' && res[i - 5] != '\n'
				&& res[i + 1] != '\n' && res[i - 1] != '\n')
				return (0);
		i++;
	}
	if (ft_hash(res) == 0)
		return (0);
	if ((((i + 1) % 21) != 0 || r != ((i + 1) / 21 * 4)) || i > 545)
		return (0);
	return (1);
}
