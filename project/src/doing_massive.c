/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_massive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:32:10 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/26 17:34:26 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_counter(int fd)
{
	int		i;
	char	b;

	i = 0;
	while (read(fd, &b, 1))
		i++;
	return (i);
}

int		checking_figure(char *str, t_list *a, int i)
{
	int		n;
	char	*x;
	char	*y;

	x = a->x;
	y = a->y;
	n = 0;
	while (str[n - 1] != '\n')
		n++;
	if (str[i + ((y[0] - '0') * n + (x[0] - '0'))] == '.')
		if (str[i + ((y[1] - '0') * n + (x[1] - '0'))] == '.')
			if (str[i + ((y[2] - '0') * n + (x[2] - '0'))] == '.')
				if (str[i + ((y[3] - '0') * n + (x[3] - '0'))] == '.')
					return (1);
	return (0);
}

char	*pasting_figure(char *str, t_list *a, int i)
{
	int		n;
	char	*x;
	char	*y;
	char	b;

	x = a->x;
	y = a->y;
	b = a->chars;
	n = 0;
	while (str[n - 1] != '\n')
		n++;
	str[i + ((y[0] - '0') * n + (x[0] - '0'))] = b;
	str[i + ((y[1] - '0') * n + (x[1] - '0'))] = b;
	str[i + ((y[2] - '0') * n + (x[2] - '0'))] = b;
	str[i + ((y[3] - '0') * n + (x[3] - '0'))] = b;
	return (str);
}

char	*clear_figure(char *str, t_list *a, int i)
{
	int		n;
	char	*x;
	char	*y;

	x = a->x;
	y = a->y;
	n = 0;
	while (str[n - 1] != '\n')
		n++;
	str[i + ((y[0] - '0') * n + (x[0] - '0'))] = '.';
	str[i + ((y[1] - '0') * n + (x[1] - '0'))] = '.';
	str[i + ((y[2] - '0') * n + (x[2] - '0'))] = '.';
	str[i + ((y[3] - '0') * n + (x[3] - '0'))] = '.';
	return (str);
}

char	**nulling_coordinats(char **str)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	j = 0;
	while (str[j])
	{
		a = '4';
		while (str[j][i])
		{
			if (str[j][i] < a)
				a = str[j][i];
			i++;
		}
		if (a > '0' && i--)
			while (i >= 0)
				str[j][i--] -= (a - '0');
		i = 0;
		j++;
	}
	return (str);
}
