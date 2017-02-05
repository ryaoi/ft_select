/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:12:29 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 20:45:37 by ryaoi            ###   ########.fr       */
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
		if (ptr->select == 1)
			ft_putstr(REV);
			ft_putstr(GREEN);
		if (ptr->cursor == 1)
			ft_putstr(ULINE);
		ft_putstr(ptr->name);
		ft_putstr(RESET);
		if (ptr->cursor == 1)
			ft_putstr(" <-");
		ft_putchar('\n');
		ptr = ptr->next;
		i++;
	}
}
