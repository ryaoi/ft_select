/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursordown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 03:10:26 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/14 03:10:27 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void curs_move(t_arg *ptr, int i, int j, int nb_arg)
{
    int     lim;

    lim = 0;
    if (j + i < nb_arg + 1)
	{
		while (lim < i)
		{
			ptr = ptr->next;
			lim++;
		}
		ptr->cursor = 1;
		return ;
	}
    lim = j % i;
    j++;
    while ((j % i != lim))
    {
        if (j == nb_arg)
        {
            j = 1;
            ptr = ptr->next;
        }
        else
            j++;
        ptr = ptr->next;

    }
	ptr->cursor = 1;
}

void		cursordown(t_slc *slc)
{
	t_arg	*ptr;
	int		i;
	int		j;
	int		max;

	i = 0;
	max = maxlen(slc) + 2;
	i = slc->row / max;
	j = 1;
	ptr = slc->arg;
	while (ptr->cursor != 1)
	{
		ptr = ptr->next;
		j++;
	}
	ptr->cursor = 0;
    curs_move(ptr, i, j, slc->nb_arg);
}
