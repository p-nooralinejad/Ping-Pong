#ifndef  _RAKET_H
#define  _RAKET_H
#include "gameboard.h"
#include "Action2.h"
#include <vector>
using namespace std;
struct Action{
	float y;
	float z;
	float vz;
	float vx;
	float vy;
	float zbarkhord;
	float xbarkhord;
};

class raket{
public:
	bool				isTime,ismore;
    int					a;
	GLfloat				x, y, z, vx, vy, vz, mehvar, poi, r, dd, dx, rd, v, xz, lkj, hjk, vch, tt, p,xz1;
	float				mahdoody, mahdoodx, mahdoodz;
	raket				( int,  gameboard);
    void  show			( gameboard, int);
    void  harekat		( gameboard, bool[], int, int);
    void  harekat1		( gameboard, int, int, int, int);
    void  power			( );
	Action2			    actions;
	void set			( int index1, int& nobat); 
};
#endif
