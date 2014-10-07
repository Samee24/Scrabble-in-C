#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h> 

//frequently used variables used as globals
int num_row;
int num_column;
int i;
int j;
int rand(void);
//Keep track of moves (mostly for first move)
int count;
//For random
int randCount;


//Longest word in the dictionary
char word[45];
char identifier;


/*Preconditions: identifier must be a valid char with value
either 'V' or 'H'. Grid must also be valid.
Postconditions: sets grid[j][i] to word[k].
*/
void setWord(char identifier, char grid[][num_row]) {


//set respective word
  for (int k = 0; k < strlen(word); k++)
  {
      grid[j][i] = word[k];

     if (identifier == 'H'){
     j++;
    }
    else i++;
  }

}

/*Preconditions: Grid must be valid.
Postconditions: prints the value at each box in the grid.
*/


void printGrid (char grid[][num_row]) {
 //print the grid
  for (int l = 0; l < num_row; l++)
      {
        for (int p = 0; p < num_column; p++)
        {
          //add spacef for readibility 
          printf ("%c  ", grid[p][l]);
        }
        printf ("\n");    
        }

}

/* check if the given word can be added horizontally at the given location
   pre-conditions
      row is a valid row location within the grid
      col is a valid column location within the grid
      word is a valid string
      num_rows is the total number of rows in the grid
      num_cols is the total number of columns in the grid
      grid is the two-dimensional array representing the grid
   post-conditions
      returns true (i.e., 1) if the word can be added to the grid
              horizontally with the first letter at the given row and col
      returns false (i.e., 0) otherwise
      the grid is NOT changed
*/
int check_horizontal (char * word, int row, int col, int num_rows,
                      int num_cols, char grid[num_cols][num_rows]) {

int length = strlen(word);
char check = 'F';
char check2 = 'T';

int k;

//printf("strlen = %d  count = %d \n", length, count);

//Check whether word is within bounds of grid
if (num_cols - col >= length && row < num_rows) {

for (k = 0; k < length; k++) {
   //printf("k=%d word[k] = %c, grid[col][row] = %c \n", k, word[k], grid[col][row]);


  //Add or filter for first move, so that word can be placed anywhere 
  if (grid[col][row] == word[k] || count == 0){

      //printf("grid[col][row] = %c  word[k]= %c \n", grid[col][row],  word[k]);
      check = 'T';

      //printf("count = %d check = %c, check2 = %c, INT k = %d,char = %c, row = %d, col = %d\n",count, check ,check2, k, word[k], row,
      //col);


    }

    //Skip if blank space
    else if (grid[col][row] == ' ') {
      //DO NOTHING

    }

     else {

      check2 = 'F';
      // printf("grid[col][row] =%c check = %c, check2 = %c, INT k = %d,char = %c, row = %d, col = %d\n",grid[col][row], check ,check2, k, word[k], row,
      //col);
    }


//Since, horizontal, we only want to increment the column
col++;
      }
  
//printf("done with loop %c \n", word[k]);

}

if (check == 'T' && check2 == 'T'){

    //printf("Finalcheck = %c\n", check);
    return 1;
  }

  else {
    return 0;
  }


 

}

/* check if the given word can be added horizontally at the given location
   pre-conditions
      row is a valid row location within the grid
      col is a valid column location within the grid
      word is a valid string
      num_rows is the total number of rows in the grid
      num_cols is the total number of columns in the grid
      grid is the two-dimensional array representing the grid
   post-conditions
      returns true (i.e., 1) if the word can be added to the grid
              vertically with the first letter at the given row and col
      returns false (i.e., 0) otherwise
      the grid is NOT changed
*/

int check_vertical (char * word, int row, int col, int num_rows,
                      int num_cols, char grid[num_cols][num_rows]) {

int length = strlen(word);
char check = 'F';
char check2 = 'T';
int k;


//printf("strlen = %d  count = %d \n", length, count);
if (num_rows - row >= length && col < num_cols){


  for (k = 0; k < length; k++) {
   // printf("k=%d word[k] = %c, grid[col][row] = %c \n", k, word[k], grid[col][row]);





    if (grid[col][row] == word[k] || count == 0){


      //printf("grid[col][row] = %c  word[k]= %c \n", grid[col][row],  word[k]);
          check = 'T';
         // printf("count = %d check = %c, check2 = %c, INT k = %d,char = %c, row = %d, col = %d\n",count, check ,check2, k, word[k], row,
        //col);



      }

      else if (grid[col][row] == ' ') {

        //DO NOTHING

      }

      else  {

        check2 = 'F';
        // printf("grid[col][row] =%c check = %c, check2 = %c, INT k = %d,char = %c, row = %d, col = %d\n",grid[col][row], check ,check2, k, word[k], row,
        //col);
        
       

      }



           row++;

}


}

if (check == 'T' && check2 == 'T'){

   //printf("Finalcheck = %c\n", check);
    return 1;
  }

  else {
    
    return 0;
  }


}



/*Preconditions:
  -Grid must be valid.
  -row and column must be valid integers that represent a VALID position 
  in the grid.
 Postcondtions:
  - Checks whether word[global] can fit into the the grid at the given 
    position. If yes, then runs setWord, and prints grid.
    If not, prints an error statement. 

  This function acts as a controller, which takes the parameters (plus globals)
  and sets the logic structure for the program.

  */

