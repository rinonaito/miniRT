/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_double.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:45:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 21:18:00 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	_is_error(const char *str)
{
	int		dot_count;
	size_t	i;

	if (str[0] != '\0' && str[1] != '\0'
		&& !ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-'
		&& !ft_isdigit(str[1]))
		return (true);
	dot_count = 0;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
			return (true);
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (true);
		i++;
	}
	return (false);
}

static bool	_is_simple_overflow(
	const char *str,
	const double max_num)
{
	double	num;
	double	digit;
	size_t	i;

	num = 0.0;
	i = 0;
	while (str[i] != '\0'
		&& (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		digit = str[i] - '0';
		num = num * 10 + digit;
		if (num > max_num)
			return (true);
		i++;
	}
	return (false);
}

static double	_set_comversion_num(
	char c,
	double *conversion_num,
	double *fraction,
	bool *is_comma)
{
	int		digit;

	if (c == '.')
		*is_comma = true;
	else
	{
		digit = c - '0';
		if (*is_comma)
		{
			*conversion_num += digit * *fraction;
			*fraction /= 10;
		}
		else
			*conversion_num = *conversion_num * 10 + digit;
	}
	return (*conversion_num);
}

static double	_convert(const char *str, const bool is_positive)
{
	double	conversion_num;
	double	fraction;
	bool	is_comma;
	size_t	i;

	(void)is_positive;
	conversion_num = 0;
	fraction = 0.1;
	is_comma = false;
	i = 0;
	while (str[i] != '\0'
		&& (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] != '\0')
	{
		_set_comversion_num(str[i], &conversion_num, &fraction, &is_comma);
		i++;
	}
	return (conversion_num);
}

double	convert_string_to_double(
	double *conversion_num,
	const char *str,
	const double max_num)
{
	bool	is_positive;

	if (str == NULL
		|| _is_error(str))
		return (EXIT_FAILURE);
	if (str[0] == '+')
		is_positive = true;
	else if (str[0] == '-')
		is_positive = false;
	if (_is_simple_overflow(str, max_num))
		return (EXIT_FAILURE);
	*conversion_num = _convert(str, is_positive);
	return (EXIT_SUCCESS);
}