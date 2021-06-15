/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:00:02 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 13:22:45 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *src, ...)
{
	va_list		list;
	char		*str;
	int			len;
	int			i;

	str = ft_strdup(src);
	if (src == NULL || str == NULL)
		return (0);
	va_start(list, src);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_parse(&str[i + 1], &list, &i);
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(list);
	free(str);
	return (len);
}
