/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:22:51 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/15 15:55:28 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_slc			*g_slc;

static void		ft_sigint(int sig)
{
	(void)sig;
	freeallarg(g_slc);
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
	tputs(tgetstr("ti", NULL), 1, fdputc);
	tputs(tgetstr("vi", NULL), 1, fdputc);
	handle_signal(g_slc);
	if (valid_size(g_slc) == 1)
		print_arg(g_slc, 0, 0, 0);
}

void			ft_sigstop(int sig)
{
	char		cp[2];

	(void)sig;
	handle_signal(g_slc);
	if (isatty(1))
	{
		cp[0] = g_slc->term.c_cc[VSUSP];
		cp[1] = 0;
		ioctl(0, TIOCSTI, cp);
		g_slc->term.c_lflag |= (ICANON | ECHO);
		tcsetattr(0, 0, &(g_slc->term));
		tputs(tgetstr("ve", NULL), 1, fdputc);
		signal(SIGTSTP, SIG_DFL);
		tputs(tgetstr("te", NULL), 1, fdputc);
	}
}

static void		ft_sigwinch(int sig)
{
	struct winsize	win;

	(void)sig;
	usleep(2000);
	ioctl(0, TIOCGWINSZ, &win);
	g_slc->row = win.ws_col;
	g_slc->col = win.ws_row;
	if (valid_size(g_slc) == 1)
		print_arg(g_slc, 0, 0, 0);
}

void			handle_signal(t_slc *slc)
{
	int				i;

	i = 1;
	g_slc = slctoglb(slc);
	while (i < 65)
	{
		if (i == SIGCONT)
			signal(SIGCONT, ft_sigcont);
		else if (i == SIGTSTP)
			signal(SIGTSTP, ft_sigstop);
		else if (i == SIGINT)
			signal(SIGINT, ft_sigint);
		else if (i == SIGWINCH)
			signal(SIGWINCH, ft_sigwinch);
		else
			signal(i, ft_sigignore);
		i++;
	}
}
