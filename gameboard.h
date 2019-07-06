#ifndef  _GAMEBOARD_H
#define  _GAMEBOARD_H
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\GLAUX.H>
#include <fstream>
using namespace std;
class gameboard{
public:
    GLUquadricObj* qu;
	GLUquadricObj* qu2;
	GLuint		   texture[35];
    GLfloat        dx, h, y1, y2, ht, z, dt, pr;
    gameboard      ( );
    void show      ( );
};
#endif
