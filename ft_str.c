/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 00:15:55 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/17 00:52:53 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			maxlen(t_slc *slc)
{
	int		i;
	int		max;
	t_arg	*ptr;

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

void		default_color(t_slc *slc, t_arg *ptr)
{
	struct stat	fs;

	if (lstat(ptr->name, &fs) < 0)
	{
		if (ft_strcmp(slc->defo_color, DEFAULT) == 0)
			ft_putstr_fd(YELLOW, isatty(1));
		else
			ft_putstr_fd(slc->defo_color, isatty(1));
		return ;
	}
	if (ft_strcmp(slc->defo_color, "default") == 0)
	{
		if (S_ISLNK(fs.st_mode))
			ft_putstr_fd(CYAN, isatty(1));
		else if (S_ISDIR(fs.st_mode))
			ft_putstr_fd(RED, isatty(1));
		else if (access(ptr->name, X_OK))
			ft_putstr_fd(RESET, isatty(1));
		else
			ft_putstr_fd(GREEN, isatty(1));
	}
	else
		ft_putstr_fd(slc->defo_color, isatty(1));
}
