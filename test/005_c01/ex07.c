/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:32:13 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 15:46:09 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_rev_int_tab(int *tab, int size){
    int i = 0;
    int j = size-1;
    int num;
    while (i<j){
        num = tab[i];
        tab[i] = tab[j];
        tab[j] = num;
        i++;
        j--;
    }
}

int main(){
    int arr[5] = {3,5,4,1,2};
    for (int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    ft_rev_int_tab(arr,5);
    for (int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
}