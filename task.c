
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
