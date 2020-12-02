#include<iostream>
using namespace std;
#include<GL/glut.h>

int m;
float tetra[4][3] = { { 0, 200, 400 }, { 0, 0, -350 }, { 200, 350, 300 }, { -300, 300, 200 } };

void draw_triangle(float p1[], float p2[], float p3[])
{
	glBegin(GL_TRIANGLES);
	glVertex3f(p1[0], p1[1], p1[2]);
	glVertex3f(p2[0], p2[1], p2[2]);
	glVertex3f(p3[0], p3[1], p3[2]);
	glEnd();
}

void divide_triangle(float a[], float b[], float c[], int m)
{

	float v1[3], v2[3], v3[3];
	int j;

	if (m > 0)
	{
		for (j = 0; j < 3; j++)
			v1[j] = (a[j] + b[j]) / 2;
		for (j = 0; j < 3; j++)
			v2[j] = (a[j] + c[j]) / 2;
		for (j = 0; j < 3; j++)
			v3[j] = (c[j] + b[j]) / 2;
		divide_triangle(a, v1, v2, m - 1);
		divide_triangle(c, v2, v3, m - 1);
		divide_triangle(b, v3, v1, m - 1);
	}
	else
		draw_triangle(a, b, c);
}
void tetrahedron()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	divide_triangle(tetra[0], tetra[1], tetra[2], m);

	glColor3f(0, 1.0, 0);
	divide_triangle(tetra[3], tetra[2], tetra[1], m);

	glColor3f(0, 0, 1.0);
	divide_triangle(tetra[0], tetra[3], tetra[1], m);

	glColor3f(0, 0, 0);
	divide_triangle(tetra[0], tetra[2], tetra[3], m);

	glFlush();
}
void myinit()
{
	glClearColor(1, 1, 1.0, 1.0);
	glColor3f(1.0, 0, 0);
	glPointSize(5.0);
	glOrtho(-500, 500, -500, 500, -500, 500);
}

void main(int argcp, char** argv)
{
	cout << "Enter m : ";
	cin >> m;
	glutInit(&argcp, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Display");
	glutDisplayFunc(tetrahedron);
	glEnable(GL_DEPTH_TEST);
	myinit();
	glutMainLoop();
}
