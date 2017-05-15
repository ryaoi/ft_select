/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:27:29 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/14 16:37:07 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		more_option(t_slc *slc, char *buffer)
{
	if (buffer[0] == -62 && buffer[1] == -82 && buffer[2] == 0)
		slc->defo_color = RED;
	else if (buffer[0] == -62 && buffer[1] == -87 && buffer[2] == 0)
		slc->defo_color = GREEN;
	else if (buffer[0] == -30 && buffer[1] == -120 && buffer[2] == -85)
		slc->defo_color = BLUE;
	else if (buffer[0] == -30 && buffer[1] == -120 && buffer[2] == -126)
		slc->defo_color = DEFAULT;
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 51
			&& buffer[3] == 126)
		delete_onechar(slc);
	else if (buffer[0] == -61 && buffer[1] == -89 && buffer[2] == 0)
	{
		if (slc->jump != NULL)
			ft_strdel(&(slc->jump));
	}
	else if (buffer[0] == -61 && buffer[1] == -97 && buffer[2] == 0)
		search_name(slc);
	else if (ft_isprint(buffer[0]) && buffer[1] == 0)
	{
		if (slc->jump == NULL)
			slc->jump = ft_strdup(buffer);
		else if ((int)ft_strlen(slc->jump) < maxlen(slc))
			slc->jump = ft_strjoini(slc->jump, buffer, 1);
	}
}

void			task_prog(t_slc *slc, char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
		cursorup(slc);
	else if ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
			|| (buffer[0] == '\t' && buffer[1] == 0 && buffer[2] == 0))
		cursordown(slc);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
		cursorleft(slc);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		cursorright(slc);
	else if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0)
		cursordel(slc);
	else if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		cursoresc(slc);
	else if (buffer[0] == 10)
		cursorenter(slc);
	else if (buffer[0] == 32)
		cursorspace(slc);
	else if (buffer[0] == 1)
		cursorall(slc);
	else
		more_option(slc, buffer);
	clrterm();
	print_arg(slc, 0, 0, 0);
}

void			freeonearg(t_slc *slc)
{
	int			i;
	t_arg		*ptr;

	slc->nb_arg--;
	i = 0;
	ptr = slc->arg;
	while (ptr->cursor != 1)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == 0)
		slc->arg = ptr->next;
	ptr->next->prev = ptr->prev;
	ptr->prev->next = ptr->next;
	if (i == slc->nb_arg)
	{
		(slc->cursor)--;
		ptr->prev->cursor = 1;
	}
	else
		ptr->next->cursor = 1;
	free(ptr->name);
	free(ptr);
}

void			freeallarg(t_slc *slc)
{
	int		i;
	t_arg	*ptr;
	t_arg	*ptr_next;

	i = 0;
	ptr = slc->arg;
	while (i < slc->nb_arg - 1)
	{
		ptr_next = ptr->next;
		free(ptr->name);
		free(ptr);
		ptr = ptr_next;
		i++;
	}
	free(ptr->name);
	free(ptr);
}

t_slc			*slctoglb(t_slc *slc)
{
	return (slc);
}
