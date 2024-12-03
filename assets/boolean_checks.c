/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:17:29 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/02 23:19:59 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/snake_game.h"

int	valid_dimentions(int cols, int rows)
{
	if (cols < 10 || cols >= 151)
	{
		perror("columns range 10 - 150");
		return (0);
	}
	else if (rows < 10 || rows >= 51)
	{
		perror("rows range 10 - 50");
		return (0);
	}
	return (1);
}

int	snake_is_safe(t_snake *snake, int x, int y)
{
	t_body *curr = snake->head;
	while (curr)
	{
		if (curr->x == x && curr->y == y)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_snake_bite_himself(t_snake *snake, int x, int y)
{
	t_body *curr = snake->head->next;
	while (curr)
	{
		if (curr->x == x && curr->y == y)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_food_taken(t_food food, t_snake *snake)
{
	if (snake->head->x == food.x && snake->head->y == food.y)
		return (1);
	return (0);
}

int	game_over(t_board *board, t_snake *snake)
{
	int	snake_x, snake_y;

	snake_x = snake->head->x;
	snake_y = snake->head->y;

	if (snake_x <= 0 || snake_x >= board->cols - 1 || snake_y <= 0 || snake_y >= board->rows - 1)
		return (1);
	if (!is_snake_bite_himself(snake, snake_x, snake_y))
		return (1);
	return (0);
}