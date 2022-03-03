CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER_NAME = server
CLIENT_NAME = client
NAME = minitalk

SRCS_PATH = ./srcs/

SRCS_SERVER = $(SRCS_PATH)server.c $(SRCS_PATH)minitalk_utils.c
SRCS_CLIENT = $(SRCS_PATH)client.c $(SRCS_PATH)minitalk_utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER_BONUS = $(SRCS_PATH)server_bonus.c $(SRCS_PATH)minitalk_utils_bonus.c
SRCS_CLIENT_BONUS = $(SRCS_PATH)client_bonus.c $(SRCS_PATH)minitalk_utils_bonus.c

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

$(NAME): server client

bonus: client_bonus server_bonus

server: $(OBJS_SERVER)
		$(CC) -o server $(CFLAGS) $(SRCS_SERVER)

server_bonus: $(OBJS_SERVER_BONUS)
		$(CC) -o server $(CFLAGS) $(SRCS_SERVER_BONUS)

client: $(OBJS_CLIENT)
		$(CC) -o client $(CFLAGS) $(SRCS_CLIENT)

client_bonus: $(OBJS_CLIENT_CLIENT)
		$(CC) -o client $(CFLAGS) $(SRCS_CLIENT_BONUS)

all: $(NAME)

clean:
		$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean: clean
		$(RM) server client minitalk

re: fclean all bonus

.PHONY: all clean fclean re