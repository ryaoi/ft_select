/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursorleft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 03:10:26 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/16 22:50:59 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	left_onepage(t_slc *slc)
{
	t_arg	*ptr;
	int		i;
	int		j;

	j = 1;
	ptr = slc->arg;
	while (ptr->cursor != 1)
	{
		ptr = ptr->next;
		j++;
	}
	i = 0;
	if (j - 10 > 0)
	{
		ptr->cursor = 0;
		while (i < 10)
		{
			ptr = ptr->prev;
			(slc->cursor)--;
			i++;
		}
		ptr->cursor = 1;
	}
}

static void	move_left(t_slc *slc, int all_col)
{
	int		i;
	int		j;
	t_arg	*ptr;

	j = 1;
	ptr = slc->arg;
	while (ptr->cursor != 1)
	{
		ptr = ptr->next;
		j++;
	}
	i = 0;
	if (j - all_col > 1)
	{
		ptr->cursor = 0;
		while (i <= all_col)
		{
			ptr = ptr->prev;
			(slc->col)--;
			i++;
		}
		ptr->cursor = 1;
	}
}

void		cursorleft(t_slc *slc)
{
	int		max;
	int		lim_row;
	int		all_col;

	max = maxlen(slc) + 3 + ft_digit(slc->nb_arg, 10);
	lim_row = slc->row / max;
	all_col = slc->nb_arg / lim_row;
	if (all_col + 2 > slc->col)
		left_onepage(slc);
	else
		move_left(slc, all_col);
}
