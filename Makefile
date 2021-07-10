NAME	= libftprintf.a
SRCS	= type_convert.c ft_printf.c func_utils.c flags_func.c ft_printf.h
BONUS	= bonus/type_convert_bonus.c bonus/ft_printf_bonus.c bonus/func_utils_bonus.c bonus/flags_func_bonus.c bonus/ft_printf_bonus.h
OBJS	= ${SRCS:.c=.o}
OBJBONUS =  ${BONUS:.c=.o}

HEADER  = includes
FOLDER 	= srcs

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
bonus:		all

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

clean:
			${RM} *.o

fclean:		clean
			${RM} ${NAME}
re : fclean all
