/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:09:52 by desambou          #+#    #+#             */
/*   Updated: 2024/11/13 13:37:14 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	int				byte;
	size_t			i;

	p = s;
	byte = 0;
	i = 0;
	while (i < n)
	{
		p[i] = byte;
		i++;
	}
}

//   #include <stdio.h>

//   int main(void)
//     {
//         char test[]= "Une voiture jaune.";
//         printf("%s", test);
//         bzero(test, 2);
//         ft_bzero(test, 2);
//         return (0);

//     }