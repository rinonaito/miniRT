/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:26:46 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/24 20:27:37 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "types.h"

void	set_ray(
			t_ray *ray,
			const t_vector3d origin,
			const t_vector2d uv,
			const double focal_len);

#endif
