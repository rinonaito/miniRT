/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_double.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:45:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/29 21:07:02 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	_is_error(const char *str)
{
	int		dot_count;
	size_t	i;

	if (ft_strlen(str) == 1 && !ft_isdigit(str[0]))
		return (true);
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

static double	_set_conversion_num(
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

	conversion_num = 0;
	fraction = 0.1;
	is_comma = false;
	i = 0;
	while (str[i] != '\0'
		&& (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] != '\0')
	{
		_set_conversion_num(str[i], &conversion_num, &fraction, &is_comma);
		i++;
	}
	if (!is_positive)
		conversion_num *= -1;
	return (conversion_num);
}

int	convert_string_to_double(
	double *conversion_num,
	const char *str,
	const double max_num)
{
	bool	is_positive;

	if (str == NULL
		|| _is_error(str))
		return (EXIT_FAILURE);
	is_positive = true;
	if (str[0] == '-')
		is_positive = false;
	if (_is_simple_overflow(str, max_num))
		return (EXIT_FAILURE);
	*conversion_num = _convert(str, is_positive);
	return (EXIT_SUCCESS);
}

// #include <stdio.h>
// int main()
// {
// 	double a = 1;
// 	double b = -1;
// 	double c = 0;

// 	convert_string_to_double(&a, "1", 100);
// 	convert_string_to_double(&b, "-1", 100);
// 	convert_string_to_double(&c, "0", 100);
// 	printf("a = %lf\n", a);
// 	printf("b = %lf\n", b);
// 	printf("c = %lf\n", c);
// }