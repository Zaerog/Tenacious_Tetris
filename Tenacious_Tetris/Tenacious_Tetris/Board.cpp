#include <vector> 
#include <iostream>
#include "Block.h"

using namespace std;

class Board
{
public:
	Board() {
		for (int i = 0; i < 240; i++) {
			Block* block = new Block(false, 'X', i);
			board.push_back(block);
		}
	};

	void Draw() {
		for (int i = 0; i < 24; i++) {
			
			for (int j = 0; j < 10; j++) {
				cout << "|" << board[i*10+j]->GetColor() << board[i*j]->GetPosition();
			}
			cout << "|" << endl;
		}
	}

	vector<Block*> GetBoard() {
		return board;
	}

	void SetBoard(vector<Block*>input) {
		board=input;
	}
	

private:
	vector<Block*> board;
};