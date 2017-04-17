/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 00:15:55 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/17 04:28:51 by ryaoi            ###   ########.fr       */
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

void		delete_onechar(t_slc *slc)
{
	char	*tmp;

	if (slc->jump == NULL)
		return ;
	if (ft_strlen(slc->jump) == 1)
	{
		ft_strdel(&slc->jump);
		return ;
	}
	tmp = ft_strsub(slc->jump, 0, ft_strlen(slc->jump) - 1);
	ft_strdel(&slc->jump);
	slc->jump = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void		search_name(t_slc *slc)
{
	t_arg	*ptr;
	t_arg	*ptr2;
	int		counter;

	if (slc->jump == NULL)
		return ;
	ptr = slc->arg;
	counter = 1;
	while (counter <= slc->nb_arg)
	{
		if (ft_strncmp(ptr->name, slc->jump, ft_strlen(slc->jump)) == 0)
		{
			slc->cursor = counter;
			ptr2 = slc->arg;
			while (ptr2->cursor != 1)
				ptr2 = ptr2->next;
			ptr2->cursor = 0;
			ptr->cursor = 1;
			ft_strdel(&slc->jump);
			return ;
		}
		counter++;
		ptr = ptr->next;
	}
	ft_strdel(&slc->jump);
}

void		index_jump(t_slc *slc)
{
	ft_putstr_fd("search:", isatty(1));
	if (slc->jump != NULL)
	{
		ft_putstr_fd(slc->jump, isatty(1));
	}
	ft_putstr_fd("\n", isatty(1));
}
