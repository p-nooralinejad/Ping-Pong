#include"gameboard.h"
gameboard::gameboard ( ){
   dx = 2.5;
   z = 1.25;
   h = 3;
   y1 = -0.5;
   y2 = -0.75;
   ht = -0.25;
   dt = 0.05;
   pr = 0.1;
}
void gameboard::show ( ){
			glBindTexture	(GL_TEXTURE_2D, texture [0] );
			glBegin	(GL_QUADS);//zamine jolo
				glColor3f		(1, 1, 1);
				glTexCoord2f	(1, 1);
				glVertex3f		(dx, y1, z);
				glTexCoord2f	(0, 1);
				glVertex3f		(-dx, y1, z);
				glTexCoord2f	(0, 0);
				glVertex3f		(-dx, y2, z);
				glTexCoord2f	(1, 0);
				glVertex3f		(dx, y2, z);
			glEnd ( );
			glBegin ( GL_LINE_LOOP );
				glColor3f   ( 10, 10, 10 );
			    glVertex3f  (  -dx,  y1, z );
				glVertex3f  ( dx,  y1, z );
				glVertex3f  ( dx, y2, z );
				glVertex3f  (  -dx,  y2, z );
			glEnd ( );
			glBindTexture	(GL_TEXTURE_2D, texture [0] );
			glBegin	(GL_QUADS);//zamine posht
				glColor3f		(1, 1, 1);
				glTexCoord2f	(1, 1);
				glVertex3f		(dx, y1, -z);
				glTexCoord2f	(0, 1);
				glVertex3f		(-dx, y1, -z);
				glTexCoord2f	(0, 0);
				glVertex3f		(-dx, y2, -z);
				glTexCoord2f	(1, 0);
				glVertex3f		(dx, y2, -z);
			glEnd ( );
			glBegin ( GL_LINE_LOOP );
				glColor3f ( 10, 10, 10 );
			    glVertex3f  (  -dx,  y1,  -z );
				glVertex3f  ( dx,  y1, -z );
				glVertex3f  ( dx, y2, -z );
				glVertex3f  (  -dx, y2, -z );
			glEnd ( );
			glBindTexture	(GL_TEXTURE_2D, texture [2] );
			glBegin ( GL_QUADS );
				glColor3f   ( 1, 1, 1 );//zamin
				glTexCoord2f( 1, 1 );
			    glVertex3f  ( dx,  y1, -z );
				glTexCoord2f( 0, 1 );
				glVertex3f  ( -dx,  y1, -z );
				glTexCoord2f( 0, 0 );
				glVertex3f  ( -dx, y1, z );
				glTexCoord2f( 1, 0 );
				glVertex3f  ( dx, y1, z );
			glEnd ( );
			glBegin ( GL_LINE_LOOP );//khate haye doresh
				glColor3f   ( 10, 10, 10 );
			    glVertex3f  ( dx,  y1,  -z );
				glVertex3f  ( -dx,  y1, -z );
				glVertex3f  ( -dx, y1,  z );
				glVertex3f  ( dx, y1, z );
			glEnd ( );
			glBindTexture	(GL_TEXTURE_2D, texture [3] );
			glBegin ( GL_QUADS );
				glColor3f   ( 1, 1, 1 );//zamin
				glTexCoord2f( 1, 1 );
			    glVertex3f  ( dx,  y2, -z );
				glTexCoord2f( 0, 1 );
				glVertex3f  ( -dx,  y2, -z );
				glTexCoord2f( 0, 0 );
				glVertex3f  ( -dx, y2, z );
				glTexCoord2f( 1, 0 );
				glVertex3f  ( dx, y2, z );
			glEnd ( );
			glBegin ( GL_LINE_LOOP );//khate haye doresh
				glColor3f   ( 10, 10, 10 );
			    glVertex3f  ( dx,  y2,  -z );
				glVertex3f  ( -dx,  y2, -z );
				glVertex3f  ( -dx, y2,  z );
				glVertex3f  ( dx, y2, z );
			glEnd ( );
			glBindTexture	(GL_TEXTURE_2D, texture [1] );
			glBegin ( GL_QUADS );//tarafe khodi
				glColor3f   ( 1, 1, 1 );
				glTexCoord2f( 1, 0 );
			    glVertex3f  ( dx,  y2,  -z );
				glTexCoord2f( 1, 1 ); 
				glVertex3f  ( dx,  y1, -z );
				glTexCoord2f( 0, 1 );
				glVertex3f  ( dx, y1, z );
				glTexCoord2f( 0, 0 );
				glVertex3f  ( dx, y2, z );
			glEnd ( );
			glBegin ( GL_LINE_LOOP );
				glColor3f ( 10, 10, 10 );
			    glVertex3f  ( dx,  y2, -z );
				glVertex3f  ( dx,  y1, -z );
				glVertex3f  ( dx, y1, z );
				glVertex3f  ( dx, y2, z );
			glEnd ( );
			glBindTexture	(GL_TEXTURE_2D, texture [1] );
			glBegin ( GL_QUADS );//tarafe harif
				glColor3f   ( 1, 1, 1 );
				glTexCoord2f( 0, 0 );
			    glVertex3f  ( -dx,  y2,  -z );
				glTexCoord2f( 0, 1 ); 
				glVertex3f  ( -dx,  y1, -z );
				glTexCoord2f( 1, 1 );
				glVertex3f  ( -dx, y1, z );
				glTexCoord2f( 1, 0 );
				glVertex3f  ( -dx, y2, z );
			glEnd ( );
			glBegin ( GL_LINE_LOOP );
				glColor3f   ( 10, 10, 10 );
			    glVertex3f  ( -dx,  y2, -z );
				glVertex3f  ( -dx,  y1, -z );
				glVertex3f  ( -dx, y1, z );
				glVertex3f  ( -dx, y2, z );
			glEnd ( );
			glBegin ( GL_LINES );//khat haye vasate safhe
			    glColor3f ( 10, 10, 10 );
			    glVertex3f  ( 0, y1, -z );
				glVertex3f  ( 0, y1, z );
				glVertex3f  ( 0, y1, z );
				glVertex3f  ( 0, y2, z );
			glEnd ( );
	for ( float i = -z;i < z;i+= dt ){
	    glBegin    ( GL_LINES );
	    glColor3f  ( 10, 10, 0 );
	    glVertex3f ( 0, ht-dt, i );
	    glVertex3f ( 0, y1, i );
	    glEnd ( );
     }
	for ( float i = y1;i <= ht;i+= dt ){
	    glBegin    ( GL_LINES );
	    glVertex3f ( 0, i, -z );
	    glVertex3f ( 0, i, z );
	    glEnd ( );
     }
	glBindTexture (GL_TEXTURE_2D, texture[25]);
    glColor3f           ( 0, 10, 0 );
    glTranslatef        ( dx-pr, y2, z-pr );
    //gluQuadricDrawStyle ( qu, GLU_SMOOTH );
    glRotatef           ( 90, 1, 0, 0 );
    gluCylinder			( qu, pr, pr, h, 10, 10 );
    glTranslatef		( 0, -dx+ ( 2*pr ), 0 );
    gluCylinder			( qu, pr, pr, h, 10, 10 );
    glTranslatef		( -2*dx+ ( 2*pr ), 0, 0 );
    gluCylinder			( qu, pr, pr, h, 10, 10 );
    glTranslatef		( 0, dx- ( 2*pr ), 0 );
    gluCylinder			( qu, pr, pr, h, 10, 10 );
}
