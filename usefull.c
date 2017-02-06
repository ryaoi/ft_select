
#include "ft_select.h"

void				get_col(t_slc *slc)
{
	int				i;
	int				max;
	t_arg			*ptr;

	i = 0;
	ptr = slc->arg;
	max = slc->arg->size;
	while (i < slc->nb_arg && ptr)
	{
		if (max < ptr->size)
			max = ptr->size;
		i++;
		ptr = ptr->next;
	}
	slc->col = max + 4;
}

int					valid_size(t_slc *slc)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	clrterm();
	if (slc->col > win.ws_col || slc->row + 2> win.ws_row)
	{
		ft_printf("Error term\nsize\n");
		return (0);
	}
	return (1);
}

void				print_arg(t_slc *slc)
{
	int				i;
	t_arg			*ptr;

	i = 0;
	ptr = slc->arg;
	while (i < slc->nb_arg)
	{
		ft_putstr(GREEN);
		if (ptr->select == 1)
			ft_putstr(REV);
		if (ptr->cursor == 1)
			ft_putstr(ULINE);
		ft_putstr(ptr->name);
		ft_putstr(RESET);
		if (ptr->cursor == 1)
			ft_putstr(" <-");
		ft_putchar('\n');
		ptr = ptr->next;
		i++;
	}
}
