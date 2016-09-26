// Core Libraries
#include <iostream>
#include <string>
#include <math.h>

// 3rd Party Libraries
#include <C:\Users\100579309\Desktop\phys_model\project\gameObject.h>
#include <GLUT\glut.h>


// Defines and Core variables
#define FRAMES_PER_SECOND 60
const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND; // Miliseconds per frame

int windowWidth = 800;
int windowHeight = 600;

int mousepositionX;
int mousepositionY;

kinematic vect[8];


GLfloat rz = 0.0;
GLfloat ry = 0.0;
GLfloat rx = 0.0;
bool keyDown[256];


//duct tape physics testing




// A few conversions to know
float degToRad = 3.14159f / 180.0f;
float radToDeg = 180.0f / 3.14159f;


void setViewport(int v) {
	if (v == 1) {
		glViewport(0, 0, windowWidth / 2, windowHeight);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90.f, 1.0f, 1.0f, 10000.f);
	}
	if (v == 2) {
		glViewport(windowWidth / 2, 0, windowWidth, windowHeight);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90.f, 1.0f, 1.0f, 10000.f);
	}

	glMatrixMode(GL_MODELVIEW);

}

/* function DisplayCallbackFunction(void)
* Description:
*  - this is the openGL display routine
*  - this draws the sprites appropriately
*/
void DisplayCallbackFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Reset

	glColor3f(0.0f, 1.0f, 0.0f);

	glTranslatef(0.0f, 0.0f, -500.0f);

	glRotatef(rz, 0.0f, 1.0f, 0.0f);
	glRotatef(ry, 1.0f, 0.0f, 0.0f);
	glRotatef(rx, 0.0f, 0.0f, 1.0f);






	glBegin(GL_QUADS);
	//front
	glVertex3f(vect[5].getPosX(), vect[5].getPosY(), vect[5].getPosZ());	 //5
	glVertex3f(vect[1].getPosX(), vect[1].getPosY(), vect[1].getPosZ());	 //1
	glVertex3f(vect[0].getPosX(), vect[0].getPosY(), vect[0].getPosZ());	 //0
	glVertex3f(vect[4].getPosX(), vect[4].getPosY(), vect[4].getPosZ());	 //4

	//back		   	 				
	glVertex3f(vect[7].getPosX(), vect[7].getPosY(), vect[7].getPosZ());	 //7
	glVertex3f(vect[3].getPosX(), vect[3].getPosY(), vect[3].getPosZ());     //3
	glVertex3f(vect[2].getPosX(), vect[2].getPosY(), vect[2].getPosZ());	 //2
	glVertex3f(vect[6].getPosX(), vect[6].getPosY(), vect[6].getPosZ());	 //6

	glColor3f(0.0f, 0.0f, 1.0f);
	//left		   	 				  
	glVertex3f(vect[2].getPosX(), vect[2].getPosY(), vect[2].getPosZ());    //2
	glVertex3f(vect[1].getPosX(), vect[1].getPosY(), vect[1].getPosZ());    //1
	glVertex3f(vect[5].getPosX(), vect[5].getPosY(), vect[5].getPosZ());	//5
	glVertex3f(vect[6].getPosX(), vect[6].getPosY(), vect[6].getPosZ());    //6

	//right		   	 				  
	glVertex3f(vect[0].getPosX(), vect[0].getPosY(), vect[0].getPosZ());	//0
	glVertex3f(vect[3].getPosX(), vect[3].getPosY(), vect[3].getPosZ());	//3
	glVertex3f(vect[7].getPosX(), vect[7].getPosY(), vect[7].getPosZ());	//7
	glVertex3f(vect[4].getPosX(), vect[4].getPosY(), vect[4].getPosZ());	//4

	glColor3f(1.0f, 0.0f, 0.0f);
	//top		   	 				  
	glVertex3f(vect[7].getPosX(), vect[7].getPosY(), vect[7].getPosZ());	//7
	glVertex3f(vect[6].getPosX(), vect[6].getPosY(), vect[6].getPosZ());	//6
	glVertex3f(vect[5].getPosX(), vect[5].getPosY(), vect[5].getPosZ());	//5
	glVertex3f(vect[4].getPosX(), vect[4].getPosY(), vect[4].getPosZ());	//4

	//bot		   	 				  
	glVertex3f(vect[0].getPosX(), vect[0].getPosY(), vect[0].getPosZ());	 //0
	glVertex3f(vect[1].getPosX(), vect[1].getPosY(), vect[1].getPosZ());	 //1
	glVertex3f(vect[2].getPosX(), vect[2].getPosY(), vect[2].getPosZ());	 //2
	glVertex3f(vect[3].getPosX(), vect[3].getPosY(), vect[3].getPosZ());	 //3


	//plane
	glVertex3f(-100, -100.0, 100.0);
	glVertex3f(100, -100.0, 100.0);
	glVertex3f(100, -100.0, -100.0);
	glVertex3f(-100, -100.0, -100.0);

	glEnd();





	glutSwapBuffers();

}

