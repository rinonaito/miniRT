/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:16:26 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 21:22:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	is_string_match(const char *s1, const char *s2)
{
	const size_t	s1_len = ft_strlen(s1);

	if (s1_len != ft_strlen(s2))
		return (false);
	return (ft_strncmp(s1, s2, s1_len) == 0);
}
