/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:37:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 18:38:56 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

int			main(int argc, char **argv, char **envp)
{
	t_slc	slc;
	char	buffer[3];
	
	if (argc < 2)
		return (ft_printf("Error: no argument\n"));
	if (init_slc(&slc) == 0)
		printf("error init_slc\n");
	handle_signal(&slc);
	init_arg(&slc, argv);
	clrterm();
	print_arg(&slc);
	while (42)
	{
		ft_bzero(buffer, 3);
		read(1, buffer, 3);
		printf("buff[0]:%d buff[1]:%d buff[2]:%d\n", buffer[0], buffer[1], buffer[2]);
		printf("win-size_x:%d and win-size_y:%d\n", slc.term_col, slc.term_row);
		printf("arg-size_x:%d and arg-size_y:%d\n", slc.col, slc.row);
		if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
		{
			cursorup(&slc);
			clrterm();
			print_arg(&slc);
		}
		else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
		{
			cursordown(&slc);
			clrterm();
			print_arg(&slc);
		}
        else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
		{
			cursorleft(&slc);
			clrterm();
			print_arg(&slc);
		}
        else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		{	
			cursorright(&slc);
			clrterm();
			print_arg(&slc);
		}
		else if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0)
		{
			cursordel(&slc);
			clrterm();
			print_arg(&slc);
		}
		else if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		{
			cursoresc(&slc);
			clrterm();
			print_arg(&slc);
		}
		else if (buffer[0] == 10)
		{
			//enter
		}
		else if (buffer[0] == 32)
		{
			//space
		}
	}
	if (reset_slc(&slc) == 0)
//		printf("reset failed\n");
	printf("reset ended\n");
//	add_arg(&slc);
	return (0);
}
