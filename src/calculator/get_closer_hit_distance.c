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
#include <config.h>

/**
 * 二次方程式（ax^2 + bx + c = 0）の解のうち、視点により近い解を返す関数
 * 解が存在しない場合には-1.0を返す。
 * b * b - 4 * a * c >= 0の場合のみ二次方程式の解が存在する。
 * 解は、⑴ -b - sqrt(result)) / (2 * a)、⑵ -b + sqrt(result)) / (2 * a)なので
 * 正の数の解でより小さい方を返す。	 
 * */
double	get_closer_hit_distance(double a, double b, double c)
{
	double	discriminant;
	double	hit_distance_1;
	double	hit_distance_2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0)
		return (NOT_HIT);
	hit_distance_1 = (-b - sqrt(discriminant)) / (2.0 * a);
	hit_distance_2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (hit_distance_1 < 0.0 && hit_distance_2 > 0.0)
		return (hit_distance_2);
	else if (hit_distance_1 > 0.0 && hit_distance_2 < 0.0)
		return (hit_distance_1);
	else if (hit_distance_1 > 0.0 && hit_distance_2 > 0.0)
	{
		if (hit_distance_1 > hit_distance_2)
			return (hit_distance_2);
		return (hit_distance_1);
	}
	else
		return (NOT_HIT);
}
