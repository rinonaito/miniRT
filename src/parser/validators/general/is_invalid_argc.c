/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_argc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:18:05 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 15:39:52 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"
#include "config.h"
#include "parser.h"
#include <stdbool.h>

bool	is_invalid_argc(const int argc)
{
	bool	ret;

	ret = (argc != VALID_ARGC_NUM && argc != VALID_ARGC_NUM + BONUS_ARGS);
	if (ret)
	{
		print_error_msg(INVALID_ARGC);
		return (true);
	}
	return (false);
}
