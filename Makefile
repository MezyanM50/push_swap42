# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:45:00 by mmezyan           #+#    #+#              #
#    Updated: 2024/01/15 14:45:02 by mmezyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCM	= push_swap.c parsing.c tstack_utils.c tstack_utils2.c stack_utils.c small_sort.c small_sort_utils.c long_sort.c long_sort_utils.c stack_utils1.c stack_utils2.c
OBJM	= ${SRCM:.c=.o}

NAME = push_swap

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address 
CC		= cc
LIBFTA 	= ./includes/libft/libft.a

all : ${NAME}

${LIBFTA} : 
	make -C includes/libft

${NAME} : ${OBJM} ${LIBFTA}
	${CC} ${CFLAGS} ${OBJM} ${LIBFTA} -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -f ${OBJM}
	make clean -C ./includes/libft

fclean : clean
	rm -f ${NAME}
	rm -f ${OBJM}
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
