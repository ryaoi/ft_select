
#include "ft_select.h"

	t_slc		*glb_slc;


static void		slctoglb(t_slc *slc)
{
	glb_slc = slc;
}

void			term_size(void)
{
	struct winsize win;

	clrterm();
	ioctl(0, TIOCGWINSZ, &win);
	glb_slc->term_col = win.ws_col;
	glb_slc->term_row = win.ws_row;
}

static void		ft_sigint(int sig)
{
	(void)sig;
	reset_slc(glb_slc);
	exit(0);
}

static void		ft_sigcont(int sig)
{
	(void)sig;
}


static void		ft_sigstop(int sig)
{
	(void)sig;
}

static void		ft_sigwinch(int sig)
{
	(void)sig;
	term_size();
}


void			handle_signal(t_slc *slc)
{
	slctoglb(slc);
	signal(SIGCONT, ft_sigcont);
	signal(SIGSTOP, ft_sigstop);
	signal(SIGINT, ft_sigint);
	signal(SIGWINCH, ft_sigwinch);
}
