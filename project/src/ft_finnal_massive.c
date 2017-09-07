/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finnal_massive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:24:18 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/26 19:24:19 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_counter_termitos(char *str)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') || str[i + 1] == '\0')
			y++;
		i++;
	}
	return (y);
}

int		ft_pow(int b)
{
	int		res;
	int		n;

	n = 1;
	res = 0;
	while ((res = n * n) < b)
		n++;
	return (n);
}

char	*creating_mass(int fig_number)
{
	int		i;
	int		j;
	char	*res;
	int		pow;

	i = 0;
	j = 0;
	pow = ft_pow((fig_number * 4));
	res = (char*)malloc(sizeof(char) * (pow * pow + pow) + 1);
	if (!res)
		return (0);
	while (j < (pow * pow + pow))
	{
		if ((j + 1) % (pow + 1) != 0)
			res[j] = '.';
		else
			res[j] = '\n';
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	**mem_free(char **res, int j)
{
	int i;

	i = 0;
	while (i < j)
		i++;
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

t_list	*list_maker(char *str)
{
	t_list	*a;
	char	**massive_x;
	char	**massive_y;

	massive_x = full_array_for_x(str, ft_counter_termitos(str));
	massive_y = full_array_for_y(str, ft_counter_termitos(str));
	a = ft_full_list(massive_x, massive_y);
	return (a);
}
