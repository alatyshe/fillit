/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 19:34:51 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/27 19:53:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read(int fd, int n)
{
	char	*result;
	char	buf[n];
	int		i;
	int		file;

	i = 0;
	result = (char*)malloc(sizeof(char) * n + 1);
	if (!result)
		return (0);
	file = read(fd, buf, n);
	buf[file] = '\0';
	while (buf[i])
	{
		result[i] = buf[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

t_list		*ft_add_elem(char *x, char *y, char a)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (!res)
		return (0);
	res->x = x;
	res->y = y;
	res->chars = a;
	res->next = NULL;
	return (res);
}

t_list		*ft_full_list(char **x, char **y)
{
	int		i;
	char	a;
	t_list	*first;
	t_list	*res;
	t_list	*temp;

	i = 0;
	a = 'A';
	first = ft_add_elem(x[i], y[i], a);
	i++;
	res = first;
	while (x[i])
	{
		a++;
		temp = ft_add_elem(x[i], y[i], a);
		res->next = temp;
		res = res->next;
		i++;
	}
	return (first);
}

char		*ft_recurssion_finnal(char *str, t_list *a)
{
	int		i;

	i = 0;
	if (!a)
		return ("YES BOSS");
	while (str[i])
	{
		if ((checking_figure(str, a, i) == 1))
		{
			pasting_figure(str, a, i);
			if ((ft_recurssion_finnal(str, a->next) == 0))
				clear_figure(str, a, i);
			else
				return (str);
		}
		i++;
	}
	return (0);
}

char		*ft_create_box(t_list *a, int sizebox)
{
	char	*res;

	if ((res = creating_mass(sizebox)) == 0)
		return (0);
	if (!(res = ft_recurssion_finnal(res, a)))
		res = ft_create_box(a, sizebox + 1);
	return (res);
}
