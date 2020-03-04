#include <vector>
#include <iostream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;
#pragma once
class Block
{
public:
	Block(bool empty, char color, int position);
	bool getStatus();
	char getColor();
	int getPosition();
	vector<GLfloat> getCoordinates();
	void setColor(char color);
	void setBool(bool status);
	void setStatus(bool status, char color);
	void setPosition(int position);
	void setAll(bool status, char color, int position);

private:
	bool empty;
	char color;
	int position;
	vector<GLfloat> coordinates;
};

