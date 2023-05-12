SRCS    =	ft_invert_first.c \
				ft_push.c \
				ft_reverse_rotate.c \
				ft_rotate.c \
				ft_set_lst.c \
				ft_utils.c \
				push_swap.c \
				19_libft/ft_atoi.c \
				19_libft/ft_bzero.c \
				19_libft/ft_calloc.c \
				19_libft/ft_isalnum.c \
				19_libft/ft_isalpha.c \
				19_libft/ft_isascii.c \
				19_libft/ft_isdigit.c \
				19_libft/ft_isprint.c \
				19_libft/ft_itoa.c \
				19_libft/ft_lstadd_back_bonus.c \
				19_libft/ft_lstadd_front_bonus.c \
				19_libft/ft_lstlast_bonus.c \
				19_libft/ft_lstnew_bonus.c \
				19_libft/ft_lstsize_bonus.c \
				19_libft/ft_memchr.c \
				19_libft/ft_memcmp.c \
				19_libft/ft_memcpy.c \
				19_libft/ft_memmove.c \
				19_libft/ft_memset.c \
				19_libft/ft_putchar_fd.c \
				19_libft/ft_putendl_fd.c \
				19_libft/ft_putnbr_fd.c \
				19_libft/ft_putstr_fd.c \
				19_libft/ft_split.c \
				19_libft/ft_strchr.c \
				19_libft/ft_strdup.c \
				19_libft/ft_striteri.c \
				19_libft/ft_strjoin.c \
				19_libft/ft_strlcat.c \
				19_libft/ft_strlcpy.c \
				19_libft/ft_strlen.c \
				19_libft/ft_strmapi.c \
				19_libft/ft_strncmp.c \
				19_libft/ft_strnstr.c \
				19_libft/ft_strrchr.c \
				19_libft/ft_strtrim.c \
				19_libft/ft_substr.c \
				19_libft/ft_tolower.c \
				19_libft/ft_toupper.c \
				printf/ft_printf.c \
				printf/ft_utils.c \
				ft_split.c \
				ft_end.c \
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
	${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

compile:
	${CC} -fsanitize=address -g ${CFLAGS} -o ${NAME} ${SRCS} ${c} && ./push_swap 2 1 3 8 5 6 18 7 123 19 55 0 164 78 22

c:
	${RM} *.o printf/*.o 19_libft/*.o

C:
	${RM} ${c} push_swap push_swap.dSYM


re: fclean all

.PHONY: all clean fclean compile c C re