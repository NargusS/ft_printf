#include "ft_printf_bonus.h"

char	*str_with_prec(char *str, t_flags *flags)
{
	char	*new_str;
	int		i;
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	new_str = malloc(len + 1);
	new_str[len] = 0;
	while (len--)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

char	*conv_char_to_str(t_flags *flags, va_list elem)
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
