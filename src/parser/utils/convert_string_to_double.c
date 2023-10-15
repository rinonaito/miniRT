/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_double.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:45:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/15 19:34:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

//プラスマイナスも進めた方が良い。.の処理が必要
static bool	_is_error(const char *str)
{
	int	i;

	while ((*str != '\0')
		&& ((*str >= 9 && *str <= 13) || (*str == 32)))
		str++;
	i = 0;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
		i++;
	if (str[i] != '\0' && str[i] == '.')
		return (true);
	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9') && str[i] != '.')
	{
		if ((str[i] != '-' && str[i] != '+' && str[i] != '.')
			&& (str[i] < '0' || str[i] > '9'))
			return (true);
		if (i > 0 && str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (true);
		i++;
	}
	return (false);
}

static int	_sign_check(const char *str)
{
	int	sign;

	sign = 0;
	while ((*str != '\0')
		&& (((*str == '+' || *str == '-'))
			|| ((*str >= 9 && *str <= 13) || (*str == 32))))
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	return (sign);
}

/*
** strがlong型の最大値を超えるか判断する関数
*/
static bool	_is_max_and_min_error(const char *str, int sign)
{
	long	return_num;
	long	i;

	return_num = 0;
	i = 0;
	while ((str[i] != '\0')
		&& (((str[i] == '+' || str[i] == '-') || (str[i] == '0'))
			|| ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))))
		i++;
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		if (return_num < ((LONG_MIN + (str[i] - '0')) / 10))
		{
			if (sign == 0)
				return (1);
			return (2);
		}
		return_num *= 10;
		return_num -= str[i] - '0';
		i++;
	}
	if (sign == 0 && return_num == LONG_MIN)
		return (1);
	return (0);
}

/*
** strの文字列の最初の数字を、int型に変換する関数
*/
//TODO:未実装
//	最初から書き直した方が早いかも
int	convert_string_to_double(const char *str, double *num)
{
	int		sign;
	long	result_num;

	result_num = 0;
	if (_is_error(str))
		return (EXIT_FAILURE);
	sign = _sign_check(str);
	if (_is_max_and_min_error(str, sign) == 1)
		return (EXIT_FAILURE);
	while ((*str != '\0')
		&& (((*str == '+' || *str == '-') || (*str == '0'))
			|| ((*str >= 9 && *str <= 13) || (*str == 32))))
		str++;
	while ((*str != '\0') && (*str >= '0' && *str <= '9'))
	{
		result_num *= 10;
		result_num += (*str - 48);
		str++;
	}
	if (sign % 2 != 0)
		result_num *= -1;
	return (result_num);
	
	return (EXIT_SUCCESS);
}

int main(void){
    // Your code here!
    
}
