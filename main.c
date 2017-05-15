/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:37:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/15 15:27:59 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		select_exec(t_slc slc, char *buffer)
{
	if (valid_size(&slc) == 1)
	{
		clrterm();
		print_arg(&slc, 0, 0, 0);
	}
	while (42)
	{
		handle_signal(&slc);
		ft_bzero(buffer, 4);
		read(isatty(1), buffer, 4);
		if (valid_size(&slc) == 1)
			task_prog(&slc, buffer);
	}
}

int			main(int argc, char **argv)
{
	t_slc	slc;
	char	buffer[4];

	if (argc < 2)
		return (ft_printf("Error: no argument\n"));
	if (init_slc(&slc) == 0)
		return (ft_printf("Error: couldn't detect env-variable TERM\n"));
	init_arg(&slc, argv);
	select_exec(slc, buffer);
	return (0);
}

void		ft_sigignore(int sig)
{
	(void)sig;
}
