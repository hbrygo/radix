SRCS    =	ft_invert_first.c \
				ft_push.c \
				ft_reverse_rotate.c \
				ft_rotate.c \
				ft_set_lst.c \
				ft_utils.c \
				ft_atoi.c \
				ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c \
				printf/ft_printf.c \
				printf/ft_utils.c \
				ft_split.c \
				ft_small_sort.c \
				main.c
OBJS    = ${SRCS:.c=.o}
INCS    = includes
NAME    = push_swap
CC        = gcc
RM        = rm -rf
CFLAGS    = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

compile:
	${CC} -fsanitize=address -g ${CFLAGS} -o ${NAME} ${SRCS} ${c} && ./push_swap 1 2 3

c:
	${RM} *.o printf/*.o 19_libft/*.o

C:
	${RM} ${c} push_swap push_swap.dSYM


re: fclean all

.PHONY: all clean fclean compile c C re