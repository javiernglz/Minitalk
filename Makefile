NAME_CLIENT = client
NAME_SERVER = server

OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/ft_printf.a  # Añadir la librería ft_printf.a

SRCS_CLIENT = src/client.c
SRCS_SERVER = src/server.c

OBJ_CLIENT = $(SRCS_CLIENT:src/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER = $(SRCS_SERVER:src/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR) -I$(PRINTF_DIR)  # Añadir -I$(PRINTF_DIR)

# Regla para compilar archivos fuente
$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla por defecto
all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

# Compilación de libft.a
$(LIBFT):
	make -C $(LIBFT_DIR) bonus

# Regla para compilar el cliente
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lft_printf -o $(NAME_CLIENT)

# Regla para compilar el servidor
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lft_printf -o $(NAME_SERVER)

# Limpiar objetos generados
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean  # Limpiar ft_printf

# Limpiar todo, incluidos los binarios
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean  # Limpiar ft_printf

# Volver a hacer todo
re: fclean all
