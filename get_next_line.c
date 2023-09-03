/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaibi <zaibi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:29:00 by mshazaib          #+#    #+#             */
/*   Updated: 2023/09/03 19:46:04 by zaibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	// count chars
	str_len = len_to_newline(list);
	// malloc size of str_len + 1
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	// cpy the string into the buffer and return it
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		return ;
	}
	// if list is empty
	if (last_node == NULL)
	{
		*list = new_node;
	}
	else
	{
		last_node->next = new_node;
	}
	new_node->str_buff = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buff;

	// scan line if \n present
	while (!found_newline(*list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return ;
		char_read = read(fd, buff, BUFFER_SIZE);
		if (!char_read)
		{
			free(buff);
			return ;
		}
		buff[char_read] = '\0';
		// append the node
		append(list, buff);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
	// fd os +ve | read gives -1 if some shit happen
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		return (NULL);
	}
	// create list
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	// fetch the line from list
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	int lines;
// 	lines = 1;
// 	fd = open("Hellotest.txt", O_RDONLY);
// 	while (line = get_next_line(fd))
// 	{
// 		printf("%d->%s\n", lines++, line);
// 	}
// }