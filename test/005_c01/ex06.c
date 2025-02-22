/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:28:51 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 15:31:54 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int    ft_strlen(char *str){
    int num = strlen(str);
    return num;
}

int main(){
    char str[] = "helloworld";
    int len = ft_strlen(str);
    printf("%d",len);
}