/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:37:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/07 18:42:58 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int argc, char **argv)
{
	t_slc	slc;
	char	buffer[3];

	if (argc < 2)
		return (ft_printf("Error: no argument\n"));
	if (init_slc(&slc) == 0)
		return (ft_printf("No env detected\n"));
	handle_signal(&slc);
	init_arg(&slc, argv);
	if (valid_size(&slc) == 1)
	{
		clrterm();
		print_arg(&slc);
	}
	while (42)
	{
		ft_bzero(buffer, 3);
		read(1, buffer, 3);
		if (valid_size(&slc) == 1)
			task_prog(&slc, buffer);
	}
	return (0);
}
