/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:01:17 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 18:32:06 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		freeonearg(t_slc *slc)
{
	int		i;
	t_arg	*ptr_prev;
	t_arg	*ptr_next;
	t_arg	*ptr;

	slc->nb_arg--;
	i = 0;
	ptr = slc->arg;
	while (ptr->cursor != 1)
	{
		ptr = ptr->next;
		i++;
	}
	ptr_next = ptr->next;
	ptr_prev = ptr->prev;
	ptr_next->prev = ptr_prev;
	ptr_prev->next = ptr_next;
	ptr_next->cursor = 1;
//	printf("gonna free :%s\n", ptr->name);
	free(ptr->name);
	free(ptr);
	if (i == 0)
		slc->arg = ptr_next;
}
