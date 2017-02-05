/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:01:17 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 19:34:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		freeonearg(t_slc *slc)
{
	int		i;
	t_arg	*ptr;

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
		ptr->prev->cursor = 1;
	else
		ptr->next->cursor = 1;
	free(ptr->name);
	free(ptr);
}
