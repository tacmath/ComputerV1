/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:19:31 by mtaquet           #+#    #+#             */
/*   Updated: 2022/03/21 10:40:34 by mtaquet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

int checkPower(t_equa *nombre, char **equa, double nb) {
	int power;

	if ((*equa)[1] >= '0' && (*equa)[1] <= '9') {
		power = ft_atoi(++(*equa));
		while ((*equa)[0] >= '0' && (*equa)[0] <= '9')
			(*equa)++;
        if (power > 2 ) {
			if (!addNewPower(nombre, nb, power))
				return 0;
		}
        else if (power == 0)
			nombre->c += nb;
		else if (power == 1)
			nombre->b += nb;
		else
			nombre->a += nb;
	}
	else {
		ft_putendl_fd("No power", 2);
		return 0;
	}
	return (1);
}


int GetNumber(t_equa *nombre, int negatif, char **equa) {
    double nb;

    nb = 1;
    if (**equa >= '0' && **equa <= '9') {
        nb = ft_strtod(*equa);
        while (**equa >= '0' && **equa <= '9')
            (*equa)++;
		if (**equa == '.') {
			(*equa)++;
			if (**equa < '0' || **equa > '9') {
				ft_putendl_fd("No decimal found", 2);
				return 0;
			}
			while (**equa >= '0' && **equa <= '9')
            	(*equa)++;
		}
    }
	if (**equa == '*')
		*equa += 1;
     nb = nb * negatif;
    if (**equa != 'x' && **equa != 'X')
        nombre->c += nb;
    if (**equa == 'x' || **equa == 'X') {
		*equa += 1;
        if (**equa != '^')
            nombre->b +=nb;
        else if (!checkPower(nombre, equa, nb))
			return 0;
    }
    return 1;
}

int GetEquation(char *equation, t_equa *variable) {
    int        signe;
	char *tmp;

	tmp = 0;
    signe = 1;
    ft_bzero(variable, sizeof(t_equa));
    while (*equation) {
		if (tmp == equation) {
			ft_putendl_fd("Wrong format", 2);
			return 0;
		}
    	if (*equation == '-') {
        	signe = -1;
            equation++;
		}
		else if (*equation == '+') {
			equation++;
			signe = 1;
		}
		else if (tmp)
			signe = 0;
		tmp = equation;
        if (signe && !GetNumber(variable, signe, &equation))
			return 0;
    }
    return 1;
}

int SplitEquation(t_equa *equa1, t_equa *equa2, char *equation) {
    char **equations;
    int n;

    n = -1;
    if (!checkTimes(equation) || !(equations = ft_strsplit(equation, '='))){
		ft_putendl_fd("Wrong format", 2);
        free(equation);
        return 0;
    }
    free(equation);
    if (!equations[1] || equations[2]) {
        ft_putendl_fd("Equation invalid", 2);
        while (equations[++n])
            free(equations[n]);
        free(equations);
        return 0;
    }
    if (!GetEquation(equations[0], equa1) || !GetEquation(equations[1], equa2)) {
	    while (equations[++n])
    	    free(equations[n]);
    	free(equations);
		return 0;
	}
    while (equations[++n])
        free(equations[n]);
    free(equations);
    return 1;
}
