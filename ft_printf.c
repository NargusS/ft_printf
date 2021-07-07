#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int printf_char;
	int temp;
	va_list	elem;
	t_flags flags;

	va_start(elem, str);
	printf_char = 0;
	while (*str)
	{
		initialize_flags(&flags);
		if (*str == '%')
		{
			str = parsing(str, &flags, elem);
			temp = printf_all(*str, elem, &flags);
			if (temp == 0 && *str == 'c')
			{
				write(1, "\0", 1);
				return (printf_char);
			}
			printf_char += temp;
			str++;
		}
		if (*str != 0 && *str != '%')
		{
			write(1, str, 1);
			printf_char++;
			str++;
		}
	}
	va_end(elem);
	return(printf_char);
}

void	*parsing(const char *str, t_flags *flags, va_list elem)
{
	str++;
	while (*str == '0' || *str == '-')
		modif_flags(flags, *(str++));
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
	change_flags(flags);
	return((void *)str);
}

void	convert_all(t_flags *flags, va_list elem, char **str,char c)
{
	long long 	nbr;
	char		*base;

	if (c == 'd' || c == 'i')
		*str = ft_itoa_prec((long long)va_arg(elem, long long), *flags);
	else if (c == 'u')
		*str = ft_uitoa_prec(va_arg(elem,unsigned long), *flags);
	else if (c == 'c' || c == '%')
		*str = char_to_str(c, flags, elem);
	else if (c == 's')
		*str = str_with_precision(va_arg(elem, void*), flags->precision);
	else if(c == 'p')
		*str = convert_pointer_to_address(va_arg(elem, void *), flags->precision);
	else if (c == 'x' || c == 'X')
	{
		nbr = va_arg(elem, unsigned int);
		base = choose_type_convert(c);
		*str = convert_to_hex(nbr, base, flags->precision);
	}
}

int	printf_all(char c, va_list elem, t_flags *flags)
{
	char *str;
	int		printf_char;
	int		check_width;

	printf_char = 0;
	//printf(" %d|%d|%d|%d|%c", flags->minus, flags->zero,flags->precision, flags->width, *str);
	convert_all(flags, elem, &str, c);
	check_width = flags->width - ft_strlen(str);
	if (check_width > 0)
	{
		c = ' ';
		if (flags->minus > 0)
			printf_char += putstr(str);
		if (flags->zero > 0)
			c = '0';
		while(check_width--)
		{
			write(1, &c, 1);
			printf_char++;
		}
		if (flags->minus == 0)
			printf_char += putstr(str);	
	}
	else
		printf_char += putstr(str);
	return (printf_char);
}