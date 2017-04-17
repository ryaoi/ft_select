/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:22:51 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/17 04:27:53 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_slc			*g_slc;

static void		ft_sigint(int sig)
{
	(void)sig;
	reset_slc(g_slc);
	exit(0);
}

static void		ft_sigcont(int sig)
{
	(void)sig;
	g_slc->term.c_lflag &= ~(ICANON | ECHO);
	g_slc->term.c_cc[VMIN] = 1;
	g_slc->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(g_slc->term));
	tputs(tgetstr("ti", NULL), 0, fdputc);
	tputs(tgetstr("vi", NULL), 0, fdputc);
	if (valid_size(g_slc) == 1)
		print_arg(g_slc, 0, 0, 0);
}

static void		ft_sigstop(int sig)
{
	(void)sig;
	g_slc->term.c_lflag |= (ICANON | ECHO);
	clrterm();
	tcsetattr(0, 0, &(g_slc->term));
	tputs(tgetstr("te", NULL), 0, fdputc);
	tputs(tgetstr("ve", NULL), 0, fdputc);
}

static void		ft_sigwinch(int sig)
{
	struct winsize	win;

	(void)sig;
	ioctl(0, TIOCGWINSZ, &win);
	g_slc->row = win.ws_col;
	g_slc->col = win.ws_row;
	if (valid_size(g_slc) == 1)
		print_arg(g_slc, 0, 0, 0);
}

void			handle_signal(t_slc *slc)
{
	g_slc = slctoglb(slc);
	signal(SIGCONT, ft_sigcont);
	signal(SIGSTOP, ft_sigstop);
	signal(SIGINT, ft_sigint);
	signal(SIGWINCH, ft_sigwinch);
}
