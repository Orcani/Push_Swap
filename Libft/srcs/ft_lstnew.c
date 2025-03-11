/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:07:43 by desambou          #+#    #+#             */
/*   Updated: 2024/11/16 20:04:22 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*container;

	container = (t_list *)malloc(sizeof(t_list));
	if (!container)
		return (NULL);
	container->content = content;
	container->next = NULL;
	return (container);
}
