/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:12:49 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/24 01:54:42 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_putspace(int len, int max)
{
	while (len < max)
	{
		ft_putchar_fd(' ', isatty(1));
		len++;
	}
}

void		cursorleft(t_slc *slc)
{
	t_arg	*ptr;

	ptr = slc->arg;
	while (ptr->cursor != 1)
		ptr = ptr->next;
	ptr->cursor = 0;
	ptr->prev->cursor = 1;
}

void		cursorright(t_slc *slc)
{
	t_arg	*ptr;

	ptr = slc->arg;
	while (ptr->cursor != 1)
		ptr = ptr->next;
	ptr->cursor = 0;
	ptr->next->cursor = 1;
}
