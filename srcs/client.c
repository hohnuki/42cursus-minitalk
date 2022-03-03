#include "../includes/minitalk.h"

static void	error_message(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	validete_config(int argc, char **argv)
{
	if (argc != 3)
		error_message("invalid argument\n");
	if (ft_strlen(argv[1]) >= 12)
		error_message("argv[1] is too long\n");
}

static void	send_message(pid_t pid, char *message)
{
	int	i;
	int	shift_num;
	int	kill_ret;

	i = 0;
	while (message[i] != '\0')
	{
		shift_num = 0;
		while (shift_num < 8)
		{
			usleep(110);
			if (((message[i] >> shift_num) & 0b00000001) == 1)
				kill_ret = kill(pid, SIGUSR1);
			else
				kill_ret = kill(pid, SIGUSR2);
			if (kill_ret == -1)
				error_message("kill failure\n");
			shift_num++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	validete_config(argc, argv);
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		error_message("invalid pid\n");
	send_message(pid, argv[2]);
	return (0);
}
