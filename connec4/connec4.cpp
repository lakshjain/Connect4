// connec4.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include"Connect4Player.h"

int main()
{
	vector< vector<int> > gameBoard(6, vector<int>(7));
	int row;

	Connect4Player p1(&gameBoard),p2(&gameBoard);
	cout<<"\n Enter Player 1 Name : ";
	p1.GetPlayerName();
	cout<<"\n Enter Player 2 Name : ";
	p2.GetPlayerName();

	for(int i=1;i<=21;++i)
	{

		row=p1.Chance(1);
		
		if(i >=4 )//Check start on and after 4th turn
			p1.IsWin(gameBoard,row,p1.Ret_Place()-1,p1.Ret_Name());
			
		row=p2.Chance(2);
		
		if( i>=4)//Check start on and after 4th turn
			p2.IsWin(gameBoard,row,p2.Ret_Place()-1,p2.Ret_Name());

	}

system("cls");
cout<<" !! Match Drawn !! \n";
system("pause");
return 0;
}
