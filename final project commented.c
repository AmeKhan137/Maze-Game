//Ameem Khan
//114859871
//FINAL PROJECT TASK 1

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#define MAXR 11      //rows
#define MAXC 10    //cols
#define MAXPOINT 9   //point

char Maze [MAXR][MAXC]; //initialize the maze 2d array out here because i use it in all of my code including functions (could have done pointer but this is easier)


void print_maze(){
	int i, j;
	for (i = 0; i < MAXR; i++){
		for (j = 0; j < MAXC; j++)       //prints it by first assigning a row then iterating through the column and placing it inside that row until it reaches the desired lenght (11) is found
			printf ("%c", Maze[i][j]); 
		printf("\n");	                //this \n seperates each row
	}
}



void point_value(int *val)
{
	while (1)
	{
	*val = rand() % (MAXPOINT + 1);      //generates from 1-9 for my points
	if (*val != 0)                     //uses pointer to make sure it changes value in main loop
	{                               //makes sure that the value generated is not a 0
		break;
	}
}

}


void randomlocation(int *x, int *y)
{
	
	
	while (1){
	
		*x = rand() % (MAXR + 1);          //uses pointers because it needs to change the actual value f my variable in main loop
		*y = rand() % (MAXC + 1);             //this function is to generate random coordinates for my maze
	if (Maze[*x][*y]==' ')                    //its in a while 1 loop to ensure that the coords dont lead to a * or point
	{
		                                       //uses rand function to generate a number from  the seed  that is between 0-10 for column and 0-11 for row
		break;}                           
		}
}


int main() {
	
    FILE *f;
	int row_index = 0, col_index = 0; //initialize index variables so that i can save my file into a 2d array
	char c;                          //this will be the char that holds each variable taken from file
	int cur_row = 0;               //intitalize my current position as 0,0 for now
	int cur_column = 0;
	int pointx = 0;
	int pointy = 0;   //intialize my current point location at 0,0 for now

	int *x = &cur_row;         //use pointers to point to my location variable
	int *y = &cur_column;
	int *p = &pointx;
	int *p2 = &pointy;
	int pointval = 0;         //initalize my point as 0 for now
	int *val = &pointval;      //make it a pointer for later
	
														// read the maze from a file into a 2D array
    if ((f = fopen ("ant_maze.txt", "r")) != NULL){
		while ((c = fgetc(f)) != EOF) {
		  if (c == '\n') {	
		    row_index++;
		    col_index = 0;                            //works by reading file taking each char and placing it into a column index until a \n is found in which it increments the row index and re-intializes the colmumn index to 0
	 	  }
		  else{
		  	Maze [row_index][col_index] = c;
		  	col_index++;
		  }
		}
	}
	
	print_maze();                     //print it


	srand((unsigned int)time(NULL)); // sets a random seed for rand


	
	randomlocation(x,y);       //get a position for start point
	
	
	
    Maze[cur_row][cur_column] = 'A';   //turn that postion in the maze into an A
	printf("\e[1;1H\e[2J");                  //clear console
	print_maze();                      //prints maze
	
	printf("Random Start Point: [%d,%d]", *x, *y); //shows me the random point
	
	
	
	time_t start_t, end_t; //intitalize my time variables
	char keypad;          //keypad is from user
	int countkey = 0;    //only used once
	int pointcount=0;   //keeps count of points
	
	while (1)
	{
		
		keypad = _getch(); //get an input
		
		if(keypad==72)                                                    //check which one it is //this is up
		{
			if (Maze[cur_row - 1][cur_column] != '*' && cur_row - 1 >=0)      //make sure its a valid spot
			{
				if (Maze[cur_row - 1][cur_column] != ' ')                     //check if its a point
				{
					randomlocation(p,p2);                       //generate a new spot for a point
					point_value(val);                          //generate a new point value
					Maze[*p][*p2] = ((char)pointval+48);      //put new point on to the maze by typecasting it into a char and adding 48 to make it an ascii of itself (1 = 49 in ascii)
					
					
					pointcount = pointcount + ((int)Maze[cur_row - 1][cur_column] - 48);   //collects previous point which you are in the position of right now and adds it to point count by first typecasting into an int then subtracting 48 to get actual value
				}
				Maze [cur_row][cur_column] = ' ';      //make the position you just moved from a space
				
				cur_row--;                       //decrement current row to move up
				
				Maze[cur_row][cur_column] = 'A';   //place new position 
					
					printf("\e[1;1H\e[2J");          //clear console
					print_maze();                    //print maze
					printf("\nPoints: %d", pointcount); //show point count
			}
			
		
			countkey++;	//increment this
		}
		
		else if(keypad==80)                                                       //same thing as before except for going down
		{
			if (Maze[cur_row + 1][cur_column] != '*' && cur_row + 1<MAXR)
			{
				if (Maze[cur_row + 1][cur_column] != ' ')
				{
					randomlocation(p,p2);
					point_value(val);
					Maze[*p][*p2] = ((char)pointval+48);
					pointcount = pointcount + ((int)Maze[cur_row + 1][cur_column] - 48);}
				Maze [cur_row][cur_column] = ' ';
				
				cur_row++;
				
				Maze[cur_row][cur_column] = 'A';
					
					printf("\e[1;1H\e[2J");
					print_maze();
					printf("\nPoints: %d", pointcount);
			}
			
			countkey++;
		}
	
		
		
		
		else if(keypad==77)              //right same as before
		{
			if (Maze[cur_row][cur_column + 1] != '*' && cur_column + 1<MAXC)
			{
				if (Maze[cur_row][cur_column + 1] != ' ')
				{
					randomlocation(p,p2);
					point_value(val);
					Maze[*p][*p2] = ((char)pointval+48);
					
					pointcount = pointcount + ((int)Maze[cur_row][cur_column + 1] - 48);
				}
				Maze [cur_row][cur_column] = ' ';
				
				cur_column++;
				
				Maze[cur_row][cur_column] = 'A';
					
					printf("\e[1;1H\e[2J");
					print_maze();
					printf("\nPoints: %d", pointcount);
			}
			countkey++;//right
			
			
			
		}
		else if (keypad==75)                     //left same as last few cases
		{
				if (Maze[cur_row][cur_column-1] != '*' && cur_column-1>=0)
			{
				if (Maze[cur_row][cur_column-1] != ' ')
				{
					randomlocation(p,p2);
					point_value(val);
					Maze[*p][*p2] = ((char)pointval+48);
					
					pointcount = pointcount + ((int)Maze[cur_row][cur_column-1]-48);
				}
				Maze [cur_row][cur_column] = ' ';
				
				cur_column--;
				
				Maze[cur_row][cur_column] = 'A';
					
					printf("\e[1;1H\e[2J");
					print_maze();
					printf("\nPoints: %d", pointcount);
			}
			
			countkey++;
		}
		
		
		else  //if not an arrow key then just do nothing except count key
		{
			
			countkey++;//just update dont do anything else
		}

		
		if (countkey == 1)    //this will start the timer once one key is pressed //only use for countkey
		{
			
			time(&start_t); //start timer
		} 
	
			
	
		
		time(&end_t);  //end the timer each iteration kind of like lapping in a stopwatch
		
		if( difftime(end_t, start_t) > 60.0)    //check full duration so far  //once its over 60 secs end it
		{
			printf("\n\nTIME UP!!!\n");         
		
			exit(1);
		}

}
	


  	return 0;
}




