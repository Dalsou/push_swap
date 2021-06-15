/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:04:43 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 12:40:22 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstk, const char *ndle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*ndle)
		return ((char *)hstk);
	i = 0;
	while (hstk[i] && i < len)
	{
		if (hstk[i] == ndle[0])
		{
			j = 1;
			while (ndle[j] && hstk[i + j] == ndle[j] && (i + j) < len)
				j++;
			if (ndle[j] == '\0')
				return ((char *)&hstk[i]);
		}
		i++;
	}
	return (0);
}
