/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:43:18 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/14 00:08:51 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			cursordel(t_slc *slc)
{
	if (slc->nb_arg == 1)
		cursoresc(slc);
	freeonearg(slc);
}

void			cursoresc(t_slc *slc)
{
	freeallarg(slc);
	if (reset_slc(slc) == 0)
		exit(EXIT_FAILURE);
	if (slc->jump != NULL)
		ft_strdel(&slc->jump);
	exit(0);
}

void			cursorspace(t_slc *slc)
{
	t_arg		*ptr;

	ptr = slc->arg;
	while (ptr->cursor != 1)
		ptr = ptr->next;
	ptr->select = (ptr->select == 0 ? 1 : 0);
	ptr->cursor = 0;
	(slc->cursor)++;
	if (slc->cursor == slc->nb_arg + 1)
		slc->cursor = 1;
	ptr->next->cursor = 1;
}

void			cursorall(t_slc *slc)
{
	t_arg		*ptr;
	int			i;
	static int	on = 1;

	i = 0;
	ptr = slc->arg;
	while (i < slc->nb_arg)
	{
		if (on == 1)
			ptr->select = 1;
		else
			ptr->select = 0;
		ptr = ptr->next;
		i++;
	}
	on = (on == 0 ? 1 : 0);
}

void			cursorenter(t_slc *slc)
{
	t_arg		*ptr;
	int			i;

	i = 0;
	if (reset_slc(slc) == 0)
		exit(EXIT_FAILURE);
	ptr = slc->arg;
	while (i < slc->nb_arg)
	{
		if (ptr->select == 1)
			slc->print_arg++;
		ptr = ptr->next;
		i++;
	}
	print_select(slc);
	freeallarg(slc);
	if (slc->jump != NULL)
		ft_strdel(&slc->jump);
	exit(0);
}
