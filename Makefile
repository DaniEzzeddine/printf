C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = convert.c \
		  ft_handle_addr.c \
		  ft_handle_char.c \
		  ft_handle_int.c \
		  ft_handle_str.c \
		  ft_handle_wstr.c \
		  ft_printf.c \
		  convert_spec.c \
		  ft_handle_binary.c \
		  ft_handle_hex.c \
		  ft_handle_octal.c \
		  ft_handle_uint.c \
		  ft_parse_specifier.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
