/*	This Code Is Created By PAK GROUP. The members are:
*	Kianoosh Abbasi		Parsa Nooralinejad		Arya Kowsary
*	This project contains an Learning Agent which plays Ping Pong and with RL type
*	Our Teachers are Mr.Ghafoorian & Mr.Zahedi 
*	//////////////////////////////////////////////////////////////////////////////
*	////////////		PAK CROUP PING PONG PROJECT HELLI3			  ////////////
*	///////////				        2011 - 2012						  ////////////
*   //////////////////////////////////////////////////////////////////////////////
*/

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "glaux.h"			// Header File For The Glaux Library
#include <stdio.h>			// Header File For Standard Input/Output
#include <iostream>			// Header File For Input/Output Stream!
#include <fstream>			// Header File For file stream!
#include <ctime>			// Header File For Time Library
#include "GLext.h"			// Header File For The Text Library 
#include "texture.h"		// Header File For Texture Library
#include "toop.h"           // Header File For The Toop Library!:D
#include "show.h"           // Header File For The ShowALL Library!:D
#include "declarations.h"   // Header File Rot The Declarations Library! :D

enum Status{
	start_show1 =-10,
	start_show2 = -9,
	call =0,
	firstMove = 3,
	set_camera = 4,
	reset_data = 5,
	start_game =6,
};
Status flag = call;
int episod =0;
int alaK =0;
int ke=1;
const int NUMBER_OF_QUADS =8;
UINT uiNumJoysticks = joyGetNumDevs();
JOYINFO joy_info;
UINT_PTR joy_ID;
JOYCAPS joy_caps;
RECT joy_trip;
HWND		hWnd =NULL;
int Time=0;
int checking =0;
int DrawGLScene (GLvoid)						// Here's Where We Do All The Drawing
{    
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	if (flag == start_show1){
		t.is_defined = false;
		r2.actions.is_defined = false;
		Time +=1;
		showall.showWhiteBack ( texture[26]);
		showall.showPleaseWait (0, 0, -4, 8);
		if (Time >=500){
			Time =0;
			flag = start_show2;
		}
	}
	if ( flag == start_show2 ){
		showall.showWhiteBack (texture[26]);
		glBindTexture (GL_TEXTURE_2D, texture[5] );
		glLoadIdentity ( );
		glTranslatef (0, 0, -4);
		glBegin (GL_QUADS);
			glColor3f (1, 1, 1);
			glTexCoord2f (0, 0);
			glVertex3f (-1,-1, 0); 
			glTexCoord2f (1, 0);
			glVertex3f ( 1,-1, 0); 
			glTexCoord2f (1, 1);
			glVertex3f ( 1, 1, 0); 
			glTexCoord2f (0, 1);
			glVertex3f (-1, 1, 0); 
		glEnd ( );
		Time++;
		if (Time>=300)
			flag =firstMove;
	}
	if ( flag==call ){
		recall( );
		makefile ( );
		flag=start_show1;
	}
 	if (flag == firstMove){
		//showall.showPleaseWait (2.5, -2.5, -8, 8 );
		if(joyGetPos(JOYSTICKID1,&joy_info)!=JOYERR_UNPLUGGED) 
			joy_ID = JOYSTICKID1; // make sure the joystick is attached
		else
			ke=0;
		joyGetDevCaps(joy_ID, &joy_caps, sizeof(JOYCAPS)); 
		if(joySetCapture(hWnd, JOYSTICKID1, NULL, TRUE)) 
		{ 
			if (joy_info.wButtons == 4 && ke){
				K=ktemp;
				flag = reset_data;
			}
			if (joy_info.wXpos == 0 && ke){
				ktemp = 1;
			}
			if (joy_info.wXpos == 65535&& ke){
				ktemp = 3;
			}
			if (joy_info.wYpos == 0&& ke){
				ktemp = 0;
			}
		}
		showall.showallInTheFirstMove (f, t, r, r2, 0, 1, 0, 0, 0, 4, -10, keys, alaK);
		showall.showallInTheFirstMove (f, t, r, r2, 1, 0, -1, 0, -10, 6, -13, keys, alaK);
		showall.showallInTheFirstMove (f, t, r, r2, 3, 1, 0, 0, 10, 6, -13, keys, alaK);
		glLoadIdentity	( );
		glTranslatef	( 0, 0, -6 );
		glBindTexture	( GL_TEXTURE_2D, texture[9] );
		glColor3f		( 1, 1, 1 );
		glBegin	( GL_QUADS );
			glTexCoord2f    ( 1, 1 );
			glVertex3f		( 15.5, 2, -10 );
			glTexCoord2f	( 0, 1 );
			glVertex3f		( -15.5, 2, -10 );
			glTexCoord2f	( 0, 0 );
			glVertex3f		( -15.5, -10, -10 );
			glTexCoord2f	( 1, 0 );
			glVertex3f		( 15.5, -10, -10 );
		glEnd	( );
        if (keys[VK_RIGHT]){
			ktemp = 3;
		}
        if (keys[VK_LEFT]){
			ktemp = 1;
		}
		if (keys[VK_UP])
		    ktemp = 0;
		showall.showKTEMP (ktemp);
		if (keys[13]){
			K =ktemp;
			flag = set_camera;
		}
	}

	if (flag == set_camera){
	    if (K == 0){
			k1 = 1;
	        k2 = 0;
	        k3 = 0;
	    }
	    if (K == 1){
	        k1 = 0;
	        k2 = -1;
	        k3 = 0;
	    }
	    if (K == 2){
	        k1 = 0;
	        k2 = 0;
	        k3 = 1;
	    }
	    flag = reset_data;
	}
	
	if (flag == reset_data){
		t = toop	(f);
		r = raket	(1, f);
		r2 = raket	(2, f);
		r2.actions.readFromFile ( );
		flag = start_game;
	}
	if (flag == start_game){
		glLoadIdentity	( );
		glTranslatef	(0, 0, -4);
		glBindTexture	(GL_TEXTURE_2D,  texture [0] );
		glColor3f		(1, 1, 1);
		glBegin (GL_QUADS);
			glTexCoord2f	(1.0f, 1.0f);
			glVertex3f		(38.5, 27.5, -30);
			glTexCoord2f	(0.0f, 1.0f);
			glVertex3f		(-38.5, 27.5, -30);
			glTexCoord2f	(0.0f, 0.0f);
			glVertex3f		(-38.5, -27.5, -30);
			glTexCoord2f	(1.0f, 0.0f);
			glVertex3f		(38.5, -27.5, -30);
		glEnd ( );
		glLoadIdentity ( );
		if (K != 0){
			showall.showall (f, t, r, r2, K, k1, k2, k3, 0, 0, -4, keys, game_actions, true, episod, checking);
		}
		else
			showall.showall (f, t, r, r2, K, k1, k2, k3, 0, -0.5, -4, keys, game_actions, true, episod , checking);
		//cout <<"Size="<<game_actions.size ( )<<endl;
		if (keys['P'])
			oops = 1;
		if (c3==0){
			ifstream toopin("Data/Files/toop.txt" );
			while (!toopin.eof())
				toopin>>t;
			   toopin.close();
			t.is_defined =true;
			c3 =1;
		}
		if (oops == 0){
			if( count2++ % 7 ==0 ){
				out2 << r.x << " " << r.y << " "<< r.z << " " << r.xz << " " ;
				out << t.x << " " << t.y << " " << t.z << " " ;
				out3 << r2.x << " " << r2.y << " "<< r2.z << " " << r2.xz << " " ;
				t2 = t;
				r3 =r; 
				r4= r2;
			}
			else{
				out2 << r.x << " " << r.y << " "<< r.z << " " << r.xz << " " ;
				out << t.x << " " << t.y << " " << t.z << " " ;
				out3 << r2.x << " " << r2.y << " "<< r2.z << " " << r2.xz << " " ;
			}
		}
		
		if (oops == 1){
			out2.close ( );
			out.close ( );
			out3.close ( );
			oops = 2;
		}
		if (oops == 2){
				in2 >> r.x >> r.y >> r.z >> r.xz;
				in >> t.x >> t.y >> t.z;
				in3 >> r2.x >> r2.y >> r2.z >> r2.xz; 
		}
		if(joyGetPos(JOYSTICKID1,&joy_info)!=JOYERR_UNPLUGGED){ 
			joy_ID = JOYSTICKID1; // make sure the joystick is attached
			ke=1;
		}
		else
			ke=0;
		joyGetDevCaps(joy_ID, &joy_caps, sizeof(JOYCAPS)); 
		if(joySetCapture(hWnd, JOYSTICKID1, NULL, TRUE)) 
		{ 
			if (joy_info.wXpos == 0 && ke){
				checking = -100;
			}
			else if (joy_info.wXpos == 65535&& ke){
				checking = 100;
			}
			else if (joy_info.wYpos == 0&& ke){
				checking = -500;
			}
			else if (joy_info.wYpos == 65535&& ke){
				checking = 500;
			}
			else if (joy_info.wButtons == 16&& ke){
				checking = 300;
			}
			else if (joy_info.wButtons == 32&& ke){
				checking = -300;
			}
			else if (joy_info.wButtons == 1&& ke){
				checking =9;	
			}
			else if (joy_info.wButtons == 4&& ke){
				checking =809;
			}
			else if (joy_info.wButtons == 256&& ke){
				if (t.is_defined){
					ofstream outtt ("Data/Files/toop.txt");
					outtt << t;
					outtt.close ( );
				}
				r2.actions.sendToFile ( );
				return false;
			}
			else
				checking  =0;
			checking =0;
		}
		glLoadIdentity			( );
		glTranslatef			(1.5, 2.5, -4);
		showall.showall			(f, t, r, r2, 0, 1, 0, 0, 0, 4, -10, keys, Alaki, false, alaK, checking);
		showall.showall			(f, t, r, r2, 1, 0, -1, 0, -10, 6, -13, keys, Alaki, false, alaK, checking);
		showall.showall			(f, t, r, r2, 3, 1, 0, 0, 10, 6, -13, keys, Alaki, false, alaK, checking);
		showall.showallTextures ( f, K);
		//game_actions.push_back  (r2.actions[0]);
		//cout <<"Size"<<game_actions.size (  )<<endl;
		//cout <<r2.v<< " ";
	
		showall.scoreBoard		( f, t, score1, score2,r,r2,ki,game_actions, episod);
	}
	if ( score1 >= 11 || score2 >= 11 ){
		int i= score1>=11?1:2;
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		showall.showallInTheLastMove (f, i);
		if (keys['Q']){
			ofstream outt ("Data/Files/toop.txt");
			outt << t;
			outt.close ( );
			r2.actions.sendToFile ( );
			return false;
		}
	}

	return TRUE;										// Keep Going
}
#include "opengl.h"
int main( ){
	 WinMain( hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
