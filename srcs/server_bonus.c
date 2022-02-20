#include "../includes/minitalk_bonus.h"

t_signal	g_signal;

static void	print_pid(void)
{
	ft_putstr_fd("pid:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_signal.ans += (0b100000000 >> g_signal.shift_num);
	if (g_signal.shift_num == 1)
	{
		ft_putchar_fd(g_signal.ans, STDOUT_FILENO);
		g_signal.ans = 0;
		g_signal.shift_num = 8;
		return ;
	}
	g_signal.shift_num--;
}

int	main(void)
{
	g_signal.ans = 0;
	g_signal.shift_num = 8;
	print_pid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
