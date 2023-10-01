/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:20:13 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 22:04:08 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

/**
 * 二次方程式（ax^2 + bx + c = 0）の解のうち、視点により近い解を返す関数
 * 解が存在しない場合には-1.0を返す。
*/
double	get_hit_distance(double a, double b, double c)
{
	double	result;

	result = b * b - 4 * a * c;
	if (result < 0)
		return (-1.0);
	else
		return ((-b - sqrt(result)) / (2 * a));
}
