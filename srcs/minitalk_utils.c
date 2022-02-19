#include "../includes/minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_fd(int c, char fd)
{
	write(fd, &c, 1);
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	ssize_t	i;

	if (str == NULL)
		return ;
	i = write(fd, str, ft_strlen(str));
	if (i == -1)
		return ;
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == INT_MIN)
		ft_putstr_fd("-2147483648", fd);
	else if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		minus_flag;
	long	number;

	i = 0;
	minus_flag = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		minus_flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	number = 0;
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * minus_flag);
}
