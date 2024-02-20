# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 17:00:40 by rboutaik          #+#    #+#              #
#    Updated: 2024/02/04 00:20:29 by rboutaik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -O3

NAME = fractol

BNAME = fractol_bonus

MPATH = ./mindatory/

BPATH = ./bonus/

CFILES = $(MPATH)fractol.c $(MPATH)fractol_utils_1.c $(MPATH)fractol_utils_2.c $(MPATH)fractol_events.c

BFILES = $(BPATH)fractol_bonus.c $(BPATH)fractol_utils_1_bonus.c $(BPATH)fractol_utils_2_bonus.c $(BPATH)fractol_events_bonus.c

OFILES = $(CFILES:.c=.o)

BOFILES = $(BFILES:.c=.o)

all : $(NAME)
	@echo "\x1b[32m============================="
	@echo "=        All Done ✅        ="
	@echo "=============================\x1b[0m"

$(NAME) : $(OFILES) $(MPATH)fractol.h
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $@

$(MPATH)%.o : $(MPATH)%.c $(MPATH)fractol.h
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ...\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@$(CC) $(FLAGS) -Imlx -c $< -o $@
	@echo "\x1b[32mCompilation successful! 🚀\x1b[0m"
	
bonus : $(BNAME)
	@echo "\x1b[32m============================="
	@echo "=        All Done ✅        ="
	@echo "=============================\x1b[0m"

$(BNAME) : $(BOFILES) $(BPATH)fractol_bonus.h
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(BOFILES) -o $@

$(BPATH)%.o : $(BPATH)%.c $(BPATH)fractol_bonus.h
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ...\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@$(CC) $(FLAGS) -Imlx -c $< -o $@
	@echo "\x1b[32mCompilation successful! 🚀\x1b[0m"

clean :
	@echo "\x1b[33mCleaning up.\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up..\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up...\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up.\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up..\x1b[0m"
	@sleep 0.2
	@rm -f $(OFILES) $(BOFILES)
	@echo "\x1b[32mCleanup complete! 🧹\x1b[0m"

fclean : clean
	@rm -f $(NAME) $(BNAME)

re : fclean all