/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:49:43 by mpetruno          #+#    #+#             */
/*   Updated: 2019/03/05 19:08:08 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include "libft.h"
# include "hashmap.h"

# define S_ANT	0
# define S_ROOM	1
# define S_LINK	2

# define L_ANT	0
# define L_ROOM	1
# define L_LINK	2
# define L_CMD	3
# define L_ERR	4
# define L_COMM	5

# define NODE(X) (t_node *)X

typedef struct s_adj_lst	t_adj_lst;

typedef struct	s_node
{
	char		*id;
	int			x;
	int			y;
	t_adj_lst	*adj;
}				t_node;

struct			s_adj_lst
{
	t_node		*node;
	t_adj_lst	*next;
};

typedef struct		s_farm
{
	int				ants_number;
	t_node			*start;
	t_node			*end;
	t_hashmap		*map;
}					t_farm;

typedef int			(*t_inp_func)(char *str);

typedef struct		s_state_trans
{
	int				state;
	t_inp_func		func;
}					t_state_trans;


/*
** farm.c
*/
int				make_farm(void);

/*
** node.c
*/
t_node			*init_node(const char *str);
void			free_node(t_node *node);

/*
** farm_lex.c
*/
int					set_ants(char *str);
int					set_room(char *str);
int					set_link(char *str);
int					set_cmd(char *str);
int					set_err(char *str);

#endif
