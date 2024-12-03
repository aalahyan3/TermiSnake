/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:34:00 by aalahyan          #+#    #+#             */
/*   Updated: 2024/12/03 00:46:31 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_GAME_H
#define	SNAKE_GAME_H

# include <stdio.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
#include <fcntl.h>

/*Typedefs*/
typedef	struct s_body
{
	int	x;
	int	y;
	int	i;
	struct s_body	*next;
}	t_body;

typedef struct s_snake
{
	int		lenght;
	t_body	*head;
}	t_snake;

typedef struct s_board
{
	char	**board_buffer;
	int		cols;
	int		rows;
}	t_board;


typedef struct s_food
{
	int	x;
	int	y;
}	t_food;

/*Macros*/
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BRIGHT_CYAN "\033[96m"
#define BOLD_BLUE   "\033[1;34m"
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_YELLOW    "\033[1;33m"
#define BOLD_BLUE    "\033[1;34m"

/*prototypes*/

int 	kbhit(void);
void	free_snake(t_snake *snake);
void	free_board_buffer(t_board *board);
char	*get_line_to_board(t_board *board, int n_line);
void	fill_board(t_board *board, t_food food);
void	draw_board(t_board *board);
int		valid_dimentions(int cols, int rows);
int		snake_is_safe(t_snake *snake, int x, int y);
int		is_snake_bite_himself(t_snake *snake, int x, int y);
int		is_food_taken(t_food food, t_snake *snake);
int		game_over(t_board *board, t_snake *snake);
void	put_snake_in_board(t_snake *snake, t_board *board);
t_body	*new_snake_segment(int x, int y, int i);
void	init_snake_position(t_snake *snake, t_board *board);
void	move_snake(t_snake *snake, int dx, int dy);
void	increase_snake_lenght(t_snake *snake, char d);
void	place_food(t_food *food, t_board *board, t_snake *snake);
void	parse_game(t_board *board, t_snake *snake, t_food food, char d);
void 	clear_screen(void);
#endif