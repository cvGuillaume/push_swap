NAME	= push_swap
CC		= @gcc
CFLAGS	= -Wall -Wextra -Werror -g
LIBS	= libft/libft.a
INC		= -I include

SRCS	=	srcs/push_swap.c		\
				srcs/print.c		\
				srcs/radix_sort.c	\
				srcs/sort_5_less.c	\
				srcs/sort_5_75.c	\
				srcs/init.c			\
				srcs/utils.c		\
				srcs/utils2.c		\
				srcs/utils3.c		\
				srcs/utils4.c		\
				srcs/operations.c	\
				srcs/operations2.c	\
				srcs/operations3.c

OBJS = 			${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c ${INC} $< -o ${<:.c=.o}

${NAME}: ${LIBS} ${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${OBJS} ${LIBS}

${LIBS}:
	@make all -C libft

all: ${NAME}

clean:
	@rm -rf ${OBJS}
	@make clean -C libft

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${LIBS}
	@make fclean -C libft
re: fclean all

.PHONY: all clean fclean re
