/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_solutions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:21:00 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 22:18:02 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

/**
 * 二次方程式の解の数を返す関数
 * ax^2 + bx + c = 0が成立する時、
 * b * b - 4 * a * cの答えと0を比較することで、解の数が求められる
*/
//TODO:多分不要
size_t	get_num_of_solutions(double a, double b, double c)
{
	double	result;

	result = b * b - 4 * a * c;
	if (result > 0)
		return (2);
	else if (result == 0)
		return (1);
	else
		return (0);
}
