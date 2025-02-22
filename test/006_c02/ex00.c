/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:48:11 by xitan             #+#    #+#             */
/*   Updated: 2025/02/21 16:00:30 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char    *ft_strcpy(char *dest, char *src)
{
    int i=0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    return dest;
}

int main()
{
    char src[20] = "helloworld";
    char dest[20];
    ft_strcpy(dest,src);
    write(1,src,strlen(src));
    write(1,"\n",1);
    write(1,dest,strlen(dest));
}