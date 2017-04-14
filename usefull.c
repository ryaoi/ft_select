/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:30:41 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/07 18:42:40 by ryaoi            ###   ########.fr       */
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
	max = maxlen(slc) + 2;
	if (max > win.ws_col)
	{
		ft_putstr_fd("Window size too small...", isatty(1));
		return (0);
	}
	return (1);
}

void				print_arg(t_slc *slc)
{
	int				i;
	int				j;
	int				max;
	int				lim_col;
	t_arg			*ptr;

	i = 0;
	ptr = slc->arg;
	max = maxlen(slc) + 2;
	if (slc->row / max >= 1)
		lim_col = slc->nb_arg / (slc->row / max);
	j = 0;
	while (i < slc->nb_arg)
	{
		print_list(slc, &j, max, ptr);
		ptr = ptr->next;
		i++;
	}
	print_page(slc, lim_col);
}

void				clrterm(void)
{
	tputs(tgetstr("cl", NULL), 0, fdputc);
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
