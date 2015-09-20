#include "Connect4Board.h"

class Connect4Player:public Connect4Board
{
	private:
				int mPlace;
				char mPlayerName[20];
				
				int Turn();
	
				//Various Checks For Winning
				int Check_LD(tBoardType mat,int row,int col);
				int Check_RD(tBoardType mat,int row,int col);
				int Check_LtoR(tBoardType mat,int row,int col);
				int Check_UtoD(tBoardType mat,int row,int col);
		
	public:

				Connect4Player(tBoardType *pBoard) : Connect4Board(pBoard){}
				
				void GetPlayerName();
				void IsWin(tBoardType mat,int row,int col,char name[30]);
				int Chance(int player);
				int Ret_Place();
				char* Ret_Name();
		
};
