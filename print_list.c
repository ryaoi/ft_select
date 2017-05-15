/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 04:31:18 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/15 13:01:32 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_elements(t_slc *slc, int max, t_arg *ptr, int i)
{
	int		count;
	char	*tmp;

	tmp = ft_itoa(slc->index);
	count = 0;
	while (count != max * i)
	{
		tputs(tgetstr("nd", NULL), 1, fdputc);
		count++;
	}
	default_color(slc, ptr);
	if (ptr->select == 1)
		ft_putstr_fd(REV, isatty(1));
	if (ptr->cursor == 1)
		ft_putstr_fd(ULINE, isatty(1));
	ft_putstr_fd(tmp, isatty(1));
	ft_putchar_fd(':', isatty(1));
	ft_putstr_fd(ptr->name, isatty(1));
	ft_putstr_fd(RESET, isatty(1));
	ft_putspace(ft_strlen(ptr->name) + ft_strlen(tmp), max);
	tputs(tgetstr("do", NULL), 1, fdputc);
	ft_strdel(&tmp);
	(slc->index)++;
}

void		print_all(t_slc *slc, int all_col, int max)
{
	int		count;
	int		i;
	int		j;
	t_arg	*ptr;

	i = 0;
	count = 0;
	ptr = slc->arg;
	while (slc->index <= slc->nb_arg)
	{
		j = 0;
		while (j <= all_col && slc->index <= slc->nb_arg)
		{
			print_elements(slc, max, ptr, i);
			j++;
			ptr = ptr->next;
		}
		while (j != 0)
		{
			tputs(tgetstr("up", NULL), 1, fdputc);
			j--;
		}
		i++;
	}
	slc->index = 1;
}

static void	define_index(t_slc *slc, t_arg **ptr, int lim_row, int *i)
{
	*i = 1;
	if (slc->cursor > (10 * lim_row))
		slc->index = (slc->page - 1) * (10 * lim_row) + 1;
	else
		slc->index = 1;
	while (*i < slc->index)
	{
		(*ptr) = (*ptr)->next;
		(*i)++;
	}
	*i = 0;
}

static void	put_page(t_slc *slc, int lim_col)
{
	int		i;
	char	*page;
	char	*all_page;

	i = 0;
	tputs(tgetstr("cr", NULL), 1, fdputc);
	while (i < lim_col + 2)
	{
		tputs(tgetstr("do", NULL), 1, fdputc);
		i++;
	}
	ft_putstr_fd(" ", isatty(1));
	page = ft_itoa(slc->page);
	all_page = ft_itoa(slc->total_page);
	ft_putstr_fd(page, isatty(1));
	ft_putstr_fd("/", isatty(1));
	ft_putstr_fd(all_page, isatty(1));
	ft_putstr_fd("page", isatty(1));
	ft_strdel(&page);
	ft_strdel(&all_page);
}

void		print_onepage(t_slc *slc, int lim_col, int lim_row, int max)
{
	int		i;
	int		j;
	int		count;
	t_arg	*ptr;

	count = 0;
	ptr = slc->arg;
	define_index(slc, &ptr, lim_row, &i);
	while (i < lim_row && slc->index <= slc->nb_arg)
	{
		j = 0;
		while (j < (lim_col + 1) && slc->index <= slc->nb_arg)
		{
			print_elements(slc, max, ptr, i);
			j++;
			ptr = ptr->next;
		}
		while (j != 0)
		{
			tputs(tgetstr("up", NULL), 1, fdputc);
			j--;
		}
		i++;
	}
	put_page(slc, lim_col);
}
