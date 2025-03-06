/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:08:20 by skafir          #+#    #+#             */
/*   Updated: 2024/12/02 11:31:07 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	x;
	char	*dup;

	dup = (char *)malloc((ft_strlen(src) + 1) * sizeof(*src));
	x = 0;
	if (!dup)
		return (NULL);
	while (src[x])
	{
		dup[x] = src[x];
		x++;
	}
	dup[x] = 0;
	return (dup);
}
