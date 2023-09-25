/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_errno.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:39:43 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/24 13:51:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	exit_with_errno(int err_num)
{
	ft_putendl_fd(strerror(err_num), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
