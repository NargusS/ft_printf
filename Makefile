NAME	= libftprintf.a
SRCS	= type_int_conv.c type_hex_conv.c type_char_conv.c ft_printf.c func_utils.c flags_func.c ft_printf.h
BONUS	= type_int_conv_bonus.c type_hex_conv_bonus.c type_char_conv_bonus.c ft_printf_bonus.c func_utils_bonus.c \
		flags_func_bonus.c ft_printf_bonus.h
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
bonus:		${OBJBONUS}
			ar -rcs ${NAME} ${OBJBONUS}
%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}
clean:
			${RM} *.o
fclean:		clean
			${RM} ${NAME}
re : fclean all
