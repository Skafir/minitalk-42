/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:46:49 by skafir          #+#    #+#             */
/*   Updated: 2024/12/02 11:42:34 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	x;

	if (!s && !c)
		return (NULL);
	x = 0;
	while (x < n)
	{
		*(unsigned char *)(s + x) = (unsigned char)c;
		x++;
	}
	return (s);
}
