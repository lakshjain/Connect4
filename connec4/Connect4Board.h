#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <conio.h>


using namespace std;
typedef vector< vector<int> > tBoardType;

class Connect4Board
	{
	private:
	 tBoardType *m_pBoard;
	
	protected:
		void ShowBoard();
		int PlayerMove(int pos,int player);

	public:
		Connect4Board(tBoardType* pBoard);
		
};