void checkPlacement (char grid[num_column][num_row], int row, int column) {


//Case if user asks the word to be placed horizontally
 if (identifier == 'H') {

  if (check_horizontal (word, i, j, row, column, grid)){ 
  setWord(identifier, grid);
  printGrid(grid);

} else {
    if (count == 0){
      count = -1;
    }
    else printf ("Word can't be placed horizontally!");
  }
  }

//Case if user asks the word to be placed vertically
  else if (identifier == 'V') {

  if (check_vertical (word, i, j, row, column, grid)){

  setWord(identifier, grid);
  printGrid(grid);
 }
  else {
    if (count == 0){
      count = -1;
    }
    else printf ("Word can't be placed vertically!");
  }
  }
//Case if user asks enters an invalid identifier
  else {

      if (count == 0){
      count = -1;
    }

      printf ("Please choose a valid identifier");
  }

  }


 

/*Preconditions:
  -Grid must be valid.
  -row and column must be the grid's number of rows and number of columns.

 Postcondtions:
  - A randomized (Valid) position is assigned to word on grid. 

  This function first chooses whether to place the word vertically or
  horizontally (randomly), and then creates an array of structs. Then
  it loops through the grid, finding valid positions. For every valid
  position, the i,j values are stored in the array. Afterward, a random
  i,j value is chosen from the array, fed into setWord and then printGrid.
  */
 void checkRandom (char grid[num_column][num_row], int row, int column) {


srand (time(NULL));

//randomize to place a word vertically or horizontally 
  int randVH = rand() % 2;

  if (randVH == 1){
    identifier = 'H';
  } else identifier = 'V';


//A struct will be used to keep track of valid positions

struct randomVal
{
     int row;
     int col;
};

//Initialize struct array
struct randomVal random[row * column];

int arrayIndex = 0;


//For H, check_horizontal is used to see if word can be placed horizontally anywhere.
  if (identifier == 'H'){


    for (int l = 0; l < row; l++)
      {
        for (int p = 0; p < column; p++)
        {
          if (check_horizontal (word, l, p, row, column, grid)){

            //A valid positions is found, so store it.
            random[arrayIndex].row = l;
            random[arrayIndex].col = p;

            //the index also keeps track of how many positions have been found
            arrayIndex++;


          }
        }
        printf ("\n");    
        }
      } else {
//For V check_vertical is used to see if word can be placed vertically anywhere.


        for (int l = 0; l < row; l++)
      {
        for (int p = 0; p < column; p++)
        {
          if (check_vertical (word, l, p, row, column, grid)){

            random[arrayIndex].row = l;
            random[arrayIndex].col = p;

            arrayIndex++;


          }
        }
        printf ("\n");    
        }

      }


        //printf("randomPosition = %i %i \n", random[0].row, random[0].col);


/*The following part of the procedure check if the previous code found any valid
positions or not */

      if (arrayIndex == 0){

/*If a position isn't found, try the other way (vertical, if previously was horizontal
  and vice versa)*/

            if (identifier == 'V') {
              for (int l = 0; l < row; l++){
            
            for (int p = 0; p < column; p++)
            {
              if (check_horizontal (word, l, p, row, column, grid)){

                random[arrayIndex].row = l;
                random[arrayIndex].col = p;

                arrayIndex++;


              }
            }
            printf ("\n");    
            }

            identifier ='H';

            }

            else if (identifier == 'H'){

               for (int l = 0; l < row; l++){
          
            for (int p = 0; p < column; p++)
            {
              if (check_vertical (word, l, p, row, column, grid)){

                random[arrayIndex].row = l;
                random[arrayIndex].col = p;

                arrayIndex++;


              }
            }
            printf ("\n");    
            }

            identifier ='V';


            }

           
      } 

      //Check again if second attempt yielded any valid positions

      if (arrayIndex > 0) {
      //+ 1 prevents x % 0;


      int randArray = rand() % arrayIndex;
      

      i = random[randArray].row;
      j = random[randArray].col;

      //printf("randomPosition = %i %i, arrayIndex = %d, randArray = %i\n", i, j, arrayIndex, randArray);

      setWord(identifier, grid);
      printGrid(grid);

    } else {

      //If word camnot definitely be placed on the grid, give error
       printf("That word can't be placed anywhere. \n");

    }
  
 }





int main ()
{
  printf ("How many rows and columns do you want? \n");

  scanf  ("%d", &num_row);
  scanf ("%d", &num_column);

  char grid [num_column][num_row];

  for (int l = 0; l < num_row; l++)
  {
    for (int p = 0; p < num_column; p++)
    {
      grid[p][l] = ' ';
      //printf ("  ");
    }

    //printf ("\n");
  }

  //Variables to check for newline
  char end;
  char end2;

  while (1){
  printf ("\nEnter a word, identifier, and i,j (if required). Type QUITQUIT to quit. \n");

  scanf  ("%s", word);

  //Check for newline, and then quit if word == QUITQUIT
  scanf ("%c", &end); 

  if (end == '\n' && strcmp(word, "QUITQUIT") == 0) {
      break;

  }


  scanf ("%c", &identifier);
  scanf ("%c", &end2); 


//Allows the user to hit enter after entering R (does not force user to enter i and j)
  if (end2 != '\n' && identifier != 'R') {
  
  scanf ("%d", &i);//row
  scanf (" %d", &j);//column

}

//Checks for random case
  if (identifier == 'R') {


   checkRandom(grid, num_row, num_column);
  } else {
    //Checks for non-R cases
      checkPlacement(grid, num_row, num_column);

  }

    printf ("\n");

//Increment as turn ends
    count++;
  
  
}

          return 0;
}







