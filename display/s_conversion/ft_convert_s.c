/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:31:44 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/12 16:12:54 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*null_case(char *res)
{
	int		i;
	char	*str;
	int		len;

	str = ft_strdup("(null)");
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

static char	*empty_case(char *res)
{
	res = (char *)malloc(sizeof(char) * 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}

static char	*casual_case(char *str, char *res)
{
	int	i;
	int	len;

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
	return (res);
}

char	*ft_convert_s(va_list list, char *res)
{
	char	*str;

	str = va_arg(list, char *);
	if (str == NULL)
		res = null_case(res);
	else if (ft_strlen(str) == 0)
		res = empty_case(res);
	else
		res = casual_case(str, res);
	if (res == NULL)
		return (NULL);
	return (res);
}
