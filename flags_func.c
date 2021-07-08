#include "libftprintf.h"

void	initialize_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = -1;
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
}

void 	change_flags(t_flags *flags)
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

char	*char_to_str(char c, t_flags *flags, va_list elem)
{
	char	*str;
	int		character;

	str = malloc(1);
	str[0] = 0;
	if (c == 'c')
	{
		character = va_arg(elem, int);
		if (character == 0)
		{
			/*if (flags->minus > 0)
				flags->width = 0;
			else*/
			flags->width--;
		}
		else
			append_char(&str, character);
	}
	else
		append_char(&str, '%');
	return (str);
}
