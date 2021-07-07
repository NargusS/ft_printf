NAME	= libftprintf.a
SRCS	= type_convert.c ft_printf.c func_utils.c flags_func.c libftprintf.h
OBJS	= ${SRCS:.c=.o}

HEADER  = includes
FOLDER 	= srcs

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
bonus:		${OBJBONUS}
			ar -rcs ${NAME} ${OBJBONUS}
%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

clean:
			${RM} *.o

fclean:		clean
			${RM} ${NAME}
re : fclean all