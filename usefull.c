
#include "ft_select.h"

void	clrterm(void)
{
	tputs(tgetstr("cl", NULL), 1, fdputc);
}
