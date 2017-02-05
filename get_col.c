/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_col.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:54:00 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 19:54:02 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		get_col(t_slc *slc)
{
	int		i;
	int		max;
	t_arg	*ptr;

	i = 0;
	ptr = slc->arg;
	max = slc->arg->size;
	while (i < slc->nb_arg && ptr)
	{
		printf("i is:%d and ptr->size:%d\n", i, ptr->size);
		if (max < ptr->size)
			max = ptr->size;
		i++;
		ptr = ptr->next;
	}
	printf("finished\n");
	slc->col = max + 4;
	printf("max is:%d\n", slc->col);
}
