#include <iostream>
#include <GL/GLUT.h>
#include <time.h>
using namespace std;
int x1, x2, yc1, y2;
int flag = 0;
void draw_pixel(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();

}
void draw_line()
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;
	dx = x2 - x1;
	dy = y2 - yc1;
	if (dx < 0)dx = -dx;
	if (dy < 0)dy = -dy;
	incx = 1;
	if (x2 < x1)
		incx = -1;
	incy = 1;
	if (y2 < yc1)
		incy = -1;
	x = x1;
	y = yc1;
	if (dx > dy)
	{
		draw_pixel(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
			if (e > 0)
			{
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}
	}
	else
	{

		draw_pixel(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (e > 0)
			{
				x += incx;
				e += inc1;

			}
			else

				e += inc2;
			y += incy;

			draw_pixel(x, y);
		}
	}
	glFlush();
}
void myinit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	gluOrtho2D(-250, 250, -250, 250);
}
void MyMouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			if (flag == 0)
			{
				printf("Defining x1,y1");
				x1 = x - 250;
				yc1 = 250 - y;
				flag++;
				cout << x1 << " " << yc1 << " \n";
			}
			else
			{
				printf("Defining x2,y2");
				x2 = x - 250;
				y2 = 250 - y;
				flag = 0;
				cout << x2 << " " << y2 << " \n";
				draw_line();

			}

		}
		break;
	}
}
void display()
{}
int main(int ac, char* av[])
{
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("LINE");
	myinit();
	glutMouseFunc(MyMouse);
	glutDisplayFunc(display);
	glutMainLoop();
}
