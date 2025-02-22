/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:41:21 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 15:42:48 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_sort_int_tab(int *tab, int size){
    int i = 0;
    int num;
    while (i<size-1){
        int j = i+1;
        while (j<size){
            if (tab[i]>tab[j]){
                num = tab[i];
                tab[i] = tab[j];
                tab[j] = num;
            }
            j++;
        }
        i++;
    }
}

int main(){
    int arr[5] = {3,5,4,1,2};
    for (int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    ft_sort_int_tab(arr,5);
    for (int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
}