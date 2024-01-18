# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:45:00 by mmezyan           #+#    #+#              #
#    Updated: 2024/01/18 14:34:01 by mmezyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCM	= push_swap.c parsing.c tstack_utils.c tstack_utils2.c stack_utils.c small_sort.c small_sort_utils.c long_sort.c long_sort_utils.c stack_utils1.c stack_utils2.c tstack_utils1.c
OBJM	= ${SRCM:.c=.o}
BONUS_S = checker.c ./includes/get_next_line/get_next_line.c ./includes/get_next_line/get_next_line_utils.c stack_utils.c stack_utils1.c stack_utils2.c parsing.c tstack_utils.c tstack_utils2.c checker_utils.c tstack_utils1.c
BONUS_O = ${BONUS_S:.c=.o}

NAME = push_swap

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address 
CC		= cc
LIBFTA 	= ./includes/libft/libft.a

all : ${NAME}

${LIBFTA} : 
	make -C includes/libft

${NAME} : ${OBJM} ${LIBFTA}
	${CC} ${CFLAGS} ${OBJM} ${LIBFTA} -o ${NAME}
	
bonus : ${BONUS_O} ${LIBFTA}
	${CC} ${CFLAGS} ${BONUS_O} ${LIBFTA} -o checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -f ${OBJM} ${BONUS_O}
	make clean -C ./includes/libft

fclean : clean
	rm -f ${NAME} ${BONUS_O} checker
	make fclean -C ./includes/libft

re : fclean all
	make re -C ./includes/libft
	

run :  
	./push_swap 42 140 61 52 104 45 71 55 9 

#make status arg="4 5 2"
status : 
	./push_swap $(arg) | ./checker_Mac $(arg)


#make count arg="34 2 1"
count : 
	./push_swap $(arg) | wc -l
