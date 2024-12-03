/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:20:47 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/02 23:22:55 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/snake_game.h"

void	put_snake_in_board(t_snake *snake, t_board *board)
{
	t_body	*curr;

	curr = snake->head;
	board->board_buffer[curr->y][curr->x] = '&';
	curr= curr->next;
	while (curr)
	{
		board->board_buffer[curr->y][curr->x] = '*';
		curr = curr->next;
	}
}

t_body	*new_snake_segment(int x, int y, int i)
{
	t_body	*segment;

	segment = malloc(sizeof(t_body));
	if (!segment)
		return (NULL);
	segment->x = x;
	segment->y = y;
	segment->i = i;
	segment->next = NULL;
	return (segment);
}

void	init_snake_position(t_snake *snake, t_board *board)
{
	t_body	*curr;
	t_body	*segment;
	snake->head->x  = board->cols - board->cols / 2;
	snake->head->y  = board->rows - board->rows / 2;
	snake->head->i = 0;
	snake->head->next = NULL;
	curr = snake->head;
	for (int i = 1; i <= snake->lenght; i++)
	{
		segment = new_snake_segment( curr->x + 1, curr->y, i);
		if (!segment)
		{
			free_snake(snake);
			return ;
		}
		curr->next = segment;
		curr = curr->next;
	}
}

void	move_snake(t_snake *snake, int dx, int dy)
{

	t_body	*curr;
	int		prev_x;
	int		prev_y;
	int		temp;

	curr = snake->head;
	prev_x = curr->x;
	prev_y = curr->y;
	curr->x += dx;
	curr->y += dy;
	while (curr->next)
	{
		curr = curr->next;
		temp = curr->x;
		curr->x = prev_x;
		prev_x = temp;
		temp = curr->y;
		curr->y = prev_y;
		prev_y = temp;
		
	}
}

void	increase_snake_lenght(t_snake *snake, char d)
{
	t_body *segment;
	t_body *tmp;
	int	dx, dy;

	segment = malloc(sizeof(t_body));
	if (!segment)
		return ;
	if (d == 'W')
	{
		dx = -1;
		dy = 0;
	}
	else if (d == 'E')
	{
		dx = 1;
		dy = 0;
	}
	else if (d == 'S')
	{
		dx = 0;
		dy = 1;
	}
	else if (d == 'N')
	{
		dx = 0;
		dy = -1;
	}
	segment->x = snake->head->x + dx;
	segment->y = snake->head->y + dy;
	tmp = snake->head;
	snake->head = segment;
	segment->next = tmp;
	snake->lenght += 1;
}