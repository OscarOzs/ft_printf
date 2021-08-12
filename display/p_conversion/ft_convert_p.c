/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:02:07 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/12 16:13:36 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*null_case(char *res)
{
	int		i;
	char	*str;
	int		len;

	str = ft_strdup("0x0");
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	free(str);
	return (res);
}

static char	*casual_case(char *str, char *res)
{
	char	*s;
	int		i;
	int		len;

	s = ft_strjoin("0x", str);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	return (res);
}

char	*ft_convert_p(va_list list, char *res)
{
	char	*str;
	long	nbr;

	nbr = va_arg(list, long);
	str = ft_utoa_base(nbr, "0123456789abcdef");
	if (nbr == 0)
		res = null_case(res);
	else
		res = casual_case(str, res);
	if (res == NULL)
		return (NULL);
	free(str);
	return (res);
}
