/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:50:48 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/02/13 23:15:20 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	tot;

	tot = 0;
	while (*str == 9 || *str == 10 || *str == 11 || *str == 12 || *str == 13
		|| *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		if (ft_isdigit(*str) == -1)
			return (-1);
		if (tot > INT_MAX)
			return (-1);
		tot = tot * 10 + (*str - 48);
		str++;
	}
	return (tot);
}
