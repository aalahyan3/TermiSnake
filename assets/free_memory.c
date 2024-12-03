/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:10:55 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/02 23:12:35 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/snake_game.h"

void	free_snake(t_snake *snake)
{
	t_body	*tmp;
	while (snake->head)
	{
		tmp = snake->head->next;
		free(snake->head);
		snake->head = tmp;
	}
	free(snake);
}

void	free_board_buffer(t_board *board)
{
	for (int i = 0; i < board->rows; i++)
		free(board->board_buffer[i]);
	free(board->board_buffer);
}