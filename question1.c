/*
 * question1.c
 * 
 * Copyright 2017 Bourion <bourion@bourion-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 30

/** Represent the actual current board game
 *
 * NOTE: global variables are usually discouraged (plus encapsulation in
 *     an appropriate data structure would also be preferred), but don't worry.
 *     For this first assignment, no dinosaure will get you if you do that.
 */
char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros

/** Retrieves the color of a given board cell */
char get_cell(int x, int y)
{
    return board[y + BOARD_SIZE * x];
}

/** Changes the color of a given board cell */
void set_cell(int x, int y, char color)
{
    board[y + BOARD_SIZE* x] = color;
}

/** Prints the current state of the board on screen
 *
 * Implementation note: It would be nicer to do this with ncurse or even
 * SDL/allegro, but this is not really the purpose of this assignment.
 */
void print_board(void)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
			if (i==0 && j==BOARD_SIZE-1) {			/** mettre des 0 dans les bords initiaux apparteanant aux joueurs*/
				printf("0");
					}
			else if (i==BOARD_SIZE-1 && j==0) {
				printf("1");	
			}
			else {
			int a = rand() % 6;
			char b='A'+a;
			set_cell(i,j,b);
            printf("%c", get_cell(i, j));
		}}
        
        printf("\n");
    }

}

int main(int argc, char **argv)
{
	    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");

    print_board();

    return 0; // Everything went well
}

