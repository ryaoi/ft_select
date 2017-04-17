/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:37:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/17 03:40:18 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int argc, char **argv)
{
	t_slc	slc;
	char	buffer[4];

	if (argc < 2)
		return (ft_printf("Error: no argument\n"));
	if (init_slc(&slc) == 0)
		return (ft_printf("No env detected\n"));
	handle_signal(&slc);
	init_arg(&slc, argv);
	if (valid_size(&slc) == 1)
	{
		clrterm();
		print_arg(&slc, 0, 0, 0);
	}
	while (42)
	{
		ft_bzero(buffer, 4);
		read(isatty(1), buffer, 4);
		if (valid_size(&slc) == 1)
			task_prog(&slc, buffer);
	}
	return (0);
}
