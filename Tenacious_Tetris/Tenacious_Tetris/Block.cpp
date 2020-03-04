#include "Block.h"


Block::Block(bool empty, char color, int position) {
	this->empty = empty;
	this->color = color;
	this->position = position + 1;

	//6 vertices, 2 polygons, 1 block
	/*
		for (int x = 0; x < 6; x++) {

				//coords
			for (int j = 0; j < 2; j++) {
				if (position > 0) {
					GLfloat temp = 1.0f;
					coordinates.push_back(temp);
				}
			}
				coordinates.push_back(0.0);

				//colors
			for (int i = 0; i < 3; i++) {
					GLfloat temp = 1.0f;
					if (x % 2 == 1) {
						coordinates.push_back(temp);
					}
					else {
						coordinates.push_back(temp - 0.5f); //darker
					}
			}
		}
		*/
	};
	
	bool Block::getStatus(){
		return empty;
	}

	char Block::getColor() {
		return color;
	}

	int Block::getPosition(){
		return position;
	}

	vector<GLfloat> Block::getCoordinates() {
		return coordinates;
	}

	void Block::setBool(bool status) {
		empty = status;
	}

	void Block::setColor(char color) {
		this-> color= color;
	}

	void Block::setStatus(bool status, char color) {
		empty = status;
		this->color = color;
	}

	void Block::setAll(bool status, char color,int position) {
		empty = status;
		this->color = color;
		this->position = position;
	}

	void Block::setPosition(int position) {
		this->position = position;
	}
