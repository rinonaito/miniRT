/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:52:14 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 11:44:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convert_string_to_int(int *num, const char *str)
{
	size_t	i;

	*num = 0;
	while ((*str != '\0')
		&& ((*str >= 9 && *str <= 13) || (*str == 32)))
		str++;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '-' && str[i] != '+') && !ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		if ((i != 0) && !ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	*num = ft_atoi(str);
	return (EXIT_SUCCESS);
}
