/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:02:28 by carolinat         #+#    #+#             */
/*   Updated: 2024/05/19 14:28:14 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_list(void *cont, t_list **lst, void (*del) (void *))
{
	del(cont);
	ft_lstclear(lst, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	void	*new_content;
	t_list	*first;
	t_list	*this_node;

	if (!lst || !f || !del)
		return (0);
	first = 0;
	while (lst)
	{
		new_content = f(lst->content);
		this_node = ft_lstnew(new_content);
		if (!this_node)
			return (free_list(new_content, &first, del));
		if (!first)
			first = this_node;
		else
			ft_lstadd_back(&first, this_node);
		this_node = this_node->next;
		lst = lst->next;
	}
	return (first);
}
