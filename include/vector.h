/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:00:07 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 16:06:20 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"

double	dot_vector3d(const t_vector3d a, const t_vector3d b);
t_vector3d	subtraction_vector3d_xyz(
		const t_vector3d a,
		const double x,
		const double y,
		const double z);
t_vector3d	subtraction_vector3d(const t_vector3d a, const t_vector3d b);

#endif
