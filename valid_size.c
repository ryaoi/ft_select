
#include "ft_select.h"

int					valid_size(t_slc *slc)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	printf("slc->col:%d\t slc->row:%d\t wincol:%d\t winrow:%d\n", slc->col, slc->row, win.ws_col, win.ws_row);
	if (slc->col > win.ws_col || slc->row + 2> win.ws_row)
	{
		ft_printf("Error term\nsize\n");
		return (0);
	}
	return (1);
}
