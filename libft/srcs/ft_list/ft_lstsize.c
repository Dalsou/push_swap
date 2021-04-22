/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:51:45 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/15 22:22:48 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list **lst)
{
	t_list	*cursor;
	int 	size;

	size = 0;
	cursor = *lst;
	while (cursor)
	{
		size++;
		cursor = cursor->next;
	}
	return (size);
}
