#include "ft_printf.h"

void	append_char(char **str, char c)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(ft_strlen(*str) + 2);
	if (new_str == NULL)
		return ;
	new_str[i++] = c;
	while ((*str)[j] != 0)
		new_str[i++] = (*str)[j++];
	new_str[i] = 0;
	free(*str);
	*str = new_str;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*str_with_precision(char *str, t_flags *flags)
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

void	putstr(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (str != NULL && str[i])
		write(1, &str[i++], 1);
	if (i == 0 && flags->type_conv == 'c')
	{
		write (1, "\0", 1);
		i++;
	}
	flags->char_count += i;
	free(str);
}

char	*ft_strdup(const char *source)
{
	char	*str;
	int		len;

	len = ft_strlen((char *)source);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = source[len];
	return (str);
}
