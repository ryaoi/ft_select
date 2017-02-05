
#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <fcntl.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft/libft.h"

# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"
# define REV	 "\033[7m"
# define ULINE	 "\033[4m"

typedef struct		s_arg
{
	char			*name;
	int				size;
	int				select;
	int				cursor;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

typedef struct		s_slc
{
	struct termios	term;
	int				print_arg;
	int				nb_arg;
	int				col;
	int				row;
	int				term_col;
	int				term_row;
	t_arg			*arg;
}					t_slc;

int					init_slc(t_slc *slc);
int					reset_slc(t_slc *slc);
int					fdputc(int c);
void				init_arg(t_slc *slc, char **argv);
void				add_arg(t_arg **head, char *str);
void				handle_signal(t_slc *slc);
void				clrterm(void);
void				get_col(t_slc *slc);
void				print_arg(t_slc *slc);
void				cursorup(t_slc *slc);
void				cursordown(t_slc *slc);
void				cursorleft(t_slc *slc);
void				cursorright(t_slc *slc);
void				cursordel(t_slc *slc);
void				cursoresc(t_slc *slc);
void				cursorspace(t_slc *slc);
void				cursorall(t_slc *slc);
void				cursorenter(t_slc *slc);
void				freeonearg(t_slc *slc);

#endif
