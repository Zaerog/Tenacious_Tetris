#include "Tetromino.h"
#include "Block.h"
#include <thread>
#include <chrono>

using namespace std;
#pragma once
class Logic
{
public:
	Logic();
	void spawnTetromino();
	void moveTetrominoDown(Tetromino* tetromino);
	void moveTetrominoRight(Tetromino* tetromino);
	void moveTetrominoLeft(Tetromino* tetromino);
	void spinTetromino(Tetromino* tetromino);
	void checkGameOver();
	void updateBoard();
	void gameTime();
	void draw();
	vector<Block*> getBoard();
	bool getTimeToMove();
	void setTimeToMove(bool input);
	void setRunning(bool input);
	bool getRunning();
	Tetromino* getCurrentTetromino();
	int getScore();
	void setScore(int input);
	void setDifficulty(int input);
	void gameStart();
	int getDifficulty();


private:
	vector<Tetromino*> tetrominoList;
	vector<Block*>  gameboard;
	vector<Block*> tempBoard;
	bool running = true;
	Tetromino* current = NULL;
	int score = 0;
	bool timeToMove = false;
	int difficulty = 0;
	int rowCounter = 0;
	int combo = 1;
};


