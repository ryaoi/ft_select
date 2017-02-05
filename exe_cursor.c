/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:43:18 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 18:44:36 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			cursordel(t_slc *slc)
{
	if (slc->nb_arg == 1)
		cursoresc(slc);
	freeonearg(slc);
}

void		cursoresc(t_slc *slc)
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
	if (reset_slc(slc) == 0)
		exit (EXIT_FAILURE);
	exit (0);
}
