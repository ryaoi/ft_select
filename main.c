/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:37:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 20:28:16 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		clrterm(void)
{
	tputs(tgetstr("cl", NULL), 1, fdputc);
}

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
//		printf("buff[0]:%d buff[1]:%d buff[2]:%d\n", buffer[0], buffer[1], buffer[2]);
//		printf("win-size_x:%d and win-size_y:%d\n", slc.term_col, slc.term_row);
//		printf("arg-size_x:%d and arg-size_y:%d\n", slc.col, slc.row);
		if (valid_size(&slc) == 1)
			task_prog(&slc, buffer);
	}
	return (0);
}
