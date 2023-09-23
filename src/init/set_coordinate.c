/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:47:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/23 20:03:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	set_coordinate(
	t_coordinate *coordinate,
	double x,
	double y,
	double z)
{
	coordinate->x = x;
	coordinate->y = y;
	coordinate->z = z;
}
