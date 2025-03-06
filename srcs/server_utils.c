/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:14:03 by skafir            #+#    #+#             */
/*   Updated: 2025/03/06 21:14:03 by skafir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

char	*concat_char(const char *str, char c)
{
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, str);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (new_str);
}

void	handle_message(char character, char **str)
{
	char	*temp;

	if (character == '\0')
	{
		ft_putstr_fd(*str, 1);
		ft_putchar_fd('\n', 1);
		free(*str);
		*str = NULL;
	}
	else
	{
		if (*str)
			temp = concat_char(*str, character);
		else
			temp = concat_char("", character);
		free(*str);
		*str = temp;
	}
}
