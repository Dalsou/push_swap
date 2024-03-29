/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:46:00 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 12:40:41 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	while (src[i] && dsize > 0 && i < (dsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (dsize > 0)
		dst[i] = '\0';
	return (len);
}
