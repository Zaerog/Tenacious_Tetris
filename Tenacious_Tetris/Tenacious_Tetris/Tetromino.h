#include "Block.h"
#include <vector> 
#include <iostream>
using namespace std;


#pragma once
class Tetromino
{
public:
	Tetromino(int shape);
	int getDirection();
	void setDirection(int input);
	vector<Block*> getTetromino();
	Block* getBlock1();
	Block* getBlock2();
	Block* getBlock3();
	Block* getBlock4();

private:
	vector<Block*> tetromino;
	Block* block1;
	Block* block2;
	Block* block3;
	Block* block4;
	int direction = 0;
};

