
#include "ft_select.h"

void        task_prog(t_slc *slc, char *buffer)
{
    if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
        cursorup(slc);
    else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
        cursordown(slc);
    else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
        cursorleft(slc);
    else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
        cursorright(slc);
    else if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0)
        cursordel(slc);
    else if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
            cursoresc(slc);
    else if (buffer[0] == 10)
            cursorenter(slc);
    else if (buffer[0] == 32)
            cursorspace(slc);
    else if (buffer[0] == 1)
            cursorall(slc);
	clrterm();
	print_arg(slc);
}
<<<<<<< HEAD

void		freeonearg(t_slc *slc)
{
	int     i;
	t_arg   *ptr;

	slc->nb_arg--;
	i = 0;
	ptr = slc->arg;
	while (ptr->cursor != 1)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == 0)
		slc->arg = ptr->next;
	ptr->next->prev = ptr->prev;
	ptr->prev->next = ptr->next;
	if (i == slc->nb_arg)
		ptr->prev->cursor = 1;
	else
		ptr->next->cursor = 1;
	free(ptr->name);
	free(ptr);
}
=======
>>>>>>> f78bf9a4644298ad50a319a4765bc03bb8b7ea36
