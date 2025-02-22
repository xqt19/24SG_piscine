/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:24:24 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 15:28:22 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void    ft_putstr(char *str){
    write(1, str, strlen(str));
}

int main(){
    char str[] = "helloworld";
    ft_putstr(str);
}