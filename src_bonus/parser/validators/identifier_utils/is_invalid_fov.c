/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_fov.c              		                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:20:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 19:43:10 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include <stdbool.h>

bool	is_invalid_fov(const int fov)
{
	return (is_invalid_int(fov, MAX_FOV, MIN_FOV));
}
