/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:52:46 by xitan             #+#    #+#             */
/*   Updated: 2025/02/22 17:47:07 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

// void    rush(char inputs[])
// {
//     char grid[30];
    
//     grid[0] = "0";
//     int i =0;
//     int length =0;
//     while (grid[i] != "\0")
//     {
//         length++;
//         i++;
//     }
//     printf("%d",length);

// }

int main(int argc, char **argv)
{
    char inputs[16];
    int i = 1;
    while (i<=16)
    {
        inputs[i] = argv[i];
        i++;
    } 
    // rush(inputs);
    i=0;
        while (i<16)
    {
        printf(inputs[i]);
        i++;
    } 
    return 0;
}