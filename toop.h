#ifndef  _TOOP_H
#define  _TOOP_H
#include  <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl\GLAUX.H>
#include <iostream>
#include <fstream>
#include "raket.h"
#include "gameboard.h"
using namespace std;
class toop{
public:
	bool		  is_defined;
    GLfloat		  x, y, z, vy, vx, a, r, q, g, vz;
    int			  makan1, makan2,ah,mn,ha,hob,issaved,istime;
	float		  xbar,zbar;
	toop          ( gameboard );
    void harekat  ( );
    void show     ( gameboard );
    void barkhord ( gameboard, vector <Action2>&, bool, raket&, int, int& );
    int Raket     ( raket, raket ,int);
    void toor     ( gameboard );
    int  barande  ( gameboard );
    void  manage  ( raket, int& output1, int& output2, int& output3);
    vector <Action> actions;
	Action ac;
	bool service  ( gameboard ,raket&,raket&r2,int);
	void checktoop();
	int setreward(raket,gameboard,int,int);
};
#endif