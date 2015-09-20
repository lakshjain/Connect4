// connec4.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <ctype.h>
using namespace std;
typedef vector< vector<int> > tBoardType;

class connect4
	{
	private:
	 tBoardType *m_pBoard;
	 
	public:
		connect4(tBoardType* pBoard)
		{
		m_pBoard = pBoard;
				
		for(int i=0;i<m_pBoard->size();++i)
			{
				for(int j=0;j<m_pBoard->at(i).size();++j)
			
				(*m_pBoard)[i][j]=0;
				
			}
		}
	
	void showboard()
		{	
		for(int i=1;i<=7;++i)
			printf(" %d ",i);

		printf("\n\n");
		
		for(int i=0;i<6;++i)
			{
			for(int j=0;j<7;++j)
			   printf(" %d ",(*m_pBoard)[i][j]);
			printf("\n\n\n");

			}
		}
		int board(int pos,int player)
		{	
			if(pos>0&&pos<8)
			{
				for(int i=m_pBoard->size()-1;i>=0;--i)
				{				
					if(((*m_pBoard)[i][pos-1])==0)
					{
						m_pBoard->at(i).at(pos-1)=player;
						return i;
					}
				}
			}
			
				return -1;
		}
	
	



};


class player:public connect4
{
	int place;
	char name[20];
	public:
		player(tBoardType *pBoard) : connect4(pBoard){}
			
		void getname()
		{
		gets(name);
		}
		int check_LD(tBoardType mat,int row,int col)
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
	
			if(count==5)
				return 1;
				
			else
				return 0;
			
}

int check_RD(tBoardType mat,int row,int col)
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
	
			if(count==5)
				return 1;
			else
				return 0;
	
}

int check_LtoR(tBoardType mat,int row,int col)
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
  
  
	if(count==5)
		return 1;
	else
		return 0;
	  
}

int check_UtoD(tBoardType mat,int row,int col)
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
  
  
	if(count==5)
			return 1;
		
	else
		return 0;
	
}


	int IsWin(tBoardType mat,int row,int col,char name[30])
		{
			if(check_LtoR(mat,row,col)||check_RD(mat,row,col)||check_LD(mat,row,col)||check_UtoD(mat,row,col))
			{
				
				system("cls");
				showboard();
				cout<<"\nConguratulations "<<name<<" You Won !!!\n";
				exit(0);
			}		
		}
		int turn()
		{
			char check;
			printf("\nChoose your column %s : ",name);
			cin>>check;
			while(!(isdigit(check)))
			{
				system("cls");
				showboard();
				printf("\nChoose your column %s : ",name);
				cin>>check;
			}
			place=(int)check-48;
			return place;
		}
		int chance(int player)
		{
			
			system("cls");
			showboard();
			int row=board(turn(),player);
			while(!(row>=0))
			{
				system("cls");
				cout<<" Wrong move try again\n ";
				system("Pause");
				system("cls");
				showboard();
				row=board(turn(),player);
			}
			return row;		
		}	
		int ret_place()
		{
			return place;
		}
		char* ret_name()
		{
			return name;
		}

		
};


int main()
{
	tBoardType board(6, vector<int>(7));
	int row;
player p1(&board),p2(&board);
printf("\n Enter Player 1 Name : ");
p1.getname();
printf("\n Enter Player 2 Name : ");
p2.getname();
for(int i=1;i<=21;++i)
{
	row=p1.chance(1);
	p1.IsWin(board,row,p1.ret_place()-1,p1.ret_name());
	row=p2.chance(2);
	p2.IsWin(board,row,p2.ret_place()-1,p2.ret_name());
	
}

system("cls");
cout<<" !! Match Drawn !! \n";
system("pause");

return 0;

}
