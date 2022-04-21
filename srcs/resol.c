/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:18:58 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/21 11:06:07 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

int reduceEquation(t_equa *equa1, t_equa *equa2) {
	int n;
	int m;

    equa1->a -= equa2->a;
    equa1->b -= equa2->b;
    equa1->c -= equa2->c;
	n = -1;
	while (equa2->otherPower && equa2->otherPower[++n]) {
		m = -1;
		while (equa1->otherPower && equa1->otherPower[++m]) {
			if (equa2->otherPower[n] == equa1->otherPower[m]) {
				equa2->otherPower[n] = 0;
				equa1->other[n] += equa2->other[n];
			}
		}
		if ((equa2->otherPower[n] || !equa1->otherPower) &&
			!addNewPower(equa1, equa2->other[n], equa2->otherPower[n])) {
			free(equa2->otherPower);
			free(equa2->other);
			free(equa1->otherPower);
			free(equa1->other);
			return (0);
		}
	}
	free(equa2->otherPower);
	free(equa2->other);
	return (1);
}

void ResolveLowEquation(t_equa equa) {

	if (equa.b) {
        ft_putendl("Polynomial degree: 1");
		ft_putendl("The solution is :");
		if (equa.b < 0)
			ft_putfloat(equa.c / (equa.b * -1));
		else
			ft_putfloat((equa.c * - 1) / equa.b);
		ft_putchar('\n');
	}
	else if (!equa.c)
		ft_putendl("Polynomial degree: 0\nThe solutions are all the real numbers");
	else
		ft_putendl("Polynomial degree: 0\nThere are no solutions");

}

int ResolveEquation(char *equation) {
    t_equa equa1;
    t_equa equa2;

    if (!SplitEquation(&equa1, &equa2, RemoveSpace(equation)) ||
		!reduceEquation(&equa1, &equa2))
        return 0;
	if (equa1.otherPower)
		BadSort(&equa1);
    PrintEquation(equa1);
	if (equa1.other) {
		ft_putstr("Polynomial degree: ");
		ft_putnbr(equa1.otherPower[0]);
		ft_putendl("\nThe polynomial degree is stricly greater than 2, I can't solve.");
		free(equa1.other);
		free(equa1.otherPower);
	}
	else if (equa1.a) {
        ft_putendl("Polynomial degree: 2");
		PrintSolution(equa1);
	}
    else 
		ResolveLowEquation(equa1);
    return 1;
}
