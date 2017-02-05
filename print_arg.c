
#include "ft_select.h"

void			print_arg(t_slc *slc)
{
	int		i;
	t_arg	*ptr;
	
	i = 0;
	ptr = slc->arg;
	while (i < slc->nb_arg)
	{
		ft_putendl_fd(ptr->name, 2);
		ptr = ptr->next;
		i++;
	}
}
