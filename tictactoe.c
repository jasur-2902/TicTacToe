/******************************************************************************

						Student: Jasur Shukurov
						Professor: Saleh Aliyari
						Class: CSC 270-002: Survey of Programming Languages
							
*******************************************************************************/

//Importing libraries 
#include <stdio.h>
#include <stdlib.h> // importing stdlib to generate random number 

const int y_side = 3; // constant the size of side 
const int x_side = 3; // constant the size of side 
const char X_move = 'X'; // constant for user move 
const char O_move = 'O'; // constant for computer move 

int gameOver = 0; // variable to check game is over 

// Function Declaration 
int isFull(char array[x_side][y_side]); 
void printBoard(char array[x_side][y_side]); 
int checkCell(int a, int b, char array[x_side][y_side]);
int determineWinner (char array[x_side][y_side]); 


// Driver Method 
int main(void)
{
    // Creating Board of size 3 to 3 
    char array[3][3] = {'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'}; 

    // Variables to store a random genrated number for computer's move
    int computer_move_x; 
    int computer_move_y;
    
    printf("Tic Tac Toe\n"); // Printing game's title 
    
    char input; // Variable to store user input
    
    int win = 0; // Variable to check the winner 
    
    int cellEmpty = 1; // Variable to check if the cell is buss or empty 
  
    // While loop which will run until game is ended 
    while(win == 0){
      printBoard(array); // printing board 
        
        // Getting user input 
        printf("Please select one block: \n");
        scanf(" %c", &input);
        
      // Adding user choice to the board 
      for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
              if(array[i][j] == input){
                  array[i][j] = X_move;
              }
          }
      }

        win = determineWinner(array); // Checking if user won

        // Checking if the board is full 
        if(isFull(array) == 1 && win == 0){
          cellEmpty = 0; // changing cellEmpty value to 0 to stop while loop below 
          win = 1; // chaning win to 1 to stop game 
          gameOver = 1; // changin gameOver to 1 

          printf("Game Over!\n");
        }

        // Checking if computer selected an empty cell         
        while(cellEmpty == 1 && win == 0){
          computer_move_y = rand() % x_side; // randomly generating number in range of 3 
          computer_move_x = rand() % y_side; // randomly generating number in range of 3

          // if cell is empty then i'm changing cellEmpty value to 0 to stop loop
          if(checkCell(computer_move_x, computer_move_y,  array) == 0)
            cellEmpty=0; 
        }

        // Having executed, chaning the cellEmpty to standard value to 1 
        cellEmpty = 1;

        // Adding computer's move to the board 
        array[computer_move_x][computer_move_y] = O_move;
        
        // Checking for winner 
        win = determineWinner(array);

    }

    // Printing board after the game ended 
    printBoard(array);

    
    // Checking who won 
    if(win == 1 && gameOver == 0 ){
      printf("X won, Congratulations!\n"); // if user won, printing Congratulations
    } else if (gameOver == 0){
      printf("Game Over, O won!\n");
    }
    
    return 0;
}

/**
* determineWinner: the method which will generate a random number in range 
* precondition: board created 
*
* @param: char array - 2D array board 
* @return: int - 1 if user won, 2 if the computer won and 0 if no one 
*
*/
 int determineWinner (char array[x_side][y_side]){
      
    // If the game is over after user move it returns 1 
    if(gameOver == 1){
      return 1;
    }

    // Checking horizontally and vertically 
    for(int i = 0; i < 3; i++){
      if(array[i][0] == X_move && array[i][1] == X_move && array[i][2] == X_move)
          return 1;
      else if(array[i][0] ==  O_move && array[i][1] == O_move && array[i][2] == O_move)
          return 2;
      else if(array[0][i] == X_move && array[1][i] == X_move && array[2][i] == X_move)
          return 1;
      else if(array[0][i] == O_move && array[1][i] == O_move && array[2][i] == O_move)
          return 2;    
      }

    // Checking diagonally 
    if(array[0][0] == X_move && array[1][1] == X_move && array[2][2] == X_move)
      return 1;
    else if(array[0][0] == O_move && array[1][1] == O_move && array[2][2] == O_move)
       return 2;
    else if(array[0][2] == X_move && array[1][1] == X_move && array[2][0] == X_move)
      return 1;
    else if(array[0][2] == O_move && array[1][1] == O_move && array[2][0] == O_move)
      return 1;

    // if there is no winner yet returns 0 
    return 0;   
}

/**
* printBoard: the method which will print the board  
* precondition: array for the board is created 
* postcondition: board is printed 
*
* @param: char array - 2D array board 
*/
void printBoard(char array[x_side][y_side]){
          for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("| %c |",array[i][j]);
            }
            printf("\n");
        }
}

/**
* checkCell: checking if the cell is empty to move 
* precondition: board created 
* @param: a - horizontal location of the cell 
* @param: b - vertical location of the cell
* @param: char array - 2D array board 

* @return: int, returns 1 if cell is empty, otherwise 0 
*/
int checkCell(int a, int b, char array[x_side][y_side]){
  
  // Checking if cell is empty 
  if(array[a][b] == X_move || array[a][b] == O_move)
    return 1;
    
  return 0; // returning 0 if cell is empty 
}

/**
* isFull: checking if the board is full or not 
* precondition: board created 
*
* @param: char array - 2D array board 
*
* @return: int, returns 1 if board is full, otherwise 0 
*/
int isFull(char array[x_side][y_side]){
  int count = 0; // count to count full cells 

  // Counting how many cells are full
  for(int i = 0; i < x_side; i++){
    for(int j = 0; j < x_side; j++){
      if(array[i][j] == X_move || array[i][j] == O_move)
        count++;
    }
  }

  // if all 9 cells are full then board is full 
  if(count == 9){
    return 1;
  }
  
  return 0; 
}

