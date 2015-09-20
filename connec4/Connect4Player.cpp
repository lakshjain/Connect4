#include "stdafx.h"
#include "Connect4Player.h"

void Connect4Player::GetPlayerName()
{
		gets(mPlayerName);
}

//Checking along Left Diagnol
int Connect4Player::Check_LD(tBoardType mat,int row,int col)
{
			int col_min,col_max,count=0;
			col_min=col;
			col_max=6-col;
			
			if((col_min-3)>=0)
				col_min-=3;
			else
				col_min=0;
			if(col_max>3)
			col_max=3;
			int k=0;
			for(int i=col;i>=col_min&&(row+k>=0&&row+k<=5);--i)
			{	
			
				if(mat[row+k][i]==mat[row][col])
					{
						++count;
					}
				else
					break;
				--k;
			}
			k=0;
			for(int i=col;i<=col+col_max&&(row+k>=0&&row+k<=5);++i)
			{
				if(mat[row+k][i]==mat[row][col])
					{
						++count;
					}
				else
					break;
			++k;
			}
	
			if(count>=5)
				return 1;
			else
				return 0;
			
}

//Checking along Right Diagnol
int Connect4Player::Check_RD(tBoardType mat,int row,int col)
{
		int col_min,col_max,count=0;
		col_min=col;
		col_max=6-col;
		
		if((col_min-3)>=0)
			col_min-=3;
		else
			col_min=0;
		
		if(col_max>3)
			col_max=3;
	
		int k=0;
		for(int i=col;i>=col_min&&(row+k>=0&&row+k<=5);--i)
		{	
		
			if(mat[row+k][i]==mat[row][col])
				{
					++count;
				}
			else
				break;
			++k;
		}
		k=0;
		
		for(int i=col;i<=col+col_max&&(row+k>=0&&row+k<=5);++i)
		{
			if(mat[row+k][i]==mat[row][col])
				{
					++count;
				}
			else
				break;
			--k;
		}

		if(count>=5)
			return 1;
		else
			return 0;
}

//Check Left to Right
int Connect4Player::Check_LtoR(tBoardType mat,int row,int col)
{
		int count =0,col_min,col_max;
		//for straight line
		col_min=col;
		col_max=6-col;
		if((col_min-3)>=0)
			col_min-=3;
		else
			col_min=0;
		if(col_max>3)
			col_max=3;
		for(int i=col;i>=col_min;--i)
		{
		if(mat[row][i]==mat[row][col])
			{
			 ++count;
			}
		else
			break;
		}
		for(int i=col;i<=col+col_max;++i)
		{
		if(mat[row][i]==mat[row][col])
			{
			 ++count;
			}
		else
			break;
		}
  
		if(count>=5)
			return 1;
		else
			return 0;
}

//Checking in Up To Down Direction
int Connect4Player::Check_UtoD(tBoardType mat,int row,int col)
{
		int count =0,row_min,row_max;
		//for straight line
		row_min=row;
		row_max=5-row;
		if((row_min-3)>=0)
			row_min-=3;
		else
			row_min=0;
		if(row_max>3)
			row_max=3;
		for(int i=row;i>=row_min;--i)
		{
		if(mat[i][col]==mat[row][col])
			{
			 ++count;
			}
		else
			break;
		}
		for(int i=row;i<=row+row_max;++i)
		{
		if(mat[i][col]==mat[row][col])
			{
			 ++count;
			}
		else
			break;
		}
  
		if(count>=5)
				return 1;
		
		else
			return 0;

}

void Connect4Player::IsWin(tBoardType mat,int row,int col,char name[30])
{
	if(Check_LtoR(mat,row,col)||Check_RD(mat,row,col)||Check_LD(mat,row,col)||Check_UtoD(mat,row,col))
		{
				
			system("cls");
			ShowBoard();
			cout<<"\nConguratulations "<<name<<" You Won !!!\n";
			exit(0);
		}	
}

int Connect4Player::Turn()
{
	char check;
	printf("\nChoose your column %s : ",mPlayerName);
	check=getche();
	while(!isdigit(check))
	{
		system("cls");
		ShowBoard();
		printf("\nChoose your column %s : ",mPlayerName);
		check=getche();
	}
		getch();
		mPlace=check-48;
		cin.sync();
		return mPlace;
}

int Connect4Player::Chance(int player)
{
	system("cls");
	ShowBoard();
	int row=PlayerMove(Turn(),player);
	while(!(row>=0))
	{
			system("cls");
			cout<<" Wrong move try again\n ";
			system("Pause");
			system("cls");
			ShowBoard();
			row=PlayerMove(Turn(),player);
	}
	return row;		
}

int Connect4Player::Ret_Place()
{
	return mPlace;
}

char* Connect4Player::Ret_Name()
{
	return mPlayerName;
}