/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:28:52 by mshazaib          #+#    #+#             */
/*   Updated: 2023/09/05 19:24:47 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
# endif

typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				copy_str(t_list *list, char *str);
int					len_to_newline(t_list *list);
void				polish_list(t_list **list);
t_list				*find_last_node(t_list *list);
int					found_newline(t_list *list);
void				cleanlists(t_list **list, t_list *clean_node, char *buf);
void				copy_str(t_list *list, char *str);
char				*get_lines(t_list *list);

#endif
