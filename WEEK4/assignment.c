#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);
   
    return 0;
}

int solveMaze(char **maze, const int HT, const int WD, int x, int y){

    // solve recursively
    // however you might want to mark wrong paths with some other character
    // your functions should be able to solve other such mazes
    // pay attention to the bounds of the arrays
    // make sure you don't enter an infinite recursion

	if(y < 0 || x < 0 || x > HT - 1 || y > WD - 1 )
		return 0;  //To make sure that we do not go out of the boundaries 
	if(maze[x][y] == '#' || maze[x][y] == '.')
		return 0;  //It will stop if the path confronts a block("#"), or the previous path(".")
    
	if(maze[x][y] == '*')
		return 1;  //It will stop when we reach at the destination where "*" symbol is located

	maze[x][y] = '.';   //If any of the statements above are not true, we will mark our path with "." symbol


    //The codes below solve it recursively by checking all the possible ways of getting to the destination
	if(solveMaze(maze, HT, WD, x+1, y)) return 1;
	else if(solveMaze(maze, HT, WD, x-1, y)) return 1;
	else if(solveMaze(maze, HT, WD, x, y+1)) return 1;
	else if(solveMaze(maze, HT, WD, x, y-1)) return 1;

    //if all the ways are blocked it will put an "x" mark and then go back and try another way
	maze[x][y] = 'x';
	return 0;
}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
}

