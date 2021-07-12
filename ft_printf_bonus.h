#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		width;
	int		space;
	int		number_sign;
	int		sharp;
	int		type_conv;
	int		char_count;
	int		error;
}				t_flags;

int		ft_printf(const char *str, ...);
void	*parsing(const char *str, t_flags *flags, va_list elem);
void	convert_type(t_flags *flags, va_list elem, char **str);
void	convert_and_print(va_list elem, t_flags *flags);
void	print_width_and_str(char *str, t_flags *flags);

void	initialize_flags(t_flags *flags);
void	append_flags(t_flags *flags, char c);
void	change_state_flags(t_flags *flags);

char	*ft_itoa_with_prec(int param, t_flags *flags);
char	*ft_uitoa_with_prec(unsigned long param, t_flags *flags);
void	treat_flags_sign_int(char **nbr_s, t_flags *flags, int param);

char	*choose_base(char convert_type);
char	*conv_to_hex_with_prec(unsigned int nbr, char *base, t_flags *flags);
void	add_precision_to_hex(char **hex_conversion, t_flags *flags);
char	*conv_to_pointer(void *pointer, t_flags *flags);

char	*conv_char_to_str(t_flags *flags, va_list elem);
char	*str_with_prec(char *str, t_flags *flags);

void	append_char(char **str, char c);
int		ft_strlen(char *str);
void	putstr(char *str, t_flags *flags);
char	*ft_strdup(const char *source);
int		ft_is_in(char *str, char c);

#endif