/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:21:32 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/15 15:25:28 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <fcntl.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include "libft/libft.h"

# define DEFAULT "default"
# define DEFO	 "\033[1m"
# define YELLOW  "\033[33m"
# define GREEN   "\x1b[32m"
# define RED	 "\x1b[31m"
# define BLUE	 "\x1b[34m"
# define CYAN	 "\x1b[36m"
# define RESET   "\x1b[0m"
# define REV	 "\033[7m\033[1m"
# define ULINE	 "\033[4m\033[1m"

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
	char			*defo_color;
	int				col;
	int				row;
	int				page;
	char			*jump;
	int				cursor;
	int				total_page;
	int				index;
	t_arg			*arg;
}					t_slc;

int					init_slc(t_slc *slc);
int					reset_slc(t_slc *slc);
int					fdputc(int c);
void				init_arg(t_slc *slc, char **argv);
void				add_arg(t_arg **head, char *str);
void				handle_signal(t_slc *slc);
void				task_prog(t_slc *slc, char *buffer);
void				print_select(t_slc *slc);
void				clrterm(void);
t_slc				*slctoglb(t_slc *slc);
void				get_col(t_slc *slc);
void				print_arg(t_slc *slc, int lim_col, int lim_row,
					int all_col);
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
void				freeallarg(t_slc *slc);
int					valid_size(t_slc *slc);
int					maxlen(t_slc *slc);
void				ft_putspace(int len, int max);
void				print_all(t_slc *slc, int lim_col, int max);
void				print_onepage(t_slc *slc, int lim_col, int lim_row,
					int max);
void				default_color(t_slc *slc, t_arg *ptr);
void				index_jump(t_slc *slc);
void				search_name(t_slc *slc);
void				delete_onechar(t_slc *slc);
void				ft_sigstop(int sig);
void				ft_sigignore(int sig);
void				select_exec(t_slc slc, char *buffer);

#endif
