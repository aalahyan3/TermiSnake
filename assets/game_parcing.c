/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_parcing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:23:34 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/02 23:26:02 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/snake_game.h"

void	place_food(t_food *food, t_board *board, t_snake *snake)
{
	int	rand_x;
	int	rand_y;
	rand_x = rand() % (board->cols - 2) + 1;
	rand_y = rand() % (board->rows - 2) + 1;
	while (!snake_is_safe(snake, rand_x, rand_y))
	{
		rand_x = rand() % (board->cols - 2) + 1;
		rand_y = rand() % (board->rows - 2) + 1;
	}
	food->x = rand_x;
	food->y = rand_y;
}

void	parse_game(t_board *board, t_snake *snake, t_food food, char d)
{
	if (d == 'W')
	{
		move_snake(snake, -1, 0);
		fill_board(board, food);
		put_snake_in_board(snake, board);
		draw_board(board);
	}
	if (d == 'N')
	{
		move_snake(snake, 0, -1);
		fill_board(board, food);
		put_snake_in_board(snake, board);
		draw_board(board);
	}
	if (d == 'E')
	{
		move_snake(snake, 1, 0);
		fill_board(board, food);
		put_snake_in_board(snake, board);
		draw_board(board);
	}
	if (d == 'S')
	{
		move_snake(snake, 0, 1);
		fill_board(board, food);
		put_snake_in_board(snake, board);
		draw_board(board);
	}
}