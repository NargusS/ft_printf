#include "libftprintf.h"

char	*ft_itoa_prec(int param, t_flags flags)
{
	char		*nbr_s;
	long long	nbr;

	nbr_s = malloc(1);
	nbr_s[0] = 0;
	nbr = (long long)param;
	if (nbr == 0 && flags.precision == 0)
		return (nbr_s);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 9)
	{
		append_char(&nbr_s, (nbr % 10) + '0');
		nbr /= 10;
	}
	append_char(&nbr_s, (nbr % 10) + '0');
	while (flags.precision > ft_strlen(nbr_s))
		append_char(&nbr_s, '0');
	if (param < 0)
	{
		while (flags.width > ft_strlen(nbr_s) + 1 && flags.zero > 0)
			append_char(&nbr_s, '0');
		append_char(&nbr_s, '-');
	}
	return (nbr_s);
}

char	*ft_uitoa_prec(unsigned long param, t_flags flags)
{
	char			*nbr_s;
	unsigned int	nbr;

	nbr_s = malloc(1);
	nbr_s[0] = 0;
	nbr = (unsigned int)param;
	if (nbr == 0 && flags.precision == 0)
		return (nbr_s);
	while (nbr > 9)
	{
		append_char(&nbr_s, (nbr % 10) + '0');
		nbr /= 10;
	}
	append_char(&nbr_s, (nbr % 10) + '0');
	while (flags.precision > ft_strlen(nbr_s))
		append_char(&nbr_s, '0');
	return (nbr_s);
}

char	*choose_type_convert(char convert_type)
{
	char	*base;

	base = NULL;
	if (convert_type == 'x')
		base = "0123456789abcdef";
	else if (convert_type == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

char	*convert_to_hex(unsigned int nbr, char *base, int precision)
{
	char	*hex_conversion;

	hex_conversion = malloc(1);
	hex_conversion[0] = 0;
	if (nbr == 0)
	{
		if (precision == 0)
			return (hex_conversion);
		append_char(&hex_conversion, base[0]);
	}
	else if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		if (hex_conversion[0] == 0 && (base[0] == 'f' || base[0] == 'F'))
			append_char(&hex_conversion, base[(nbr % 16) - 1]);
		else
			append_char(&hex_conversion, base[nbr % 16]);
		nbr /= 16;
	}
	while (ft_strlen(hex_conversion) < 8 && (base[0] == 'f' || base[0] == 'F'))
		append_char(&hex_conversion, base[0]);
	while (precision > ft_strlen(hex_conversion))
		append_char(&hex_conversion, '0');
	return (hex_conversion);
}

char	*convert_to_pointer(void *pointer, int precision)
{
	char			*hex_conversion;
	char			*base;
	unsigned long	nbr;

	base = "0123456789abcdef";
	hex_conversion = malloc(1);
	hex_conversion[0] = 0;
	nbr = (unsigned long)pointer;
	if (nbr == 0 && precision == 0)
	{
		append_char(&hex_conversion, 'x');
		append_char(&hex_conversion, '0');
		return (hex_conversion);
	}
	while (nbr >= 16)
	{
		append_char(&hex_conversion, base[nbr % 16]);
		nbr /= 16;
	}
	append_char(&hex_conversion, base[nbr % 16]);
	append_char(&hex_conversion, 'x');
	append_char(&hex_conversion, '0');
	return (hex_conversion);
}
