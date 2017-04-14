/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursorup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 03:05:11 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/14 03:05:12 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void curs_move(t_arg *ptr, int i, int j, int left)
{
    if (j - i < 0 && j < left)
	{
		while (left > 0)
		{
			ptr = ptr->prev;
			left--;
		}
		ptr->cursor = 1;
		return ;
	}
	while (i > 0)
	{
		if (j == 0)
			i += left;
		i--;
		ptr = ptr->prev;
		j--;
	}
	ptr->cursor = 1;
}

void		cursorup(t_slc *slc)
{
	t_arg	*ptr;
	int		i;
	int		j;
	int		max;
	int		left;

	i = 0;
	max = maxlen(slc) + 2;
	left = slc->nb_arg % (slc->row / max);
	i = slc->row / max;
	j = 0;
	ptr = slc->arg;
	while (ptr->cursor != 1)
	{
		ptr = ptr->next;
		j++;
	}
	ptr->cursor = 0;
    curs_move(ptr, i, j, left);
}
