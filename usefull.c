/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:30:41 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/14 15:05:53 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					valid_size(t_slc *slc)
{
	struct winsize	win;
	int				max;

	clrterm();
	ioctl(0, TIOCGWINSZ, &win);
	slc->row = win.ws_col;
	slc->col = win.ws_row;
	max = maxlen(slc) + ft_digit(slc->nb_arg, 10) + 4;
	if ((max + 7) > win.ws_col || win.ws_row < 13)
	{
		ft_putstr_fd("Window size too small...", isatty(1));
		return (0);
	}
	return (1);
}

void				print_arg(t_slc *slc, int lim_col, int lim_row, int all_col)
{
	int				max;

	max = maxlen(slc) + 3 + ft_digit(slc->nb_arg, 10);
	lim_row = slc->row / max;
	all_col = slc->nb_arg / lim_row;
	index_jump(slc);
	if (all_col + 2 > slc->col)
	{
		lim_col = 9;
		slc->total_page = (slc->nb_arg) / (10 * lim_row) + 1;
		if (slc->cursor <= (10 * lim_row))
			slc->page = 1;
		else
		{
			if ((slc->cursor) % (10 * lim_row) == 0)
				slc->page = (slc->cursor) / (10 * lim_row);
			else
				slc->page = ((slc->cursor) / (10 * lim_row) + 1);
		}
		print_onepage(slc, lim_col, lim_row, max);
	}
	else
		print_all(slc, all_col, max);
}

void				clrterm(void)
{
	tputs(tgetstr("cl", NULL), 1, fdputc);
}

void				print_select(t_slc *slc)
{
	int				i;
	t_arg			*ptr;

	i = 0;
	ptr = slc->arg;
	while (i < slc->print_arg)
	{
		if (ptr->select == 1)
		{
			ft_putstr_fd(ptr->name, 1);
			if (i != slc->print_arg - 1)
				ft_putchar_fd(' ', 1);
			i++;
		}
		ptr = ptr->next;
	}
}
