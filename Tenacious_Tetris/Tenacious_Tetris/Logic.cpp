#include "Logic.h"



	Logic::Logic() {


	};

	void Logic::spawnTetromino() {
		srand(static_cast<unsigned int>(time(nullptr)));
		int random = (rand() % 7) + 1;
		Tetromino* tetromino = new Tetromino(random);
		current = tetromino;
		tetrominoList.push_back(tetromino);
		gameboard[tetromino->getBlock1()->getPosition()]->setStatus(false, tetromino->getBlock1()->getColor());
		gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, tetromino->getBlock2()->getColor());
		gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, tetromino->getBlock3()->getColor());
		gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, tetromino->getBlock4()->getColor());

	
	}



	void Logic::moveTetrominoDown(Tetromino* tetromino) {

		//check for collision
		if (gameboard[tetromino->getBlock1()->getPosition() + 12]->getStatus() == true || gameboard[tetromino->getBlock2()->getPosition() + 12]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 12]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 12]->getStatus() == true) {

			//set collision true after colliding
			gameboard[tetromino->getBlock1()->getPosition()]->setBool(true);
			gameboard[tetromino->getBlock2()->getPosition()]->setBool(true);
			gameboard[tetromino->getBlock3()->getPosition()]->setBool(true);
			gameboard[tetromino->getBlock4()->getPosition()]->setBool(true);
			spawnTetromino();
		}
		else {

			//clear initial position
			gameboard[tetromino->getBlock1()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

			//update coords on tetromino
			tetromino->getBlock1()->setPosition(tetromino->getBlock1()->getPosition() + 12);
			tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 12);
			tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 12);
			tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 12);


			//update board
			gameboard[tetromino->getBlock1()->getPosition()]->setStatus(tetromino->getBlock1()->getStatus(), tetromino->getBlock1()->getColor());
			gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
			gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
			gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());
			draw();
		
		}
	}

	void Logic::moveTetrominoRight(Tetromino* tetromino) {

		//collisioncheck
		if (gameboard[tetromino->getBlock1()->getPosition() + 1]->getStatus() == true || gameboard[tetromino->getBlock2()->getPosition() + 1]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 1]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 1]->getStatus() == true) {
			
			//do nothing
		}
		else {
			//clear initial position
			gameboard[tetromino->getBlock1()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

			//update coords on tetromino
			tetromino->getBlock1()->setPosition(tetromino->getBlock1()->getPosition() + 1);
			tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 1);
			tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 1);
			tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 1);


			//update board
			gameboard[tetromino->getBlock1()->getPosition()]->setStatus(tetromino->getBlock1()->getStatus(), tetromino->getBlock1()->getColor());
			gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
			gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
			gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());
			draw();
		

		}
	}

	void Logic::moveTetrominoLeft(Tetromino* tetromino) {

		//Collision Check
		if (gameboard[tetromino->getBlock1()->getPosition() - 1]->getStatus() == true || gameboard[tetromino->getBlock2()->getPosition() - 1]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 1]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 1]->getStatus() == true) {
			//do nothing

		}
		else {
			//clear initial position
			gameboard[tetromino->getBlock1()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
			gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

			//update coords on tetromino
			tetromino->getBlock1()->setPosition(tetromino->getBlock1()->getPosition() - 1);
			tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 1);
			tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 1);
			tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 1);


			//update board
			gameboard[tetromino->getBlock1()->getPosition()]->setStatus(tetromino->getBlock1()->getStatus(), tetromino->getBlock1()->getColor());
			gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
			gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
			gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());
			draw();
			
		}
	}

	//-----------------------------------------------------Rotation start---------------------------------------------------------------------------------------------------------------------------------------------------
	//------------------------- DIRECTION  00000000000000000000000000----------------------------------------------------------------------------
	void Logic::spinTetromino(Tetromino* tetromino) {

		if (tetromino->getDirection() == 0) {
			switch (tetromino->getBlock1()->getColor()) {
			case 'C':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 11]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 2]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 11);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 2);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(1);
					draw();
			
				}
				break;
			case 'E':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 24]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 24);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 11);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(1);
					draw();
					
				}
				break;
			case 'G':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 2]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 13]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 2);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 11);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 13);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(1);
					draw();
				
				}
				break;
			case 'R':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() - 2]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 13]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 2);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 13);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(1);
					draw();
				
				}
				break;
			case 'B':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 22]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 22);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 11);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(1);
					draw();
				
				}
				break;
			case 'P':
					//Square doesnt do the rotat0r!
				
				
				break;
			case 'Y':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 11]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 13]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 13]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 11);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 13);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 13);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(1);
					draw();
				
				}
				break;
			}
		}
		//-----------------------DIRECTION 1111111111111--------------------------------------------------------------------------------------------------------------------------------
		else if (tetromino->getDirection() == 1) {
			switch (tetromino->getBlock1()->getColor()) {
			case 'C':
				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 13]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() +24]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() -13]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() +13);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() +24);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() -13);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(2);
					draw();
				
				}
				break;
			case 'E':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 2]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() +13]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 13]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 2);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 13);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 13);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(2);
					draw();
				
				}
				break;
			case 'G':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() - 2]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 13]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 2);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 11);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 13);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(0);
					draw();
					
				}
				break;
			case 'R':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 2]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 13]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 2);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 13);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(0);
					draw();
					
				}
				break;
			case 'B':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() - 22]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 22);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 11);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(0);
					draw();
					
				}
				break;
			case 'Y':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() + 13]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() + 13);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 11);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(2);
					draw();
				
				}
				break;
			}

		}
		//---------------------DIRECTION 22222222222222222222222----------------------------------------------------------------------------------------------
		else if (tetromino->getDirection() == 2) {

			switch (tetromino->getBlock1()->getColor()) {
			case 'C':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() - 11]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 2]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 11);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 2);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(3);
					draw();
					
				}
				break;
			case 'E':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() -24]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 11]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 24);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 11);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 11);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(3);
					draw();
				
				}
				break;
			case 'Y':

				//Collision Check
				if (gameboard[tetromino->getBlock2()->getPosition() - 11]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 13]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 13]->getStatus() == true) {
					//do nothing

				}
				else {
					//clear initial position
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

					//update coords on tetromino
					tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 11);
					tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 13);
					tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 13);


					//update board
					gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
					gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
					gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

					current->setDirection(3);
					draw();
					
				}
				break;
				}

		}
		// ------------------------------------------ DIRECTION 33333333333333333333333333333-----------------------------------------------------------------------------
		else{

			switch (tetromino->getBlock1()->getColor()) {
				case 'C':
					//Collision Check
					if (gameboard[tetromino->getBlock2()->getPosition() -13]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 24]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() + 13]->getStatus() == true) {
						//do nothing

					}
					else {
						//clear initial position
						gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
						gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
						gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

						//update coords on tetromino
						tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 13);
						tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 24);
						tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 13);


						//update board
						gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
						gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
						gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

						current->setDirection(0);
						draw();
				
					}
					break;
				case 'E':

					//Collision Check
					if (gameboard[tetromino->getBlock2()->getPosition() -2]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() - 13]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() +13]->getStatus() == true) {
						//do nothing

					}
					else {
						//clear initial position
						gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
						gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
						gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

						//update coords on tetromino
						tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 2 );
						tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() - 13);
						tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() + 13);


						//update board
						gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
						gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
						gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

						current->setDirection(0);
						draw();
						
					}
					break;
				case 'Y':

					//Collision Check
					if (gameboard[tetromino->getBlock2()->getPosition() - 13]->getStatus() == true || gameboard[tetromino->getBlock3()->getPosition() + 11]->getStatus() == true || gameboard[tetromino->getBlock4()->getPosition() - 11]->getStatus() == true) {
						//do nothing

					}
					else {
						//clear initial position
						gameboard[tetromino->getBlock2()->getPosition()]->setStatus(false, '_');
						gameboard[tetromino->getBlock3()->getPosition()]->setStatus(false, '_');
						gameboard[tetromino->getBlock4()->getPosition()]->setStatus(false, '_');

						//update coords on tetromino
						tetromino->getBlock2()->setPosition(tetromino->getBlock2()->getPosition() - 13);
						tetromino->getBlock3()->setPosition(tetromino->getBlock3()->getPosition() + 11);
						tetromino->getBlock4()->setPosition(tetromino->getBlock4()->getPosition() - 11);


						//update board
						gameboard[tetromino->getBlock2()->getPosition()]->setStatus(tetromino->getBlock2()->getStatus(), tetromino->getBlock2()->getColor());
						gameboard[tetromino->getBlock3()->getPosition()]->setStatus(tetromino->getBlock3()->getStatus(), tetromino->getBlock3()->getColor());
						gameboard[tetromino->getBlock4()->getPosition()]->setStatus(tetromino->getBlock4()->getStatus(), tetromino->getBlock4()->getColor());

						current->setDirection(0);
						draw();
						
					}
					break;
			}
		}
	}

	// ---------------------------------------roation end--------------------------------------------------------------------------------------------------------------------------------------
	void Logic::checkGameOver() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				if (gameboard[i * 12 + j+1]->getStatus()==true) {
					running = false;
				}
			}
		}	
	}


	void Logic::updateBoard() {
		int counter = 0;
		int row = 0;
		

		for (int i = 0; i < 24; i++) {
			
			for (int j = 0; j < 12; j++) {
				if (gameboard[i * 12 + j]->getStatus()==true) {
					counter++;
				}
			}
			if (counter == 12) {
				// EXPLOSIONS!!!!------------------------BOOOOM
				for (int j = 0; j < 12; j++) {
					gameboard[i * 12 + j]->setColor('F');
				}
				draw();

				score = (score + 10 * combo * (difficulty+1));

				Block* block;

				int skipper = 12;

				for (int j = 0; j < 25; j++) {
				
					if (j == 4) {
						Block* block = new Block(true, 'X', 0);
						tempBoard.push_back(block);
						for (int j = 0; j < 10; j++) {
							block = new Block(false, '_', j + 1);
							tempBoard.push_back(block);
						}
						block = new Block(true, 'X', 11);
						tempBoard.push_back(block);
					}
					if (j == i) {
						//Skip line (solved)
						rowCounter++;
						combo++;
					}
					else {
						for (int x = 0; x < 12; x++) {
							block = new Block(gameboard[j*12+x]->getStatus(), gameboard[j * 12 + x]->getColor(), skipper);
							tempBoard.push_back(block);
							skipper++;
						}
					}
				}

				gameboard.clear();


				for (int j = 0; j < 48; j++) {
					block = new Block(tempBoard[j]->getStatus(), '_', j);
					gameboard.push_back(block);
				}

				for (int j = 48; j < (int)tempBoard.size(); j++) {
					block = new Block(tempBoard[j]->getStatus(), tempBoard[j]->getColor(), tempBoard[j]->getPosition());
					gameboard.push_back(block);
				}
				tempBoard.clear();

				

			}
			row++;
			counter = 0;
			
		}
		combo = 1;
	}

	//extra thread 
	void Logic::gameTime() {
		int timer = 1000;
		while (running == true) {
					   
			this_thread::sleep_for(chrono::milliseconds(timer));

			if (rowCounter >= 10 ) {
				timer = timer * 0.8;
				rowCounter = 0;
				difficulty++;
			}
			timeToMove = true;			   
		}
	}

	void Logic::draw() {
		
		//top pipe decoration
		//line 1
		for (int x = 0; x < 12; x++) {
			cout << "|X";
		}cout << "|"<<endl;
		//line2
		cout << "|X|_|_|_|_|X|X|_|_|_|_|X|" << endl;
		//line3
		cout << "|X|_|_|_|X|X|X|X|_|_|_|X|" << endl;
		


		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 12; j++) {
				cout << "|" << gameboard[i * 12 + j+48]->getColor(); // << gameboard[i * 12 + j]->getPosition();
			}
			cout << "|" << endl;
		}
	}

	vector<Block*> Logic::getBoard() {
		return gameboard;
	}

	bool Logic::getTimeToMove() {
		return timeToMove;
	}

	void Logic::setTimeToMove(bool input) {
		timeToMove = input;
	}


	void Logic::setRunning(bool input) {
		running = input;
	}

	bool Logic::getRunning() {
		return running;
	}

	Tetromino* Logic::getCurrentTetromino() {
		return current;
	}

	int Logic::getScore() {
		return score;
	}

	void Logic::setScore(int input) {
		difficulty = input;
	}

	int Logic::getDifficulty() {
		return difficulty;
	}

	void Logic::setDifficulty(int input) {
		difficulty = input;
	}


	void Logic::gameStart() {

		rowCounter = 0;
		setScore(0);
		setDifficulty(0);
		gameboard.clear();
		// populate gameboard
		for (int i = 0; i < 24; i++) {
			Block* block = new Block(true, 'X', i*12);
			gameboard.push_back(block);
			for (int j = 0; j < 10; j++) {
				block = new Block(false, '_', i * 12 + j+1);
				gameboard.push_back(block);
			}
			block = new Block(true, 'X', i*12+11);
			gameboard.push_back(block);
		}
		for (int i = 0; i < 12; i++) {
			 Block* block = new Block(true, 'X', 288+i);
			 gameboard.push_back(block);
		}

		//Spawn First enemy!
		spawnTetromino();
		draw();

		/*
		thread t1(&Logic::gameTime,this);

		//Listen For Input WINDOWS ONLY! -> check include windows.h
		while (running == true) {
			if (timeToMove == true) {
				moveTetrominoDown(current);
				timeToMove = false;
			}
			updateBoard();
			checkGameOver();
			if (getKeyState(VK_SPACE) & 0x8000)
			{
				running = false;
			}

			if (getKeyState(VK_RIGHT) & 0x8000)
			{
				moveTetrominoRight(current);
			}

			if (getKeyState(VK_LEFT) & 0x8000)
			{
				moveTetrominoLeft(current);
			}

			if (getKeyState(VK_UP) & 0x8000)
			{
				spinTetromino(current);
			}

			if (getKeyState(VK_DOWN) & 0x8000)
			{
				moveTetrominoDown(current);
			}			
				
		}
		t1.join();*/

	}