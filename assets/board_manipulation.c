/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:13:08 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/03 00:46:41 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/snake_game.h"

char	*get_line_to_board(t_board *board, int n_line)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (board->cols + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	for (int j = 0; j < board->cols; j++)
	{
		if (j == 0 || j == board->cols - 1)
		 	ptr[i++] = '#';
		else if (n_line == 0 || n_line == board->rows - 1)
			ptr[i++] = '#';
		else
			ptr[i++] = ' ';
	}
	ptr[i] = 0;
	return (ptr);
}

void	fill_board(t_board *board, t_food food)
{
	int 	i;
	char	*ptr;

	board->board_buffer = malloc(sizeof(char *) * board->rows);
	if (board->board_buffer == NULL)
		return ;
	for ( int x = 0; x < board->rows; x++)
	{
		ptr = get_line_to_board(board, x);
		if (!ptr || !board)
			return ;
		board->board_buffer[x] = ptr;
	}
	board->board_buffer[food.y][food.x] = '+';
}

void	draw_board(t_board *board)
{
	char	c;
	for (int x = 0; x < board->rows; x++)
	{
		for (int y = 0; y < board->cols; y++)
		{
			c = board->board_buffer[x][y];
			if (c == '#')
			{
				printf(BOLD_BLUE);
				putchar(c);
			}
			else if (c == '+')
			{
				printf(BOLD_GREEN);
				putchar(c);
			}
			else
			{
				printf(BOLD_YELLOW);
				putchar(c);
			}
		}
		putchar('\n');
	}
	free_board_buffer(board);
	printf(RESET);
}
