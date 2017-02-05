/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_slc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:15:17 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/05 20:24:29 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int         fdputc(int c)
{
    write(2, &c, 1);
    return (1);
}

int				init_slc(t_slc *slc)
{
	struct winsize	win;

	if ((tgetent(NULL, getenv("TERM")) != 1))
		return (0);
	tcgetattr(0, &slc->term);
	(slc)->term.c_lflag &= ~ICANON;
	(slc)->term.c_lflag &= ~ECHO;
	(slc)->term.c_cc[VMIN] = 1;
	(slc)->term.c_cc[VTIME] = 0;
	(slc)->print_arg = 0;
	ioctl(0, TIOCGWINSZ, &win);
	slc->term_col = win.ws_col;
	slc->term_row = win.ws_row;
	if (tcsetattr(0, 0, &slc->term) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, fdputc);
	tputs(tgetstr("vi", NULL), 1, fdputc);
	return (1);
}

int				reset_slc(t_slc *slc)
{
	(slc)->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &slc->term) == -1)
		return (1);
	tputs(tgetstr("ve", NULL), 1, fdputc);
	tputs(tgetstr("te", NULL), 1, fdputc);
	return (1);
}
