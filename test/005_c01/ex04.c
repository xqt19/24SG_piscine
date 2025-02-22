/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:21:35 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 15:23:59 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_ultimate_div_mod(int *a, int *b){
    int num1 = *a;
    int num2 = *b;
    *a = num1/num2;
    *b = num1%num2;
}

int main(){
    int nbr = 63;
    int nbr2 = 10;
    ft_ultimate_div_mod(&nbr, &nbr2);
    printf("%d",nbr);
    printf("\n");
    printf("%d",nbr2);
}