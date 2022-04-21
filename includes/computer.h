/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerV1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:01:32 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/21 10:40:55 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPUTER_H
# define FT_COMPUTER_H

# include <unistd.h>
# include "libft.h"
# include <stdlib.h>


struct					s_equa
{
	double a;
	double b;
	double c;
	double *other;
	int *otherPower;

};

typedef struct s_equa	t_equa;

int ResolveEquation(char *equation);
double    ft_strtod(const char *str);
void        ft_putfloat(double nb);
char* RemoveSpace(char *string);
int SplitEquation(t_equa *equa1, t_equa *equa2, char *equation);
double ft_sqrtd(double number);
int addNewPower(t_equa *nombre, double nb, int power);
void PrintSolution(t_equa equa);
double ft_abs(double nb);
int checkTimes(char *line);
int addNewPower(t_equa *nombre, double nb, int power);
void PrintEquation(t_equa equation);
void BadSort(t_equa *equa);

#endif
