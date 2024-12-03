/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:36:25 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/03 15:26:16 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/snake_game.h"

/*
just for leaks checking ...

void check_leaks(void)
{
	system("leaks a.out");
}
*/

int main(void)
{
	t_snake	*snake;
	t_board	*board;
	t_food	food;
	int		score;
	int		level;
	char	ch;
	char	direction;

	board = malloc(sizeof(t_board));
	snake = malloc(sizeof(t_snake));
	if (!snake || !board)
		return (1);
	snake->lenght = 3;
	snake->head = malloc(sizeof(t_body));
	if (!snake->head)
		return (4);
	board->board_buffer = NULL;
	printf(BRIGHT_CYAN"Welcome To Termisnake\n"RESET);
	printf(YELLOW"Number of culumns (width): "RESET);
	scanf("%d", &board->cols);
	printf(YELLOW"Number of rows (height): "RESET);
	scanf("%d", &board->rows);
	printf(YELLOW"Game Difficulty (1 - 9): "RESET);
	scanf("%d", &level);
	if (!valid_dimentions(board->cols, board->rows))
	{
		perror("invalid dimentions");
		return (3);
	}
	if (level >= 10 || level <= 0)
	{
		perror("Invalid Level : range 1 - 9");
		return (5);
	}
	init_snake_position(snake, board);
	fill_board(board, food);
	put_snake_in_board(snake, board);
	draw_board(board);
	direction = 'W';
	score = snake->lenght;
	place_food(&food, board, snake);
	printf("Pres ENTER to start The Game!");
	getchar();
	getchar();
	while (!game_over(board, snake))
	{
		if (kbhit())
		{
			ch = getchar(); 
			if (ch == '\033')
			{
				ch = getchar();
				if (ch == '[')
				{
					ch = getchar();
					if (ch == 'A')
					{
						if (direction != 'S')
							direction = 'N';
					}
					else if (ch == 'B')
					{
						if (direction != 'N')
							direction = 'S';
					}
					else if (ch == 'C')
					{
						if (direction != 'W')
							direction = 'E';
					}
					else if (ch == 'D')
					{
						if (direction != 'E')
							direction = 'W';
					}
				}
			}
		}
		parse_game(board, snake, food, direction);
		if (is_food_taken(food, snake))
		{
			increase_snake_lenght(snake, direction);
			place_food(&food, board, snake);
			score += snake->lenght * level;
		}
		printf(BOLD_BLUE"###########################################\n"RESET);
		printf(BOLD_BLUE"# ");
		printf(BOLD_GREEN"%-12s: %-4d "RESET, "Score", score);
		printf(BOLD_BLUE"# "BOLD_GREEN "%-12s: %-4d"RESET, "Level", level);
		printf(BOLD_BLUE" #\n");
		printf(BOLD_BLUE"# ");
		printf(BOLD_GREEN"%-12s: %-4d ", "Snake lenght", snake->lenght);
		printf(BOLD_BLUE"# "BOLD_GREEN "%-12s: %-4d"RESET, "Checkpoints", snake->lenght - 3);
		printf(BOLD_BLUE" #\n");
		printf(BOLD_BLUE"###########################################\n"RESET);
		usleep(100000 * (5 - level / 2));
		clear_screen();
	}
	printf(BRIGHT_CYAN"===========================================\n");
	printf(BRIGHT_CYAN"== GAME_OVER\tScore: %d\tLevel: %d ==\n", score, level);
	printf(BRIGHT_CYAN"===========================================\n"RESET);
	free(board);
	free_snake(snake);
	
	//uncomment for leaks check : if you have leaks tool in your machine
	//atexit(check_leaks);
	
}