#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	va_list	elem;
	t_flags	flags;

	va_start(elem, str);
	flags.char_count = 0;
	while (*str)
	{
		initialize_flags(&flags);
		if (*str == '%')
		{
			str = parsing(str, &flags, elem);
			convert_and_print(elem, &flags);
			str++;
			if (flags.char_count == -1)
				return (flags.char_count);
		}
		if (*str != 0 && *str != '%')
		{
			write(1, str, 1);
			flags.char_count++;
			str++;
		}
	}
	va_end(elem);
	return (flags.char_count);
}

void	*parsing(const char *str, t_flags *flags, va_list elem)
{
	str++;
	while (ft_is_in("0-#+ ", *str) == 1)
		append_flags(flags, *(str++));
	while (*str >= '0' && *str <= '9')
		flags->width = (flags->width * 10) + (*(str++) - '0');
	if (*str == '*')
	{
		flags->width = va_arg(elem, int);
		str++;
	}
	if (*str == '.')
	{
		str++;
		flags->precision = 0;
		while (*str >= '0' && *str <= '9')
			flags->precision = (flags->precision * 10) + (*(str++) - '0');
		if (*str == '*')
		{
			flags->precision = va_arg(elem, int);
			str++;
		}
	}
	flags->type_conv = *str;
	change_state_flags(flags);
	return ((void *)str);
}

void	convert_type(t_flags *flags, va_list elem, char **str)
{
	long long	nbr;
	char		*base;

	if (flags->type_conv == 'd' || flags->type_conv == 'i')
		*str = ft_itoa_with_prec(va_arg(elem, long long), flags);
	else if (flags->type_conv == 'u')
		*str = ft_uitoa_with_prec(va_arg(elem, unsigned long), flags);
	else if (flags->type_conv == 'c' || flags->type_conv == '%')
		*str = conv_char_to_str(flags, elem);
	else if (flags->type_conv == 's')
		*str = str_with_prec(va_arg(elem, void *), flags);
	else if (flags->type_conv == 'p')
		*str = conv_to_pointer(va_arg(elem, void *), flags);
	else if (flags->type_conv == 'x' || flags->type_conv == 'X')
	{
		nbr = va_arg(elem, unsigned int);
		base = choose_base(flags->type_conv);
		*str = conv_to_hex_with_prec(nbr, base, flags);
		if (flags->sharp > 0 && nbr != 0)
		{
			append_char(str, flags->type_conv);
			append_char(str, '0');
		}
	}
}

void	convert_and_print(va_list elem, t_flags *flags)
{
	char	*str;

	str = NULL;
	convert_type(flags, elem, &str);
	if (str == NULL && (flags->type_conv != 's'))
		flags->char_count = -1;
	print_width_and_str(str, flags);
}

void	print_width_and_str(char *str, t_flags *flags)
{
	int	check_width;
	int	c;

	check_width = flags->width - ft_strlen(str);
	if (check_width > 0)
	{
		c = ' ';
		if (flags->minus > 0)
			putstr(str, flags);
		if (flags->zero > 0)
			c = '0';
		while (check_width--)
		{
			write(1, &c, 1);
			flags->char_count++;
		}
		if (flags->minus == 0)
			putstr(str, flags);
	}
	else
		putstr(str, flags);
}
