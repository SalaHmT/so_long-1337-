# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 18:08:10 by shamsate          #+#    #+#              #
#    Updated: 2023/06/24 17:51:52 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDE = -I /usr/local/include
LIBMLX = -L /usr/local/lib

CFLAGS	= -Wall -Wextra -Werror
CC = cc
RM = rm -Rf

FT_PRINTF_PATH = dependencies/src/ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF_PATH)libftprintf.a

FILES = main creator \
		dependencies/src/get_next_line/get_next_line dependencies/src/libft/ft_split \
		dependencies/src/libft/ft_strchr dependencies/src/libft/ft_strcmp \
		dependencies/src/libft/ft_strlcpy dependencies/src/libft/ft_swap \
		dependencies/src/parse_function/check_char dependencies/src/parse_function/check_dir \
		dependencies/src/parse_function/check_extent dependencies/src/parse_function/check_map_format \
		dependencies/src/parse_function/check_map dependencies/src/parse_function/check_plyr \
		dependencies/src/parse_function/check_var dependencies/src/parse_function/check_wall \
		dependencies/src/parse_function/error_map_handling dependencies/src/parse_function/get_all_colls \
		dependencies/src/parse_function/get_map dependencies/src/parse_function/get_plyr_pos \
		dependencies/src/parse_function/len_map dependencies/src/parse_function/map_free \
		dependencies/src/move_function/move_plyr dependencies/src/move_function/movement_up \
		dependencies/src/move_function/movement_down dependencies/src/move_function/movement_right \
		dependencies/src/move_function/movement_left dependencies/src/mlx_config/free_and_destro \
		dependencies/src/mlx_config/render_function dependencies/src/mlx_config/window.config \
		dependencies/src/ft_printf/ft_printf dependencies/src/get_next_line/get_next_line_utils \
		dependencies/src/libft/ft_strlen_const dependencies/src/parse_function/get_all_ext \
		dependencies/src/parse_function/get_ext_pos dependencies/src/parse_function/get_map2 \
		dependencies/src/parse_function/check_is_valid_path \

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER = include/so_long.h

#Debug
ifeq ($(DEBUG), 1)
	OPTS = -g
endif

all :  subsys $(NAME)

subsys :
	@echo "ft_printf compilation.."
	make -C $(FT_PRINTF_PATH) all

$(NAME): $(OBJ) $(HEADER)
		@echo "  - Compilation Starting $(NAME)..\n"
		@ $(CC) $(OBJ) $(INCLUDE) $(LIBMLX) $(FT_PRINTF_LIB) $(OPTS) -lmlx -framework OpenGL -framework AppKit -o  $(NAME)
		@echo " - Execution ready..\n"

%.o: %.c $(HEADER)
	@echo "- Making Object file $(notdir $@) from source file $(notdir $<)...\n"
	@ $(CC) -Wall -Wextra -Werror $(OPT) -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@echo "\n -Removing object file ..\n"
	@echo "-Object file Removed..\n"

fclean: clean
	@ $(RM) $(NAME)
	@echo "-Removing $(NAME) ..\n"
	@echo " Removed..\n"

re: fclean clean

.PHONY: all clean fclean re