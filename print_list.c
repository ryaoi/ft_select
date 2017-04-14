/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 04:31:18 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/14 04:31:19 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void       print_list(t_slc *slc, int *j, int max, t_arg *ptr)
{
    ft_putstr_fd(slc->defo_color, isatty(1));
    if (ptr->select == 1)
        ft_putstr_fd(REV, isatty(1));
    if (ptr->cursor == 1)
        ft_putstr_fd(ULINE, isatty(1));
    *j = *j + max;
    if (*j > slc->row)
    {
        ft_putchar_fd('\n', isatty(1));
        *j = max;
    }
    ft_putstr_fd(ptr->name, isatty(1));
    ft_putstr_fd(RESET, isatty(1));
    ft_putspace(ft_strlen(ptr->name), max);
}

void     print_page(t_slc *slc, int lim)
{
    while (lim < slc->col - 1)
    {
        ft_putstr_fd("\n", isatty(1));
        lim++;
    }
    ft_putstr_fd("page: 1/1", isatty(1));
}
