#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

typedef struct	s_flags
{
	int		minus;
	int		zero;
	int 	precision;
	int		width;
	int 	typ_conv;
	int		count_char;
}		t_flags;

int	ft_printf(const char *str, ...);
void	*parsing(const char *str, t_flags *flags, va_list elem);
void	convert_all(t_flags *flags, va_list elem, char **str,char c);
int	printf_all(char c, va_list elem, t_flags *flags);

void	initialize_flags(t_flags *flags);
void	modif_flags(t_flags *flags, char c);
void 	change_flags(t_flags *flags);

char	*ft_itoa_prec(int param, t_flags flags);
char	*ft_uitoa_prec(unsigned long param, t_flags flags);
char	*choose_type_convert(char convert_type);
char	*convert_to_hex(unsigned int nbr, char *base, int precision);
char	*convert_to_pointer(void *pointer, int precision);

void	append_char(char **str, char c);
char *str_with_precision(char *str, int precision);
int ft_strlen(char *str);
int	putstr(char *str, char type);
char	*char_to_str(char c, t_flags *flags, va_list elem);