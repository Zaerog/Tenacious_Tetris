#include "Tetromino.h"

Tetromino::Tetromino(int shape) {

		switch (shape) {
			//Rotation on block 1 only
		case 1: 
			block2 = new Block(false, 'C',5); //Inverted "L" Shape, C=Cyan			
			block3 = new Block(false, 'C',6);
			block1 = new Block(false, 'C',17);
			block4 = new Block(false, 'C',29);
			break;
		case 2: 
			block2 = new Block(false, 'E',5); //"L" Shape, E=Orange
			block3 = new Block(false, 'E',6);
			block1 = new Block(false, 'E',18);
			block4 = new Block(false, 'E',30);
			break;
		case 3: 
			block2 = new Block(false, 'G',5); //inverted "Z" Shape, G=Green
			block3 = new Block(false, 'G',17);
			block1 = new Block(false, 'G',18);
			block4 = new Block(false, 'G',30);
			break;
		case 4: 
			block2 = new Block(false, 'R',6); //"Z" Shape, R=Red
			block1 = new Block(false, 'R',17);
			block3 = new Block(false, 'R',18);
			block4 = new Block(false, 'R',29);
			break;
		case 5: 
			block2 = new Block(false, 'B',5); //"I" Shape, B=Blue (The Great Long One, The very bestest Tetromino, All hail the long one!)
			block3 = new Block(false, 'B',17);
			block1 = new Block(false, 'B',29);
			block4 = new Block(false, 'B',41);
			break;
		case 6: 
			block2 = new Block(false, 'P', 5); //"Square" Shape, P=Purple
			block3 = new Block(false, 'P', 6);
			block1 = new Block(false, 'P', 17);
			block4 = new Block(false, 'P', 18);
			break;
		case 7: 
			block2 = new Block(false, 'Y', 5); //"T" Shape, Y=Yellow
			block3 = new Block(false, 'Y', 16);
			block1 = new Block(false, 'Y', 17);
			block4 = new Block(false, 'Y', 18);
			break;
		}
		tetromino.push_back(block1);
		tetromino.push_back(block2);
		tetromino.push_back(block3);
		tetromino.push_back(block4);
	};




	vector<Block*> Tetromino::getTetromino() {
		return tetromino;
	}

	int Tetromino::getDirection() {
		return direction;
	}

	void Tetromino::setDirection(int input) {
		direction=input;
	}

	Block* Tetromino::getBlock1() {
		return block1;
	}

	Block* Tetromino::getBlock2() {
		return block2;
	}

	Block* Tetromino::getBlock3() {
		return block3;
	}

	Block* Tetromino::getBlock4() {
		return block4;
	}


