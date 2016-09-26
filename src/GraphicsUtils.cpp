#include "TTK/GraphicsUtils.h"
#include <windows.h>
#include "GLUT/glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>


void TTK::Graphics::DrawText2D(std::string text, int posX, int posY)
{
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glLoadIdentity();
		glRasterPos2f(posX, posY+24); // Plus 24 because thats the size of the text
		for (unsigned int i = 0; i < text.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
		}
	glPopMatrix();
}

void TTK::Graphics::DrawLine(float* p0, float* p1, float lineWidth, float *colour)
{
	GLboolean lightingEnabled;
	glGetBooleanv(GL_LIGHTING, &lightingEnabled);

	glDisable(GL_LIGHTING);

	glLineWidth(lineWidth);
	glBegin(GL_LINES);
	if (colour != nullptr)
		glColor3fv(colour);
	else
		glColor3f(0.0f, 0.0f, 0.0f);

		glVertex3fv(p0);
		glVertex3fv(p1);
	glEnd();
	glLineWidth(1.0f);

	
	if (lightingEnabled)
		glEnable(GL_LIGHTING);
}

void TTK::Graphics::DrawVector(float* origin, float* vectorToDraw, float lineWidth, float *colour)
{
	GLboolean lightingEnabled;
	glGetBooleanv(GL_LIGHTING, &lightingEnabled);

	glDisable(GL_LIGHTING);

	glLineWidth(lineWidth);
	glBegin(GL_LINES);
	if (colour != nullptr)
		glColor3fv(colour);
		glVertex3fv(origin);
		glVertex3f(origin[0] + vectorToDraw[0], origin[1] + vectorToDraw[1], origin[2] + vectorToDraw[2]);
	glEnd();
	glLineWidth(1.0f);

	if (lightingEnabled)
		glEnable(GL_LIGHTING);
}

 void TTK::Graphics::DrawPoint(float *p0, float pointSize, float *colour)
{
	GLboolean lightingEnabled;
	glGetBooleanv(GL_LIGHTING, &lightingEnabled);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glPointSize(pointSize);
	glBegin(GL_POINTS);

	if (colour != nullptr)
		glColor3fv(colour);
	else
		glColor3f(0.0f, 0.0f, 0.0f);

		glVertex3fv(p0);
	glEnd();

	glEnable(GL_TEXTURE_2D);

	if (lightingEnabled)
		glEnable(GL_LIGHTING);
}

 void TTK::Graphics::DrawCube(float *p0, float size, float *colour)
{
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLboolean lightingEnabled;
	glGetBooleanv(GL_LIGHTING, &lightingEnabled);

	glDisable(GL_LIGHTING);

	if (colour != nullptr)
		glColor4fv(colour);

	glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glTranslatef(*(p0), *(p0 + 1), *(p0 + 2));
			glutSolidCube(size);
		glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	if (lightingEnabled)
		glEnable(GL_LIGHTING);
}


 void TTK::Graphics::DrawTeapot(float *p0, float size /*= 1.0f*/, float *colour /*= nullptr*/)
{
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (colour != nullptr)
		glColor4fv(colour);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(*(p0), *(p0 + 1), *(p0 + 2));
	glutSolidTeapot(size);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void TTK::Graphics::SetCameraMode2D(int windowWidth, int windowHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, windowWidth, windowHeight);
	gluOrtho2D(0.0f, (float)windowWidth, 0.0f, (float)windowHeight);


	glMatrixMode(GL_MODELVIEW);
}

 void TTK::Graphics::SetCameraMode3D(int windowWidth, int windowHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, windowWidth, windowHeight);
	gluPerspective(60.0f, (float)windowWidth / (float)windowHeight, 0.001f, 10000.0f);

	glMatrixMode(GL_MODELVIEW);
}

void TTK::Graphics::SetBackgroundColour(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
}

void TTK::Graphics::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}