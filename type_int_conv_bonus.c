#include "ft_printf_bonus.h"

char	*ft_itoa_with_prec(int param, t_flags *flags)
{
	char		*asc_conv;
	long long	nbr;

	asc_conv = ft_strdup("");
	if (asc_conv == NULL)
		return (NULL);
	nbr = (long long)param;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 9)
	{
		append_char(&asc_conv, (nbr % 10) + '0');
		nbr /= 10;
	}
	if (flags->precision != 0 || nbr != 0)
		append_char(&asc_conv, (nbr % 10) + '0');
	while (flags->precision > ft_strlen(asc_conv))
		append_char(&asc_conv, '0');
	treat_flags_sign_int(&asc_conv, flags, param);
	return (asc_conv);
}

void	treat_flags_sign_int(char **asc_conv, t_flags *flags, int param)
{
	while (flags->width > ft_strlen(*asc_conv) + 1 && flags->zero > 0)
		append_char(asc_conv, '0');
	if (flags->space > 0 && flags->number_sign == 0 && param >= 0)
		append_char(asc_conv, ' ');
	else if (flags->number_sign > 0 && param >= 0)
		append_char(asc_conv, '+');
	else if (param < 0)
		append_char(asc_conv, '-');
}

char	*ft_uitoa_with_prec(unsigned long param, t_flags *flags)
{
	char			*asc_conv;
	unsigned int	nbr;

	asc_conv = ft_strdup("");
	if (asc_conv == NULL)
		return (NULL);
	nbr = (unsigned int)param;
	if (nbr == 0 && flags->precision == 0)
		return (asc_conv);
	while (nbr > 9)
	{
		append_char(&asc_conv, (nbr % 10) + '0');
		nbr /= 10;
	}
	append_char(&asc_conv, (nbr % 10) + '0');
	while (flags->precision > ft_strlen(asc_conv))
		append_char(&asc_conv, '0');
	return (asc_conv);
}
