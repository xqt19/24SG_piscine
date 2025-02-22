/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:13:53 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 15:16:58 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b){
    int num = *a;
    *a = *b;
    *b = num;
}

int main(){
    int nbr = 10;
    int nbr2 = 59;
    ft_swap(&nbr, &nbr2);
    printf("%d",nbr);
    printf("\n");
    printf("%d",nbr2);
}