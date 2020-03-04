// Tenacious_Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define GLEW_STATIC

#include "Logic.h"

#include <iostream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


using namespace std;
const GLint WIDTH = 400;
const GLint HEIGHT = 800;
GLFWwindow* gWindow = NULL;
bool gWireframe = false;
bool running = true;
Logic* gamelogic = new Logic();
thread t1(&Logic::gameTime, gamelogic);



// Shaders
const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"layout (location = 1) in vec3 color;"
"\n"
"out vec3 vert_color;"
"void main()"
"{"
"    vert_color = color;"
"    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";

const GLchar* fragmentShaderSrc =
"#version 330 core\n"
"in vec3 vert_color;"
"out vec4 frag_color;"
"void main()"
"{"
"    frag_color = vec4(vert_color, 1.0f);"
"}";


void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
void showFPS(GLFWwindow* window);

int main() {
	//initialize GLFW
	if (!glfwInit()) {
		cout << "GLFW init failed";
		glfwTerminate();
		return 1;
	}

	


	gamelogic->gameStart();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//core mean no backwards compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	gWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!gWindow) {
		cout << "GLFW window creation failed!";
		glfwTerminate();
		return 1;
	}

	//Get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(gWindow, &bufferWidth, &bufferHeight);
	cout << "buffer width " << bufferWidth << endl;

	//set context use
	glfwMakeContextCurrent(gWindow);

	//Allow modern extension features
	glewExperimental = GL_TRUE; //prolly don't need

	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW init failed";
		glfwDestroyWindow(gWindow);
		glfwTerminate();
		return 1;
	}

	//setup viewport size - size of what we are drawing to
	glViewport(0, 0, bufferWidth, bufferHeight);
	glfwSetKeyCallback(gWindow, glfw_onKey);
	GLfloat row1, row2,column1,column2,shade1,shade2;

	vector<GLfloat> verticesAlex;

			shade1 = 1.0f;
			shade2 = 0.1f;
			row1 = (-1.0f);
			row2 = (-1.0f);
			column1 = 1.0f;
			column2 = (1.0f-0.08f);

	for (int i = 0; i < 25; i++) {
			
		
		for (int j = 0; j < 12; j++) {
	
				
				verticesAlex.push_back(row1);				
				verticesAlex.push_back(column1);				
				verticesAlex.push_back(0.0f);
				//insert color
				for (int x = 0; x < 3; x++) {					
						verticesAlex.push_back(shade1);	
				}

				row1 = row1 + 0.1667f;

				verticesAlex.push_back(row1);
				verticesAlex.push_back(column1);
				verticesAlex.push_back(0.0f);
				//insert color
				for (int x = 0; x < 3; x++) {
					verticesAlex.push_back(shade1);
				}


				verticesAlex.push_back(row2);
				verticesAlex.push_back(column2);
				verticesAlex.push_back(0.0f);
				//insert color
				for (int x = 0; x < 3; x++) {
					verticesAlex.push_back(shade1);
				}

				verticesAlex.push_back(row2);
				verticesAlex.push_back(column2);
				verticesAlex.push_back(0.0f);
				//insert color
				for (int x = 0; x < 3; x++) {
					verticesAlex.push_back(shade2);
				}

				row2 = row2 + 0.1667f;

				verticesAlex.push_back(row2);
				verticesAlex.push_back(column2);
				verticesAlex.push_back(0.0f);
				//insert color
				for (int x = 0; x < 3; x++) {
					verticesAlex.push_back(shade2);
				}

				verticesAlex.push_back(row2);
				verticesAlex.push_back(column1);
				verticesAlex.push_back(0.0f);
				//insert color
				for (int x = 0; x < 3; x++) {
					verticesAlex.push_back(shade2);
				}

			
		}	
		row1 = (-1.0f);
		row2 = (-1.0f);

		column1 = column1 - 0.08f;
		column2 = column2 - 0.08f;

		shade1 = shade1 - 0.1f;
		shade2 = shade2 + 0.2f;

	}

	
	

	GLuint indices[1800];

	for (int i = 0; i < 1800; i++) {
		indices[i] = i;
	}



	//GLfloat vertices[] = {
	//	//0.0f, 0.5f, 0.0f,
	//	//0.5f, -0.5f, 0.0f,
	//	//-0.5f, -0.5f, 0.0f
	//	-0.5f, 0.5f, 0.0f, //Top
	//	0.5f, 0.5f, 0.0f,
	//	0.5f, -0.5f, 0.0f,

	//	-0.5f, 0.5f, 0.0f, //Top
	//	0.5f, -0.5f, 0.0f,
	//	-0.5f, -0.5f, 0.0f


	//};


	//GLfloat vertices[] = {
	//	-0.25f, 0.25f, 0.0f, //Top Left
	//	0.0f, 0.25f, 0.0f,
	//	0.0f, 0.0f, 0.0f,

	//	-0.25f, 0.25f, 0.0f, 
	//	0.0f, 0.0f, 0.0f,
	//	-0.25f, 0.f, 0.0f,

	//	0.0f, 0.25f, 0.0f, //Top Middle
	//	0.25f, 0.25f, 0.0f,
	//	0.25f, 0.0f, 0.0f,

	//	0.0f, 0.25f, 0.0f,
	//	0.25f, 0.0f, 0.0f,
	//	0.0f, 0.f, 0.0f,

	//	0.25f, 0.25f, 0.0f, //Top right
	//	0.5f, 0.25f, 0.0f,
	//	0.5f, 0.0f, 0.0f,

	//	0.25f, 0.25f, 0.0f,
	//	0.5f, 0.0f, 0.0f,
	//	0.25f, 0.0f, 0.0f,

	//	0.0f, 0.0f, 0.0f, //Bottom Middle
	//	0.25f, 0.0f, 0.0f,
	//	0.25f, -0.25f, 0.0f,

	//	0.0f, 0.0f, 0.0f,
	//	0.25f, -0.25f, 0.0f,
	//	0.0f, -0.25f, 0.0f,
	//};

	GLuint vbo, ibo, vao;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, verticesAlex.size() * sizeof(GLfloat), verticesAlex.data(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (GLvoid*)(sizeof(GLfloat) * 3));
	glEnableVertexAttribArray(0); //attribute 0 - the location
	glEnableVertexAttribArray(1); //attribute 1 - the color

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexShaderSrc, NULL);
	glCompileShader(vs);

	GLint result;
	GLchar infoLog[512];
	glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(vs, sizeof(infoLog), NULL, infoLog);
		cout << "Error - Vertex shader failed to compile. " << infoLog << endl;
	}

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fs);

	glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(fs, sizeof(infoLog), NULL, infoLog);
		cout << "Error - Fragment shader failed to compile. " << infoLog << endl;
	}

	GLint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
		cout << "Error - Shader program linker failed " << infoLog << endl;
	}

	glDeleteShader(vs);
	glDeleteShader(fs);


	//ALEX AMAZING TETRIS INTERFACING WITH KENS WEIRD OPENGL STUFF!!!-------------------------------------------------------------------------



	//loop until window closed
	while (!glfwWindowShouldClose(gWindow)  && running == true) {


		if (gamelogic->getTimeToMove() == true) {
			gamelogic->moveTetrominoDown(gamelogic->getCurrentTetromino());
			gamelogic->setTimeToMove(false);
		}
		gamelogic->updateBoard();
		gamelogic->checkGameOver();
		if (gamelogic->getRunning() == false) { 
			break;
		}

		//Covering up the top area
		for (int i = 0; i < 12; i++) {			
				gamelogic->getBoard()[i]->setColor('X');		
		}
		gamelogic->getBoard()[12]->setColor('X');
		gamelogic->getBoard()[23]->setColor('X');
		gamelogic->getBoard()[24]->setColor('X');
		gamelogic->getBoard()[35]->setColor('X');
		gamelogic->getBoard()[36]->setColor('X');
		gamelogic->getBoard()[47]->setColor('X');

		gamelogic->getBoard()[16]->setColor('1');
		gamelogic->getBoard()[17]->setColor('2');
		gamelogic->getBoard()[18]->setColor('1');
		gamelogic->getBoard()[19]->setColor('3');

		for (int i = 0; i < 4; i++) {
			gamelogic->getBoard()[i + 16]->setColor('1');
		}


		for (int i = 0; i < 4; i++) {
			gamelogic->getBoard()[i + 28]->setColor('1');
		}		

		for (int i = 0; i < 6; i++) {
			gamelogic->getBoard()[i + 39]->setColor('1');
		}

		
		
		//Update colors!
		for (int i = 0; i < (int)gamelogic->getBoard().size(); i++) {



			switch (gamelogic->getBoard()[i]->getColor()) {
			case('X'):
				//light shade
				verticesAlex[i*36 + 3] = 0.45f;
				verticesAlex[i*36+ 4] = 0.24f;
				verticesAlex[i*36+ 5] = 0.1f;

				verticesAlex[i * 36 + 3 + 6] = 0.45f;
				verticesAlex[i * 36 + 4 + 6] = 0.24f;
				verticesAlex[i * 36+ 5 + 6] = 0.1f;

				verticesAlex[i * 36 + 3 + 12] = 0.45f;
				verticesAlex[i * 36+ 4 + 12] = 0.24f;
				verticesAlex[i * 36+ 5 + 12] = 0.1f;

				//dark shade
				verticesAlex[i*36 + 3 + 18] = 0.35f;
				verticesAlex[i*36+ 4 + 18] = 0.14f;
				verticesAlex[i*36+ 5 + 18] = 0.0f;

				verticesAlex[i * 36 + 3 + 24] = 0.35f;
				verticesAlex[i * 36+ 4 + 24] = 0.14f;
				verticesAlex[i * 36 + 5 + 24] = 0.0f;

				verticesAlex[i * 36+ 3 + 30] = 0.35f;
				verticesAlex[i * 36+ 4 + 30] = 0.14f;
				verticesAlex[i * 36+ 5 + 30] = 0.0f;

				break;

			case('_'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.45f;
				verticesAlex[i * 36 + 4] = 0.6f;
				verticesAlex[i * 36 + 5] = 0.77f;

				verticesAlex[i * 36 + 3 + 6] = 0.45f;
				verticesAlex[i * 36 + 4 + 6] = 0.6f;
				verticesAlex[i * 36 + 5 + 6] = 0.77f;

				verticesAlex[i * 36 + 3 + 12] = 0.45f;
				verticesAlex[i * 36 + 4 + 12] = 0.6f;
				verticesAlex[i * 36 + 5 + 12] = 0.77f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.35f;
				verticesAlex[i * 36 + 4 + 18] = 0.5f;
				verticesAlex[i * 36 + 5 + 18] = 0.67f;

				verticesAlex[i * 36 + 3 + 24] = 0.35f;
				verticesAlex[i * 36 + 4 + 24] = 0.5f;
				verticesAlex[i * 36 + 5 + 24] = 0.67f;

				verticesAlex[i * 36 + 3 + 30] = 0.35f;
				verticesAlex[i * 36 + 4 + 30] = 0.5f;
				verticesAlex[i * 36 + 5 + 30] = 0.67f;


				break;

			case('C'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.21f;
				verticesAlex[i * 36 + 4] = 0.86f;
				verticesAlex[i * 36 + 5] = 0.79f;

				verticesAlex[i * 36 + 3 + 6] = 0.21f;
				verticesAlex[i * 36 + 4 + 6] = 0.86f;
				verticesAlex[i * 36 + 5 + 6] = 0.79f;

				verticesAlex[i * 36 + 3 + 12] = 0.21f;
				verticesAlex[i * 36 + 4 + 12] = 0.86f;
				verticesAlex[i * 36 + 5 + 12] = 0.79f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.11f;
				verticesAlex[i * 36 + 4 + 18] = 0.76f;
				verticesAlex[i * 36 + 5 + 18] = 0.69f;

				verticesAlex[i * 36 + 3 + 24] = 0.11f;
				verticesAlex[i * 36 + 4 + 24] = 0.76f;
				verticesAlex[i * 36 + 5 + 24] = 0.69f;

				verticesAlex[i * 36 + 3 + 30] = 0.11f;
				verticesAlex[i * 36 + 4 + 30] = 0.76f;
				verticesAlex[i * 36 + 5 + 30] = 0.69f;

				break;

			case('E'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.89f;
				verticesAlex[i * 36 + 4] = 0.44f;
				verticesAlex[i * 36 + 5] = 0.1f;

				verticesAlex[i * 36 + 3 + 6] = 0.89f;
				verticesAlex[i * 36 + 4 + 6] = 0.44f;
				verticesAlex[i * 36 + 5 + 6] = 0.1f;

				verticesAlex[i * 36 + 3 + 12] = 0.89f;
				verticesAlex[i * 36 + 4 + 12] = 0.44f;
				verticesAlex[i * 36 + 5 + 12] = 0.1f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.79f;
				verticesAlex[i * 36 + 4 + 18] = 0.34f;
				verticesAlex[i * 36 + 5 + 18] = 0.05f;

				verticesAlex[i * 36 + 3 + 24] = 0.79f;
				verticesAlex[i * 36 + 4 + 24] = 0.34f;
				verticesAlex[i * 36 + 5 + 24] = 0.05f;

				verticesAlex[i * 36 + 3 + 30] = 0.79f;
				verticesAlex[i * 36 + 4 + 30] = 0.34f;
				verticesAlex[i * 36 + 5 + 30] = 0.05f;

				break;

			case('G'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.2f;
				verticesAlex[i * 36 + 4] = 0.8f;
				verticesAlex[i * 36 + 5] = 0.2f;

				verticesAlex[i * 36 + 3 + 6] = 0.2f;
				verticesAlex[i * 36 + 4 + 6] = 0.8f;
				verticesAlex[i * 36 + 5 + 6] = 0.2f;

				verticesAlex[i * 36 + 3 + 12] = 0.2f;
				verticesAlex[i * 36 + 4 + 12] = 0.8f;
				verticesAlex[i * 36 + 5 + 12] = 0.2f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.1f;
				verticesAlex[i * 36 + 4 + 18] = 0.7f;
				verticesAlex[i * 36 + 5 + 18] = 0.1f;

				verticesAlex[i * 36 + 3 + 24] = 0.1f;
				verticesAlex[i * 36 + 4 + 24] = 0.7f;
				verticesAlex[i * 36 + 5 + 24] = 0.1f;

				verticesAlex[i * 36 + 3 + 30] = 0.1f;
				verticesAlex[i * 36 + 4 + 30] = 0.7f;
				verticesAlex[i * 36 + 5 + 30] = 0.1f;

				break;

			case('R'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.8f;
				verticesAlex[i * 36 + 4] = 0.0f;
				verticesAlex[i * 36 + 5] = 0.0f;

				verticesAlex[i * 36 + 3 + 6] = 0.8f;
				verticesAlex[i * 36 + 4 + 6] = 0.0f;
				verticesAlex[i * 36 + 5 + 6] = 0.0f;

				verticesAlex[i * 36 + 3 + 12] = 0.8f;
				verticesAlex[i * 36 + 4 + 12] = 0.0f;
				verticesAlex[i * 36 + 5 + 12] = 0.0f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.7f;
				verticesAlex[i * 36 + 4 + 18] = 0.0f;
				verticesAlex[i * 36 + 5 + 18] = 0.0f;

				verticesAlex[i * 36 + 3 + 24] = 0.7f;
				verticesAlex[i * 36 + 4 + 24] = 0.0f;
				verticesAlex[i * 36 + 5 + 24] = 0.0f;

				verticesAlex[i * 36 + 3 + 30] = 0.7f;
				verticesAlex[i * 36 + 4 + 30] = 0.0f;
				verticesAlex[i * 36 + 5 + 30] = 0.0f;

				break;

			case('B'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.2f;
				verticesAlex[i * 36 + 4] = 0.2f;
				verticesAlex[i * 36 + 5] = 1.0f;

				verticesAlex[i * 36 + 3 + 6] = 0.2f;
				verticesAlex[i * 36 + 4 + 6] = 0.2f;
				verticesAlex[i * 36 + 5 + 6] = 1.0f;

				verticesAlex[i * 36 + 3 + 12] = 0.2f;
				verticesAlex[i * 36 + 4 + 12] = 0.2f;
				verticesAlex[i * 36 + 5 + 12] = 1.0f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.1f;
				verticesAlex[i * 36 + 4 + 18] = 0.1f;
				verticesAlex[i * 36 + 5 + 18] = 0.9f;

				verticesAlex[i * 36 + 3 + 24] = 0.1f;
				verticesAlex[i * 36 + 4 + 24] = 0.1f;
				verticesAlex[i * 36 + 5 + 24] = 0.9f;

				verticesAlex[i * 36 + 3 + 30] = 0.1f;
				verticesAlex[i * 36 + 4 + 30] = 0.1f;
				verticesAlex[i * 36 + 5 + 30] = 0.9f;

				break;

			case('P'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.49f;
				verticesAlex[i * 36 + 4] = 0.15f;
				verticesAlex[i * 36 + 5] = 0.80f;

				verticesAlex[i * 36 + 3 + 6] = 0.49f;
				verticesAlex[i * 36 + 4 + 6] = 0.15f;
				verticesAlex[i * 36 + 5 + 6] = 0.8f;

				verticesAlex[i * 36 + 3 + 12] = 0.49f;
				verticesAlex[i * 36 + 4 + 12] = 0.15f;
				verticesAlex[i * 36 + 5 + 12] = 0.8f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.39f;
				verticesAlex[i * 36 + 4 + 18] = 0.05f;
				verticesAlex[i * 36 + 5 + 18] = 0.7f;

				verticesAlex[i * 36 + 3 + 24] = 0.39f;
				verticesAlex[i * 36 + 4 + 24] = 0.05f;
				verticesAlex[i * 36 + 5 + 24] = 0.7f;

				verticesAlex[i * 36 + 3 + 30] = 0.35f;
				verticesAlex[i * 36 + 4 + 30] = 0.05f;
				verticesAlex[i * 36 + 5 + 30] = 0.7f;

				break;

			case('Y'):
				//light shade
				verticesAlex[i * 36 + 3] = 1.0f;
				verticesAlex[i * 36 + 4] = 1.0f;
				verticesAlex[i * 36 + 5] = 0.0f;

				verticesAlex[i * 36 + 3 + 6] = 1.0f;
				verticesAlex[i * 36 + 4 + 6] = 1.0f;
				verticesAlex[i * 36 + 5 + 6] = 0.0f;

				verticesAlex[i * 36 + 3 + 12] = 1.0f;
				verticesAlex[i * 36 + 4 + 12] = 1.0f;
				verticesAlex[i * 36 + 5 + 12] = 0.0f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.8f;
				verticesAlex[i * 36 + 4 + 18] = 0.8f;
				verticesAlex[i * 36 + 5 + 18] = 0.0f;

				verticesAlex[i * 36 + 3 + 24] = 0.8f;
				verticesAlex[i * 36 + 4 + 24] = 0.8f;
				verticesAlex[i * 36 + 5 + 24] = 0.0f;

				verticesAlex[i * 36 + 3 + 30] = 0.8f;
				verticesAlex[i * 36 + 4 + 30] = 0.8f;
				verticesAlex[i * 36 + 5 + 30] = 0.0f;

				break;

			case('F'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.4f;
				verticesAlex[i * 36 + 4] = 0.5f;
				verticesAlex[i * 36 + 5] = 0.5f;

				verticesAlex[i * 36 + 3 + 6] = 0.4f;
				verticesAlex[i * 36 + 4 + 6] = 0.5f;
				verticesAlex[i * 36 + 5 + 6] = 0.5f;

				verticesAlex[i * 36 + 3 + 12] = 0.4f;
				verticesAlex[i * 36 + 4 + 12] = 0.5f;
				verticesAlex[i * 36 + 5 + 12] = 0.5f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.4f;
				verticesAlex[i * 36 + 4 + 18] = 0.5f;
				verticesAlex[i * 36 + 5 + 18] = 0.5f;

				verticesAlex[i * 36 + 3 + 24] = 0.4f;
				verticesAlex[i * 36 + 4 + 24] = 0.5f;
				verticesAlex[i * 36 + 5 + 24] = 0.5f;

				verticesAlex[i * 36 + 3 + 30] = 0.4f;
				verticesAlex[i * 36 + 4 + 30] = 0.5f;
				verticesAlex[i * 36 + 5 + 30] = 0.5f;

				break;

				//Pipe colors
				//base
			case('1'):
				//light shade
				verticesAlex[i * 36 + 3] = 0.19f;
				verticesAlex[i * 36 + 4] = 0.73f;
				verticesAlex[i * 36 + 5] = 0.30f;

				verticesAlex[i * 36 + 3 + 6] = 0.19f;
				verticesAlex[i * 36 + 4 + 6] = 0.73f;
				verticesAlex[i * 36 + 5 + 6] = 0.30f;

				verticesAlex[i * 36 + 3 + 12] = 0.19f;
				verticesAlex[i * 36 + 4 + 12] = 0.73f;
				verticesAlex[i * 36 + 5 + 12] = 0.30f;

				//dark shade
				verticesAlex[i * 36 + 3 + 18] = 0.09f;
				verticesAlex[i * 36 + 4 + 18] = 0.63f;
				verticesAlex[i * 36 + 5 + 18] = 0.2f;

				verticesAlex[i * 36 + 3 + 24] = 0.09f;
				verticesAlex[i * 36 + 4 + 24] = 0.63f;
				verticesAlex[i * 36 + 5 + 24] = 0.2f;

				verticesAlex[i * 36 + 3 + 30] = 0.09f;
				verticesAlex[i * 36 + 4 + 30] = 0.63f;
				verticesAlex[i * 36 + 5 + 30] = 0.2f;

				break;
				//light

			}

		}






		
		//get and handle user input events
		glfwPollEvents();

		//clear window
		glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, verticesAlex.size() * sizeof(GLfloat), verticesAlex.data(), GL_STATIC_DRAW);

		glUseProgram(shaderProgram);
		glBindVertexArray(vao);

		//glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, verticesAlex.size());
		glBindVertexArray(0);
		glfwSwapBuffers(gWindow);
		showFPS(gWindow);
	}

	t1.join();
	glDeleteProgram(shaderProgram);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
	glfwTerminate();

	cout << endl;
	cout << endl;
	cout << "GAME OVER" << endl;
	cout << "LEVEL: " << gamelogic->getDifficulty() << endl;
	cout << "TOTAL SCORE: " << gamelogic->getScore() << endl;
	cout << endl;
	system("pause");

	return 0;
}

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		gamelogic->moveTetrominoRight(gamelogic->getCurrentTetromino());
	}

	if (key == GLFW_KEY_LEFT &&  (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		gamelogic->moveTetrominoLeft(gamelogic->getCurrentTetromino());
	}

	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		gamelogic->moveTetrominoDown(gamelogic->getCurrentTetromino());
	}

	if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		gamelogic->spinTetromino(gamelogic->getCurrentTetromino());
	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
		gamelogic->setRunning(false);
		running = false;
		
	}

	if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
		gamelogic->setRunning(false);
		running = false;
	}

	if (key == GLFW_KEY_R && action == GLFW_PRESS) {
		//restart

		gamelogic->gameStart();
		

		// DUHHHHH
	}

	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		gWireframe = !gWireframe;
		if (gWireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void showFPS(GLFWwindow* window)
{
	static double previousSeconds = 0.0;
	static int frameCount = 0;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime(); // returns number of seconds since GLFW started, as double float

	elapsedSeconds = currentSeconds - previousSeconds;

	// Limit text updates to 4 times per second
	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerFrame = 1000.0 / fps;

		// The C++ way of setting the window title
		std::ostringstream outs;
		outs.precision(3);	// decimal places
		outs << std::fixed
			<< "Tenacious Tetris" << " "
			<< "LVL: " << gamelogic->getDifficulty() << " "
			<< "SCORE: " << gamelogic->getScore() << " "
			<< "FPS: " << fps << "    "
			<< "Frame Time: " << msPerFrame << " (ms)";
		glfwSetWindowTitle(window, outs.str().c_str());

		// Reset for next average.
		frameCount = 0;
	}

	frameCount++;
}