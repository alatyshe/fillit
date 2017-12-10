/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			chars;
	char			*x;
	char			*y;
	struct s_list	*next;
}					t_list;
int					ft_counter_termitos(char *str);
int					ft_pow(int b);
char				*creating_mass(int fig_number);
char				**mem_free(char **res, int j);
int					ft_read_counter(int fd);
char				*ft_read(int fd, int n);
int					ft_check(char *str, int i);
int					ft_hash(char *res);
int					ft_validate(char *res);
int					hash_temp(char *res, int i);
int					checking_figure(char *str, t_list *a, int i);
char				*pasting_figure(char *str, t_list *a, int i);
char				*clear_figure(char *str, t_list *a, int i);
char				**doing_array(int num_figures);
char				**coordinats_row_x(char *str, char **our_massive_x);
char				**coordinats_row_y(char *str, char **our_massive_y);
char				**full_array_for_x(char *str, int num_figures);
char				**full_array_for_y(char *str, int num_figures);
char				**nulling_coordinats(char **str);
t_list				*ft_add_elem(char *x, char *y, char a);
t_list				*ft_full_list(char **x, char **y);
char				*ft_recurssion_finnal(char *str, t_list *a);
char				*ft_create_box(t_list *a, int sizebox);
t_list				*list_maker(char *str);
void				ft_putstr(char const *s);
void				ft_putchar(char c);

#endif
