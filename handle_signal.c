
#include "ft_select.h"

	t_slc		*glb_slc;


static void		slctoglb(t_slc *slc)
{
	glb_slc = slc;
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

	glb_slc->term.c_lflag &= ~(ICANON | ECHO);
	glb_slc->term.c_cc[VMIN] = 1;
	glb_slc->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(glb_slc->term));
	tputs(tgetstr("ti", NULL), 1, fdputc);
	tputs(tgetstr("vi", NULL), 1, fdputc);
	if (valid_size(glb_slc) == 1)
		print_arg(glb_slc);
}


static void		ft_sigstop(int sig)
{
	(void)sig;
	char	cp[2];

	cp[0] = glb_slc->term.c_cc[VSUSP];
	cp[1] = 0;
	glb_slc->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	clrterm();
	tcsetattr(0, 0, &(glb_slc->term));
	tputs(tgetstr("te", NULL), 1, fdputc);
	tputs(tgetstr("ve", NULL), 1, fdputc);
	ioctl(0, TIOCSTI, cp);
}

static void		ft_sigwinch(int sig)
{
	(void)sig;
	if (valid_size(glb_slc) == 1)
		print_arg(glb_slc);
}


void			handle_signal(t_slc *slc)
{
	slctoglb(slc);
	signal(SIGCONT, ft_sigcont);
	signal(SIGSTOP, ft_sigstop);
	signal(SIGINT, ft_sigint);
	signal(SIGWINCH, ft_sigwinch);
}