/* function void KeyboardCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is pressed
*/
void KeyboardCallbackFunction(unsigned char key, int x, int y)
{
	std::cout << "Key: " << (int)key << std::endl;
	keyDown[key] = true;

	switch (key) {
		//	case 'a': rz += 1.0;
	}

}

/* function void KeyboardUpCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is lifted
*/
void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
{
	keyDown[key] = false;

}

void idleFunc()
{

}

/* function TimerCallbackFunction(int value)
* Description:
*  - this is called many times per second
*  - this enables you to animate things
*  - no drawing, just changing the state
*  - changes the frame number and calls for a redisplay
*  - FRAME_DELAY is the number of milliseconds to wait before calling the timer again
*/
void TimerCallbackFunction(int value)
{
	/* this call makes it actually show up on screen */
	glutPostRedisplay();

	if (keyDown['a'])
		rz += 1.0f;
	if (keyDown['d'])
		rz -= 1.0f;
	if (keyDown['w'])
		ry -= 1.0f;
	if (keyDown['s'])
		ry += 1.0f;
	if (keyDown['q'])
		rx -= 1.0f;
	if (keyDown['e'])
		rx += 1.0f;



	if (keyDown['8']) {

		for (int i = 0; i < 8; i++) {
			vect[i].setAcc(0.0f, 0.1f, 0.0f);;
		}
	}
	if (keyDown['5']) {

		for (int i = 0; i < 8; i++) {
			vect[i].setAcc(0.0f, -0.1f, 0.0f);
		}
	}
	if (keyDown['4']) {

		for (int i = 0; i < 8; i++) {
			vect[i].setAcc(-0.1f, 0, 0.0f);
		}
	}
	if (keyDown['6']) {

		for (int i = 0; i < 8; i++) {
			vect[i].setAcc(0.1f, 0.0f, 0.0f);
		}
	}

	for (int j = 0; j < 8; j++) {

		vect[j].move(vect[j].getAcc());
		vect[j].setAcc(0.0f, 0, 0.0f);
	}


	/* this call gives it a proper frame delay to hit our target FPS */
	glutTimerFunc(FRAME_DELAY, TimerCallbackFunction, 0);
}

/* function WindowReshapeCallbackFunction()
* Description:
*  - this is called whenever the window is resized
*  - and sets up the projection matrix properly
*/
void WindowReshapeCallbackFunction(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	windowWidth = w;
	windowHeight = h;
	float aspect = float(windowWidth) / float(windowHeight);
	gluPerspective(45.0f, aspect, 0.1f, 10000.0f);
	//				fov, aspect ratio, near, far

	glViewport(0, 0, windowWidth, windowHeight);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void MouseClickCallbackFunction(int button, int state, int x, int y)
{
	// Handle mouse clicks
	if (state == GLUT_DOWN)
	{
		std::cout << "Mouse x:" << x << " y:" << y << std::endl;
	}
}


/* function MouseMotionCallbackFunction()
* Description:
*   - this is called when the mouse is clicked and moves
*/
void MouseMotionCallbackFunction(int x, int y)
{
}

/* function MousePassiveMotionCallbackFunction()
* Description:
*   - this is called when the mouse is moved in the window
*/
void MousePassiveMotionCallbackFunction(int x, int y)
{
	mousepositionX = x;
	mousepositionY = y;
}

void init()
{
	///// INIT OpenGL /////
	// Set color clear value
	glClearColor(0.2f, 0.2f, 0.2f, 1.f);

	// Enable Z-buffer read and write (for hidden surface removal)
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_TEXTURE_2D); // textures for future use

							 //Example03
	glLineWidth(4.0f);
	glPolygonMode(GL_FRONT, GL_LINE); //GL_FRONT_AND_BACK, GL_FILL
}


/* function main()
* Description:
*  - this is the main function
*  - does initialization and then calls glutMainLoop() to start the event handler
*/

int main(int argc, char **argv)
{

	vect[0].setPos(-10, -10.0, 10.0);
	vect[1].setPos(10, -10.0, 10.0);
	vect[2].setPos(10, -10.0, -10.0);
	vect[3].setPos(-10, -10.0, -10.0);
	vect[4].setPos(-10.0, 10.0, 10.0);
	vect[5].setPos(10.0, 10.0, 10.0);
	vect[6].setPos(10.0, 10.0, -10.0);
	vect[7].setPos(-10.0, 10.0, -10.0);

	/* initialize the window and OpenGL properly */
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("INFR1350U - Example");

	/* set up our function callbacks */
	glutDisplayFunc(DisplayCallbackFunction);
	glutKeyboardFunc(KeyboardCallbackFunction);
	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
	glutIdleFunc(idleFunc);
	glutReshapeFunc(WindowReshapeCallbackFunction);
	glutMouseFunc(MouseClickCallbackFunction);
	glutMotionFunc(MouseMotionCallbackFunction);
	glutPassiveMotionFunc(MousePassiveMotionCallbackFunction);
	glutTimerFunc(1, TimerCallbackFunction, 0);
	init(); //Setup OpenGL States

			/* start the event handler */
	glutMainLoop();
	return 0;
}