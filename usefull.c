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

void				get_col(t_slc *slc)
{
	int				i;
	int				max;
	t_arg			*ptr;

	i = 0;
	ptr = slc->arg;
	max = slc->arg->size;
	while (i < slc->nb_arg && ptr)
	{
		if (max < ptr->size)
			max = ptr->size;
		i++;
		ptr = ptr->next;
	}
	slc->col = max + 4;
}

int					valid_size(t_slc *slc)
{
	struct winsize	win;

	clrterm();
	ioctl(0, TIOCGWINSZ, &win);
	slc->row = win.ws_col;
	slc->col = win.ws_row;
	return (1);
}

void				print_arg(t_slc *slc)
{
	int				i;
	int				j;
	int				max;
	t_arg			*ptr;

	i = 0;
	ptr = slc->arg;
	max = maxlen(slc) + 2;
	j = 0;
	while (i < slc->nb_arg)
	{
		ft_putstr_fd(GREEN, isatty(1));
		if (ptr->select == 1)
			ft_putstr_fd(REV, isatty(1));
		if (ptr->cursor == 1)
			ft_putstr_fd(ULINE, isatty(1));
		j += max;
		if (j >= slc->row)
		{
			ft_putchar_fd('\n', isatty(1));
			j = max;
		}
		ft_putstr_fd(ptr->name, isatty(1));
		ft_putstr_fd(RESET, isatty(1));
		ft_putspace(ft_strlen(ptr->name), max);
		ptr = ptr->next;
		i++;
	}
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
