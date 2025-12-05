#include<stdio.h>
#include<stdbool.h>
bool WinStaleCheck(char grid[3][3])
{
	int isWin = 0;
	char winner;

	// Check for row and column Matches
	for(int i = 0;i<3;i++)
	{
		if((grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2]) && (grid[i][0] == 'X'||grid[i][0] == 'O'))
		{
			winner = grid[i][0];
			isWin = 1;
		}
		else if((grid[0][i] == grid[1][i]) && (grid[1][i] == grid[2][i]) && (grid[0][i] == 'X'||grid[0][i] == 'O'))
		{
			winner = grid[0][i];
			isWin = 1;
		}
	}

	// Check for Diagonol Matches
	if((grid[0][0] == grid [1][1]) && (grid[1][1] == grid[2][2]) && (grid[0][0] == 'X'||grid[0][0] == 'O'))
	{
		winner = grid[0][0];
		isWin = 1;
	}
	else if((grid[2][0] == grid [1][1]) && (grid[1][1] == grid[0][2]) && (grid[2][0] == 'X'||grid[2][0] == 'O'))
	{
		winner = grid[2][0];
		isWin = 1;
	}
	
	// Counting the total Non Empty locations in grid
	int nonEmptyCount = 0;
	for(int i = 0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[i][j] == 'X' || grid[i][j] == 'O')
			{
				nonEmptyCount += 1;
			}
		}
	}

	// Checking for Condition and ending this function with a return value

	if((isWin == 1 && nonEmptyCount == 9) || (isWin == 1))
	{
		printf("%c Wins The Game!",winner);
		return true;
	} 
	else if(isWin == 0 && nonEmptyCount == 9)
	{
		printf("\nStale\nNobody Wins!\n");
		return true;
	}
	else if(isWin == 0 && nonEmptyCount != 9)
	{
		return false;
	}
}

void StartGame()
{
	char grid[3][3],input = 'X';
	int row,col;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		grid[i][j] = ' ';
	}
	
	do{	

		printf("\nRow ->\n");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			printf("%c ",grid[i][j]);
			printf("\n");
		}
		printf("Column\n|\nV");

		
		do{
			printf("\n\n%c's Turn!\n",input);
			printf("\nEnter the Row : ");
			scanf("%d",&row);
			printf("\nEnter the column : ");
			scanf("%d",&col);
		}while(row < 1 || row > 3 || col < 1 || col > 3);

		row -= 1;
		col -= 1;
		
		if(grid[row][col] != 'X' && grid[row][col] != 'O')
		{
			grid[row][col] = input;
			if(input == 'X')
			input = 'O';
			else if(input == 'O')
			input = 'X';
		}		
	}while(WinStaleCheck(grid) != true);
	printf("\nRow ->\n");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			printf("%c ",grid[i][j]);
			printf("\n");
		}
		printf("Column\n|\nV");
		printf("\n\nGame Over!\n\n\n");

}
void main()
{
	int choice;
	printf("Tic Tac Toe Game\n");
	do{
		printf("\n1 - Play\n2 - Exit\nEnter Choice : ");
		scanf("%d",&choice);	
		
		switch(choice)
		{
			
			case 1:
			StartGame();
			break;
			case 2:
			break;
			default:
			printf("\nInvalid Input\n");
		}

	}while(choice != 2);
	

}
