/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:52:45 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 19:36:52 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <stdlib.h>

size_t	get_num_of_positive_solutions(double a, double b, double c);
size_t	get_num_of_solutions(double a, double b, double c);
double	get_t_of_contact_point(double a, double b, double c);
double	scale_to_minus_one_to_one(double value);
double	scale_to_zero_to_one(double value);

#endif