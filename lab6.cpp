// Ross Strickland CS1428
// 10/10/17

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void printarray();
int neighbors(int r,int c);
void update();

const int ROWS = 10;
const int COLS = 10;
char life[ROWS][COLS];
char cop[ROWS][COLS];

int main()
{
	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell;

	for(int r=0; r<ROWS; r++) //randomly initializes array
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]='-';
			}
		}
	}
	cout << "The Game of Life"<<endl<<endl;

	for(int i=0;i<11;i++) //cycles through printing and updating each generation
    {
        cout << "Generation "<<i<<endl;
        printarray();
        update();
    }



	return 0;

}

void printarray() //prints life
{
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++)
            {cout << life[i][j]<<" ";}
    cout <<endl;
                            }
    cout <<endl<<endl;
}

int neighbors(int r,int c) //calculates # of living neighbors
{
    int neighbs=0;
    if(r-1>=0 && c-1>=0){ if(life[r-1][c-1]=='*') neighbs++;}
    if(r-1>=0){ if(life[r-1][c]=='*') neighbs++;}
    if(r-1>=0 && c<9){ if(life[r-1][c+1]=='*') neighbs++;}
    if(c-1>=0){ if(life[r][c-1]=='*') neighbs++;}
    //center square
    if(c<9){ if(life[r][c+1]=='*') neighbs++;}
    if(r<9 && c-1>=0){ if(life[r+1][c-1]=='*') neighbs++;}
    if(r<9){ if(life[r+1][c]=='*') neighbs++;}
    if(r<9 && c<9){ if(life[r+1][c+1]=='*') neighbs++;}

    return neighbs;
}

void update() //uses neighbors to update cop and then copies cop to life
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            int n= neighbors(i,j);
            if(n<2){cop[i][j]='-';}
            else if(n==2){cop[i][j]=life[i][j];}
            else if(n==3){cop[i][j]='*';}
            else{cop[i][j]='-';}
        }
    }

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            life[i][j]=cop[i][j];
}
