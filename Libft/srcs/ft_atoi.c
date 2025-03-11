/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:04:46 by desambou          #+#    #+#             */
/*   Updated: 2024/11/13 13:53:27 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;

       	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		    i++;
        if (nptr[i] == '-' || nptr[i] == '+')
        {
            if (nptr[i] == '-')
                sign *= -1;
            i++;
        }
        while ((nptr[i] >= '0' && nptr[i] <= '9'))
        {
            res = res * 10 + (nptr[i] - '0');
            i++;
        }
    

	return (res * sign);
}

// int main(int ac, char *av[])
// {
//     if(ac == 2)
//         printf("%d\n", ft_atoi(av[1]));
//     return (0);
// }