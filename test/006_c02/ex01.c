/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:02:58 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 16:21:29 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i=0;
    while(i<n && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}


int main()
{
    char src[20] = "helloworld";
    char dest[20] = "good-byeworld";
    ft_strncpy(dest,src,5);
    write(1,src,strlen(src));
    write(1,"\n",1);
    write(1,dest,strlen(dest));
}