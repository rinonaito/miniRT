/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:00:07 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/30 15:01:03 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "types.h"

double		dot_vector3d(const t_vector3d a, const t_vector3d b);

t_vector3d	subtraction_vector3d_xyz(
				const t_vector3d a,
				const double x,
				const double y,
				const double z);

t_vector3d	addition_vector3d(const t_vector3d a, const t_vector3d b);

t_vector3d	subtraction_vector3d(const t_vector3d a, const t_vector3d b);

t_vector3d	normalize_vector3d(t_vector3d v);

t_vector3d	vector3d_dot_double(t_vector3d vec, double t);

double		get_len_of_vector3d(t_vector3d vec);

#endif
