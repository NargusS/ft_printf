#include "ft_printf.h"

void	initialize_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->space = 0;
	flags->sharp = 0;
	flags->pos_sign = 0;
}

void	modif_flags(t_flags *flags, char c)
{
	if (c == '0' && flags->minus == 0)
		flags->zero++;
	else if (c == '-')
	{
		flags->minus++;
		if (flags->zero > 0)
			flags->zero = 0;
	}
	else if (c == '+')
		flags->pos_sign++;
	else if (c == ' ')
		flags->space++;
	else if (c == '#')
		flags->sharp++;
}

void	change_flags(t_flags *flags)
{
	if (flags->precision >= 0)
		flags->zero = 0;
	if (flags->width < 0)
	{
		flags->zero = 0;
		flags->minus += 1;
		flags->width = -(flags->width);
	}
}

char	*char_to_str(t_flags *flags, va_list elem)
{
	char	*str;
	int		character;

	str = ft_strdup("");
	if (str == NULL)
		return (NULL);
	if (flags->type_conv == 'c')
	{
		character = va_arg(elem, int);
		if (character == 0)
			flags->width--;
		else
			append_char(&str, character);
	}
	else
		append_char(&str, '%');
	return (str);
}
