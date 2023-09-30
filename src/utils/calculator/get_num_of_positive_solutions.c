/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_positive_solutions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:14:12 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/26 22:18:50 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

//TODO:多分不要
size_t	get_num_of_positive_solutions(double a, double b, double c)
{
	double	result;
	double	t1;
	double	t2;
	size_t	num;

	num = 0;
	result = b * b - 4 * a * c;
	if (result > 0)
	{
		t1 = (-b + sqrt(result)) / (2 * a);
		t2 = (-b - sqrt(result)) / (2 * a);
		if (t1 >= 0 || t2 >= 0)
		{
			if (t1 >= 0 && t2 >= 0)
				num = 2;
			else
				num = 1;
		}
	}
	else if (result == 0)
	{
		if (-b / (2 * a) >= 0)
			num = 1;
	}
	return (num);
}
