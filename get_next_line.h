/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:28:52 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/13 16:32:02 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif



typedef struct s_list
{
	char			*content;
	int				length;
	int				remaining;
	struct s_list *next;
}					t_list;



char get_next_line(int fd);









#endif
