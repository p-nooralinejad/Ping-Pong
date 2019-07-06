#ifndef  _SHOW_H
#define  _SHOW_H
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "glaux.h"
#include <iostream>
#include <fstream>
//#include <MMSystem.h>
#include "toop.h"
#include "raket.h"

using namespace std;
class show{
public:
    bool keys[256];
	void pointer               ( toop, raket, gameboard, int );
	void showall               ( gameboard&,  toop&,  raket&,  raket &,  int,  int,  int,  int,  float,  float,
		float, bool[], vector <Action2>&, bool, int&, int);
	void showallInTheFirstMove ( gameboard&,  toop&,  raket&,  raket &,  int,  int,  int,  int,  float,  float,
		float, bool[], int );
	void showKTEMP			   ( int );
	void showallTextures	   ( gameboard, int );
	void scoreBoard			   ( gameboard, toop&, int&, int& ,raket&,raket&r2 ,int, vector <Action2>&, int&/*, int &*/);
	void showWhiteBack		   ( GLuint texture );
	void showPleaseWait		   ( GLfloat x_pos, GLfloat y_pos, GLfloat z_pos, int num );
	void showallInTheLastMove  ( gameboard, int);
};
#endif
