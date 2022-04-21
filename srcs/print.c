/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:21:21 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/21 11:21:23 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

void PrintOtherPower(t_equa equation) {
	int n;

	if (!equation.otherPower || !equation.otherPower[0])
		return ;
	n = -1;
	while (equation.otherPower[++n]) {
		if (!n && equation.other[0] != 1 && equation.other[0] != -1)
			ft_putfloat(equation.other[0]);
		if (!n && equation.other[n] == -1)
			ft_putchar('-');
		if (n && equation.other[n] != 1 && equation.other[n] != -1)
			ft_putfloat(ft_abs(equation.other[n]));
	    ft_putstr("x^");
		ft_putnbr(equation.otherPower[n]);
		ft_putchar(' ');
		if (equation.otherPower[n + 1] || equation.a) {
			if ((equation.other[n + 1] > 0) || (!equation.otherPower && equation.a > 0))
				ft_putstr("+ ");
			else
				ft_putstr("- ");
		}
	}
}

void PrintB(t_equa equation) {
	if (((equation.otherPower && equation.otherPower[0]) || equation.a) && equation.b){
		if (equation.b > 0)
			ft_putstr("+ ");
		else
			ft_putstr("- ");
		 if (equation.b != 1 && equation.b != -1)
			ft_putfloat(ft_abs(equation.b));
        ft_putstr("x ");
	} else if (equation.b) {
        if (equation.b != 1 && equation.b != -1)
			ft_putfloat(equation.b);
		if (equation.b == -1)
			ft_putchar('-');
        ft_putstr("x ");
    }
}

void PrintEquation(t_equa equation) {
    ft_putstr("Reduced form: ");
	PrintOtherPower(equation);
    if (equation.a) {
		if (equation.otherPower && equation.otherPower[0])
			ft_putfloat(ft_abs(equation.a));
		else {
        	if (equation.a != 1 && equation.a != -1)
            	ft_putfloat(equation.a);
			if (equation.a == -1)
				ft_putchar('-');
		}
        ft_putstr("x^2 ");
    }
	PrintB(equation);
	if (((equation.otherPower && equation.otherPower[0]) || equation.a || equation.b) && equation.c) {
		if (equation.c > 0)
			ft_putstr("+ ");
		else
			ft_putstr("- ");
		ft_putfloat(ft_abs(equation.c));
		ft_putchar(' ');
	} else if (equation.c) {
		ft_putfloat(equation.c);
		 ft_putchar(' ');
	}
	if (!equation.a && !equation.b && !equation.c)
		ft_putstr("0 ");
    ft_putendl("= 0");
}

void PrintSolution(t_equa equa) {
    double delta;

    delta = equa.b * equa.b - 4 * equa.a * equa.c;
	if (delta < 0)
        ft_putendl("Discriminant is negative, the equation has no solution");
    else if (delta == 0) {
        ft_putendl("Discriminant is nul, the solution is:");
        ft_putfloat(-1 * (equa.b / (2 * equa.a)));
        ft_putchar('\n');
    }
    else {
        ft_putendl("Discriminant is strictly positive, the two solutions are:");
        ft_putfloat((-equa.b - ft_sqrtd(delta)) / (2 * equa.a));
        ft_putchar('\n');
        ft_putfloat((-equa.b + ft_sqrtd(delta)) / (2 * equa.a));
        ft_putchar('\n');
    }
}
