/*
 * question5.c
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

/** fonction qui retourne le nombre de cases appartenent à un joueur*/
int nombrecases (char joueur)
{
	int casesjoueur = 0 ;
	int i,j ;
	for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
			if (board[j+i*BOARD_SIZE]==joueur) {
				casesjoueur = casesjoueur + 1 ;
			}
		}
	}
	return (casesjoueur/9);
}
	

/** Un joueur joue, mise à jour du tableau*/
void tourjoueur(char joueur)
{
	printf("c'est le tour du joueur %c ;",joueur);
	printf ("donner une couleur\n");
	char couleur = 'A';
	scanf("%c",&couleur);
	char vide ='A';
	scanf("%c",&vide);
	int a = 0; 		/**bouléen*/
	while (a==0) {
		int b=0;
		int i , j ;
		for (i = 0; i<BOARD_SIZE; i++) {
			for (j = 0; j<BOARD_SIZE; j++) {
				if (board[j + BOARD_SIZE*i]==couleur){
					if (i==0 && j==0) { 
						if (board[1]==joueur || board[BOARD_SIZE]==joueur){
							b=1;
							set_cell(0,0,joueur);
						}
					}

					if (i==0) { 
						if (board[j+1]==joueur || board[j-1]==joueur || board[j+BOARD_SIZE]==joueur){
							b=1;
							set_cell(i,j,joueur);
						}
					}
					else if (j==0) { 
						if (board[j+BOARD_SIZE*i+1]==joueur || board[j+BOARD_SIZE*i+BOARD_SIZE]==joueur|| board[j+BOARD_SIZE*i-BOARD_SIZE]==joueur) {
							b=1;
							set_cell(i,j,joueur);
						}
					}
					else if (i==BOARD_SIZE-1 && j==BOARD_SIZE-1) { 
						if (board[j+i*BOARD_SIZE-1]==joueur || board[j+i*BOARD_SIZE-BOARD_SIZE]==joueur){
							b=1;
							set_cell(i,j,joueur);
						}
					}

					else if (i==BOARD_SIZE) { 
						if (board[j+i*BOARD_SIZE-1]==joueur || board[j-i*BOARD_SIZE-BOARD_SIZE]==joueur || board[j-i*BOARD_SIZE+BOARD_SIZE]==joueur){
							b=1;
							set_cell(i,j,joueur);
						}
					}
					else if (j==BOARD_SIZE) { 
						if (board[j+BOARD_SIZE*i+1]==joueur || board[j+BOARD_SIZE*i-1]==joueur|| board[j+BOARD_SIZE*i-BOARD_SIZE]==joueur){
							b=1;
							set_cell(i,j,joueur);
						}
					}
					else {
						if (board[j+BOARD_SIZE*i+1]==joueur || board[j+BOARD_SIZE*i-1]==joueur|| board[j+BOARD_SIZE*i-BOARD_SIZE]==joueur || board[j+BOARD_SIZE*i+BOARD_SIZE]==joueur) {
							b=1;
							set_cell(i,j,joueur);
						}
					}
					
				}	
			}		
		}
		if (b==0) {a=1;}
	}				
	
	printf("Current board state :\n");
	int i , j ;
	for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
			printf("%c",board[j+BOARD_SIZE*i]);   
		}
		printf("\n");
	}
	printf("joueur 0 : %d  ; joueur 1 : %d  \n", nombrecases('0') , nombrecases('1'));

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
				set_cell(i,j,'0');
				printf("0");
					}
			else if (i==BOARD_SIZE-1 && j==0) {
				printf("1");
				set_cell(i,j,'1');
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

    while (nombrecases('0')<50 && nombrecases('1')<50) {
		tourjoueur('0');
		tourjoueur('1');
	}
	
	printf ("pourcentage joueur 0 : %d ; pourcentage joueur 1 : %d \n" , nombrecases('0'),nombrecases('1'));

    return 0; // Everything went well
}
