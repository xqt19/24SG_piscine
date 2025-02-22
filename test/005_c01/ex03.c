/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:17:30 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 15:20:58 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_div_mod(int a, int b, int *div, int *mod){
    *div = a/b;
    *mod = a%b;
}

int main(){
    int nbr = 42;
    int nbr2 = 10;
    int div = 98;
    int mod = 99;
    ft_div_mod(nbr, nbr2, &div, &mod);
    printf("%d",div);
    printf("\n");
    printf("%d",mod);
}