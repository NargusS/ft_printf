/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex_conv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:06:49 by achane-l          #+#    #+#             */
/*   Updated: 2021/07/14 12:06:52 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*choose_base(char convert_type)
{
	char	*base;

	base = NULL;
	if (convert_type == 'x')
		base = "0123456789abcdef";
	else if (convert_type == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

char	*conv_to_hex_with_prec(unsigned int nbr, char *base, t_flags *flags)
{
	char	*hex_conversion;

	hex_conversion = ft_strdup("");
	if (hex_conversion == NULL)
		return (NULL);
	if (nbr == 0)
	{
		if (flags->precision == 0)
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
	add_precision_to_hex(&hex_conversion, flags);
	return (hex_conversion);
}

void	add_precision_to_hex(char **hex_conversion, t_flags *flags)
{
	while (flags->precision > ft_strlen(*hex_conversion))
		append_char(hex_conversion, '0');
}

char	*conv_to_pointer(void *pointer, t_flags *flags)
{
	char			*hex_conversion;
	char			*base;
	unsigned long	nbr;

	base = "0123456789abcdef";
	hex_conversion = ft_strdup("");
	if (hex_conversion == NULL)
		return (NULL);
	nbr = (unsigned long)pointer;
	if (nbr == 0 && flags->precision == 0)
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
