CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_PATH = ./srcs/

all : server client

bonus : client_bonus server_bonus

server : $(SRCS_PATH)server.c $(SRCS_PATH)minitalk_utils.c
		$(CC) -o server $(CFLAGS) $(SRCS_PATH)server.c $(SRCS_PATH)minitalk_utils.c

server_bonus : $(SRCS_PATH)server_bonus.c $(SRCS_PATH)minitalk_utils_bonus.c
				$(CC) -o server_bonus $(CFLAGS) $(SRCS_PATH)server_bonus.c $(SRCS_PATH)minitalk_utils_bonus.c

client : $(SRCS_PATH)client.c $(SRCS_PATH)minitalk_utils.c
		$(CC) -o client $(CFLAGS) $(SRCS_PATH)client.c $(SRCS_PATH)minitalk_utils.c

client_bonus : $(SRCS_PATH)client_bonus.c $(SRCS_PATH)minitalk_utils_bonus.c
				$(CC) -o client_bonus $(CFLAGS) $(SRCS_PATH)client_bonus.c $(SRCS_PATH)minitalk_utils_bonus.c

clean :
		$(RM) $(SRCS_PATH)server.o $(SRCS_PATH)client.o $(SRCS_PATH)minitalk_utils.o $(SRCS_PATH)minitalk_utils_bonus.o $(SRCS_PATH)client_bonus.o $(SRCS_PATH)server_bonus.o

fclean : clean
		$(RM) server client client_bonus server_bonus

re : fclean all bonus

.PHONY : all clean fclean re