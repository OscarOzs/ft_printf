/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:54:59 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/12 14:26:40 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*fill_res(char *res)
{
	res = (char *)malloc(sizeof(char) * 2);
	if (res == NULL)
		return (NULL);
	res[1] = '\0';
	res[0] = '%';
	return (res);
}

char	*ft_convert_percent(char *res)
{
	res = fill_res(res);
	if (res == NULL)
		return (NULL);
	return (res);
}
