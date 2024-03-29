# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 15:07:02 by afoulqui          #+#    #+#              #
#    Updated: 2021/06/15 15:51:10 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#     VARIABLES     #
# ----------------- #

BONUS		=	checker

NAME		=	push_swap

LIB_DIR		=	libft
LIBFT		=	$(LIB_DIR)/libft.a

SRC_CHECKER =	checker.c \
				display.c \
				exec_cmd.c

SRC_PS		=	push_swap.c \
				sort_5.c \
				sort_500.c \
				find_min_max.c \
				median.c \
				split.c \
				utils.c

SRC_SHARED	=	parse_args.c \
				utils_stack.c \
				is_sorted.c

SRC_OP		=	push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c

C_SRC_LST	=	$(SRC_CHECKER) $(SRC_SHARED) $(SRC_OP)
PS_SRC_LST	=	$(SRC_PS) $(SRC_SHARED) $(SRC_OP)

SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d) $(LIB_DIR)/includes

OBJ_DIR		=	objs/

LIB			=	ft
C_SRC		=	$(foreach dir, $(SRC_DIR), $(C_SRC_LST))
PS_SRC		=	$(foreach dir, $(SRC_DIR), $(PS_SRC_LST))
C_OBJ		=	$(addprefix $(OBJ_DIR),$(C_SRC_LST:%.c=%.o))
PS_OBJ		=	$(addprefix $(OBJ_DIR),$(PS_SRC_LST:%.c=%.o))
HEADERS		=	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))


vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#    COMPILATION    #
# ----------------- #

CC		=	gcc

CFLAG	=	-Wall -Werror -Wextra
IFLAG	=	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) ) 

# ----------------- #
#     FUNCTIONS     #
# ----------------- #

$(OBJ_DIR)%.o:%.c $(HEADERS)		
				@mkdir -p $(OBJ_DIR)
				@echo "\033[32mCompilation ... $(foreach file, $< , $(notdir $<))"
				@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<

$(NAME):	install $(PS_OBJ)
					@$(CC) $(CFLAG) $(PS_OBJ) $(IFLAG) $(LFLAG) -o $@
					@echo "\n\t\033[36;1m*.............................*"
					@echo "\n\t*    Compilation $(NAME)    *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
					@echo "\n\t\033[036;1m*.............................*\033[0m\n"				

$(BONUS):	install $(C_OBJ)
				@$(CC) $(CFLAG) $(C_OBJ) $(IFLAG) $(LFLAG) -o $@
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*    Compilation $(BONUS)    *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

all	:		$(NAME)

bonus :		$(NAME) $(BONUS)

install :	
				@make -C $(LIB_DIR)

re-install :
				@make -C $(LIB_DIR) re

# ----------------- #
#       CLEAN       #
# ----------------- #

RM		=	rm -rf

clean:	
			@$(RM) $(OBJ_DIR)
			@echo "\033[36;1m $(NAME) ------>>  clean\033[0m\n"
			@echo "\033[36;1m $(BONUS) ------>>  clean\033[0m\n"

fclean:		clean
			@$(RM) $(NAME) $(BONUS)
			@make fclean -C $(LIB_DIR)
			@echo "\033[36;1m $(NAME) ------>>  fclean\033[0m\n"
			@echo "\033[36;1m $(BONUS) ------>>  fclean\033[0m\n"

re:			fclean all

re-bonus:	fclean bonus

.PHONY:		all clean fclean re re-bonus
