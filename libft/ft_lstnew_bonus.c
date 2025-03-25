/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:45:42 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/09 16:07:44 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* int	main(void)
{
 	char 	*s = "Lists work like this";
	t_list *node = ft_lstnew((void *)s);
	if (node == NULL)
	{
		printf("Failed to allocate memory.\n");
		return (1);
	}
	printf("Node content: %s\n", (char *)node->content);
	free(node);
	return (0);
 } */