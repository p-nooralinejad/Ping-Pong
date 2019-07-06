#include "raket.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
raket::raket ( int i, gameboard f ):actions (0, 0, 0, 0, 0, 0)
{
	ismore=false;
	if (i==2)
		actions = Action2 (25,25,3,10,5,6);
	if ( i == 1 )
		x = -f.dx;
	if ( i == 2 ){
		z =  ( f.z-f.z )/2.0+0.1;
	}
	if ( i == 1 )
		x = f.dx;
	else
	    x = -f.dx;
	r = 0.2;                /////markaz-0.32! = -0.5
	isTime=0;
	dd = 0.15;
	dx = 0.02;
	rd = 0.017;
    y = -0.2;
    mahdoodx = x;
    mahdoody = y;
	v=(i==1)?(0.002):(0.004);
    xz = 0;
	lkj = 0;
    vch = 0.35;
    p = 0.001;
}

void raket::show ( gameboard f, int i )
{
	 glTranslatef	( x, y, z );
     glRotatef		( 90, 0, 1, 0 );
     glColor3f		( 1, 0, 0 );
     glRotatef		( 30, 0, 0, 1 );
	 if(i==1){
     if ( xz!= 0 && vch == 0 )
         glRotatef ( xz1, 0, 1, 0 );
     if ( xz != 0 && vch != 0 )
         glRotatef ( -xz1, 0, -1, 0 );  
	 }
	 if(i==2){
	 if ( xz!= 0 && vch == 0 )
         glRotatef ( -xz, 0,1, 0 );
     if ( xz != 0 && vch != 0 )
         glRotatef ( xz, 0, -1, 0 );  
	 }
	 glBindTexture (GL_TEXTURE_2D, f.texture [25]);
      gluDisk		( f.qu, 0, r, 30, 30 );
     glTranslatef	( 0, 0, dx );
     glColor3f		( 0, 0, 0 );
     gluDisk		( f.qu, 0, r, 30, 30 );
     glTranslatef	( 0, 0, -dx );
     glColor3f		( 1, 0.5, 0 );
     gluCylinder	( f.qu, r, r, dx, 30, 30 );
     glTranslatef	( 0, -r, dx/2 );
     glRotatef		( 90, 1, 0, 0 );
     gluCylinder	( f.qu, rd, rd, dd, 30, 30 );
}
void raket::harekat ( gameboard f, bool keys[], int k, int joy)
{
	if(xz>=180){
        xz-=180;
		ismore=true;
	}
	if(xz1>=360){
		xz-=360;
		ismore=false;
	}
    //  if ( k == 3||k == 0 ){

         if ( keys['W'] || joy == -500 )
            y +=  v;
         if ( y-0.32>f.y1  )
         {                  
			if ( keys['S'] || joy == 500 )
				y -=  v;
         }
          if ( x+ ( dx/2 )>0.01+r  )
			if ( keys[VK_UP]|| joy == -300 )
			{
            x -=  v;
			}
        if ( keys[VK_DOWN] || joy == 300)
        {
            x +=  v;
        } 
        if ( keys['A'] || joy==-100 )
        {
            lkj = 0;
            z +=  v;
        } 
        if ( keys['D']  || joy==100)
        {    
            lkj +=  10;
            z -=  v;
        } 
        if ( keys[VK_SPACE] || joy == 809){
            xz +=  vch;
			xz1=(ismore)?(xz+180):xz;
		}
 /*    }
     else if ( k == 1 ){
         if ( keys['W'] )
            y +=  v;
         if ( y-0.32>f.y1  )
         {  
         if ( keys['S'] )
            y -=  v; 
        }
        if ( x+ ( dx/2 )>0.01+r  )
        if ( keys[VK_UP] )
        {
            x -=  v;
        }
        if ( keys[VK_DOWN] )
        {
            x +=  v;
        } 
        if ( keys['A'] )
        {
            lkj = 0;
            z +=  v;
            } 
        if ( keys['D'] )
        {
            z -=  v;
            lkj +=  10;
            }
        if ( keys[VK_SPACE] )
            xz +=  vch;      
     }*/ 
     if (p<0.004 &&( keys['E']|| joy == 9) )
     {
		p +=  0.00001;
     }
}

void raket::set ( int  index1, int& nobat )
{
	int i;
	int rrr=this->actions.len_angle * this ->actions.len_power;
	int * copy = new int [rrr];
	for (int i=0; i<rrr;i++){
		copy [i] = actions.s_a[index1][i].v;
	}
	for (int i=1; i<rrr;i++)
		copy[i] = copy[i] + copy[i-1];
	int j=rrr-1;
	long int random;
	srand (time( 0 ));
	if (copy[rrr-1])
		random =rand ( )%copy[rrr-1]+8000;
	else
		random = 0;
	int jk;
	for(jk=rrr-1;jk>=0;jk--)
		if(random>=copy[jk-1])
		{
			j=jk;
			break;
		}
	if (jk == 0)
		j=0;
	int tmp1, tmp2;
	tmp1 = j/ 10;
	if (tmp1 == 0)
		p=-0.002;
	else if (tmp1==1)
		p=0.001;
	else
		p=0.004;
	p=0.001;
	tmp2 = j%10;
	xz = 180-(tmp2* 18);
	delete [] copy;
	actions.s_a[index1][j].is_using = true;
	actions.s_a[index1][j].queue = ++nobat;
}

void raket::harekat1 ( gameboard f, int o1, int o2, int o3, int index)
 { 
 
	 if (o1 == 0 || o2 == 0){
		return ;
	}
	if(o1== 2)
		x+=v;
	else if(o1== 3)
		x-=v;
	if(o2== 2){
		z+=v;
	}
	else if(o2== 3){
		z-=v;
		//y+=0.001;
	}
	else if (o2==1)
	{
      //cout <<1;
		
	}

}


void raket::power ( )
{
	 glLoadIdentity ( );
	 glTranslatef	( 0, 0.6, -4 );
 	 glBegin ( GL_QUADS );
 	 	glColor3f	( 0, 1, 0 );
 	 	glVertex3f	( -3.2, 2, 0 );
		glVertex3f	( -3.2, 2.15, 0 );
		glColor3f	( p*150, 1- ( p*150 ), 0 );
 		glVertex3f	(  ( p*100 )-3, 2.15, 0 );
 	 	glVertex3f	(  ( p*100 )-3, 2, 0 );
 	 glEnd ( );
 	 glBegin ( GL_LINE_LOOP );
 	    glColor3f	( 0, 0, 0 );
 	 	glColor3f	( 0.1, 0.3, 0.2 );
 	 	glVertex3f	( -3.2, 2, 0 );
		glVertex3f	( -3.2, 2.15, 0 );
 		glVertex3f	( -2.6, 2.15, 0 );
 	 	glVertex3f	( -2.6, 2, 0 );
 	 glEnd ( );
}
