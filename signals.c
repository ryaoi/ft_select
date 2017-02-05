
#include "ft_select.h"

void		quit_prog(int signal, t_slc *slc)
{
	if (signal == SIGINT)
	{
		end_prog(slc);
		exit(0);
	}
}

void		move_cursor(int signal)
{
		
}

void		check_signal(void)
{
	signal(SIGINT, quit_prog);
	signal(SIGWINCH, move_cursor);
}
