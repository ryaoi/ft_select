/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:12:29 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 17:12:31 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			print_arg(t_slc *slc)
{
	int		i;
	t_arg	*ptr;
	
	i = 0;
	ptr = slc->arg;
	while (i < slc->nb_arg)
	{
		ft_putstr_fd(ptr->name, 2);
		if (ptr->cursor == 1)
			ft_putendl_fd(" <- ", 2);
		else
			ft_putchar('\n');
		ptr = ptr->next;
		i++;
	}
}
