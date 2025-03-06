/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:15:10 by skafir            #+#    #+#             */
/*   Updated: 2025/03/06 21:15:14 by skafir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	x;
	int	sign;
	int	result;

	x = 0;
	sign = 1;
	result = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == ' ')
		nptr++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			sign *= -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		result = result * 10 + (nptr[x] - 48);
		nptr++;
	}
	return (result * sign);
}
