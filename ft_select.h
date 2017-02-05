
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

# define	UP		183
# define	DOWN	184
# define	RIGHT	185
# define	LEFT	186
# define	ESC		27
# define	SPACE	32
# define	ENTER	10

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
	int				fd;
	int				nb_arg;
	int				cursor_x;
	int				cursor_y;
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
void				handle_signal(t_slc *slc);
void				clrterm(void);
void				get_col(t_slc *slc);
void				print_arg(t_slc *slc);

#endif
