#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_signal
{
	int	shift_num;
	int	ans;
}	t_signal;

/* minitalk_utils.c */
size_t	ft_strlen(char *str);
int		ft_putchar_fd(int c, char fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
int		ft_atoi(const char *str);

#endif