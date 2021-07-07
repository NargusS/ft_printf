#include "libftprintf.h"

void	append_char(char **str, char c)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(ft_strlen(*str) + 2);
	if (!new_str)
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

char	*str_with_precision(char *str, int precision)
{
	char	*new_str;
	int		i;
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	if (precision >= 0 && precision < len)
		len = precision;
	new_str = malloc(len + 1);
	new_str[len] = 0;
	while (len--)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

int	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
