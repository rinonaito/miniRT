/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:08:39 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/08 12:26:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "x_wrapper.h"
#include "config.h"
#include <unistd.h>

void	print_error_msg(char *msg)
{
	ft_xputendl_fd(ERROR_MSG, STDERR_FILENO);
	ft_xputendl_fd(msg, STDERR_FILENO);
}
