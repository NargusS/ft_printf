#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		width;
	int		space;
	int		pos_sign;
	int		sharp;
	int		type_conv;
	int		char_count;
	int		error;
}				t_flags;

int		ft_printf(const char *str, ...);
void	*parsing(const char *str, t_flags *flags, va_list elem);
void	convert_all(t_flags *flags, va_list elem, char **str);
void	printf_all(va_list elem, t_flags *flags);

void	initialize_flags(t_flags *flags);
void	modif_flags(t_flags *flags, char c);
void	change_flags(t_flags *flags);

char	*ft_itoa_prec(int param, t_flags *flags);
char	*ft_uitoa_prec(unsigned long param, t_flags *flags);
char	*choose_type_convert(char convert_type);
char	*convert_to_hex(unsigned int nbr, char *base, t_flags *flags);
char	*convert_to_pointer(void *pointer, t_flags *flags);
char	*char_to_str(t_flags *flags, va_list elem);
char	*str_with_precision(char *str, t_flags *flags);

void	append_char(char **str, char c);
int		ft_strlen(char *str);
void	putstr(char *str, t_flags *flags);
char	*ft_strdup(const char *source);

#endif