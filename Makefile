NAME = server
NAME_C = client

NAME_BONUS = server_bonus
NAME_C_BONUS = client_bonus
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_PATH = libft
LIBFT_A = $(LIBFT_PATH)/libft.a

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c

all: $(LIBFT_A) server client

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_PATH)

server: $(LIBFT_A) $(SRC_SERVER)
	@cc $(CFLAGS) -o $(NAME) $(SRC_SERVER) $(LIBFT_A)
	@echo "\n Server executable created \n"

client: $(LIBFT_A) $(SRC_CLIENT)
	@cc $(CFLAGS) -o $(NAME_C) $(SRC_CLIENT) $(LIBFT_A)
	@echo "\n Client executable created \n"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(NAME_C) $(NAME_BONUS) $(NAME_C_BONUS)

re: fclean all

.phony: all bonus clean fclean re