/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:26:46 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/28 21:38:57 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "types.h"

void	set_ray(
			t_ray *ray,
			const t_camera camera,
			const t_vector3d xyz);

#endif
