/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:04:01 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 12:56:26 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_object	create_object(
	const void *object,
	double (*fp_hit_object)(const t_ray, const void *),
	t_vector3d (*fp_get_normal_vector_for_object)(
		const t_ray, const t_vector3d, const void *, const t_bumpmap),
	int (*fp_get_pixel_color_for_object)(
		const void *, const t_ray))
{
	t_object	ret;

	ret.object = (void *)object;
	ret.fp_hit_object = fp_hit_object;
	ret.fp_get_normal_vector_for_object = fp_get_normal_vector_for_object;
	ret.fp_get_pixel_color_for_object = fp_get_pixel_color_for_object;
	return (ret);
}
