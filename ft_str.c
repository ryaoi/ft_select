/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 00:15:55 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/14 00:23:22 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int         maxlen(t_slc *slc)
{
    int     i;
    int     max;
    t_arg   *ptr;

    ptr = slc->arg;
    max = 0;
    i = 0;
    while (slc->nb_arg > i)
    {
        if ((int)ft_strlen(ptr->name) > max)
            max = ft_strlen(ptr->name);
        i++;
        ptr = ptr->next;
    }
    return (max);
}
