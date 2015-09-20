#include "stdafx.h"
#include "Connect4Board.h"

Connect4Board::Connect4Board(tBoardType* pBoard)
{
	m_pBoard = pBoard;
			
	for(int i=0;i<m_pBoard->size();++i)
		{
			for(int j=0;j<m_pBoard->at(i).size();++j)
				(*m_pBoard)[i][j]=0;
				
		}
}
void Connect4Board::ShowBoard()
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

int Connect4Board::PlayerMove(int pos, int player)
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
