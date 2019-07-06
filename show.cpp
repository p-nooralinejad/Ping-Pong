#include"show.h" //show library
#include <cmath>
int kalam=0, mmm = 0, lll = 0,c,fff=0;

void show::pointer ( toop t, raket r, gameboard f, int k ){
		if ( k == 3 ){
			glBegin ( GL_LINES );
			    glColor3f  ( 1, 1, 0 );
			    glVertex3f ( f.dx, f.y1+0.1, t.z );
			    glVertex3f ( f.dx, f.y1, t.z );
			glEnd ( );
		}
		/*if ( k =  = 1 ){
			    glColor3f ( 1, 1, 0 );
			    glVertex3f ( 0, 0, 0 );
			glBegin ( GL_LINES );
			    glVertex3f ( 10, 0, 0 );
			glEnd ( );
		}*/
}

void show::showallInTheLastMove (gameboard f, int i){
	glLoadIdentity ( );
	glTranslatef (0, 0, -14);
	if (i==1)
	{
		glBindTexture	(GL_TEXTURE_2D, f.texture[22]);
		glBegin (GL_QUADS);
			glColor3f		(1,1,1);
			glTexCoord2f	(1.0f, 1.0f);
			glVertex3f		(38.5, 27.5, -30);
			glTexCoord2f	(0.0f, 1.0f);
			glVertex3f		(-38.5, 27.5, -30);
			glTexCoord2f	(0.0f, 0.0f);
			glVertex3f		(-38.5, -27.5, -30);
			glTexCoord2f	(1.0f, 0.0f);
			glVertex3f		(38.5, -27.5, -30);
		glEnd ( );
	}
	else
	{
		glBindTexture	(GL_TEXTURE_2D, f.texture[23]);
		glBegin (GL_QUADS);
			glColor3f		(1, 1, 1);
			glTexCoord2f	(1.0f, 1.0f);
			glVertex3f		(38.5, 27.5, -30);
			glTexCoord2f	(0.0f, 1.0f);
			glVertex3f		(-38.5, 27.5, -30);
			glTexCoord2f	(0.0f, 0.0f);
			glVertex3f		(-38.5, -27.5, -30);
			glTexCoord2f	(1.0f, 0.0f);
			glVertex3f		(38.5, -27.5, -30);
		glEnd ( );
	}
}

float Y, Z;
void show::showall ( gameboard &f, toop &t, raket &r, raket &r2, int k, int k1, int k2, int k3, float i, float j, float zoom, bool keys[256]
	,vector <Action2>& gameAction, bool tr, int&episod, int joy ){
	for (float i=0; i<0.05;i+=0.01){
		glLoadIdentity	( );
		glTranslatef	( 0, 0, -4 );
		glBegin			( GL_LINE_LOOP );
			glColor3f	( 1, 0, 0 );
			glVertex3f	( -6-i, 9-i, -10 );
			glColor3f	( 0, 1, 0 );
			glVertex3f	( -6-i, 2-i, -10 );
			glColor3f	( 0, 0, 1 );
			glVertex3f	( -15.35-i, 2-i, -10 );
			glColor3f	( 1, 1, 1 );
			glVertex3f	( -15.35-i, 9-i, -10 );
		glEnd ( );
		glBegin ( GL_LINE_LOOP );
			glColor3f	( 1, 0, 0 );
			glVertex3f	( -5.5-i, 9-i, -10 );
			glColor3f	( 0, 1, 0 );
			glVertex3f	( -5.5-i, 2-i, -10 );
			glColor3f	( 0, 0, 1 );
			glVertex3f	( 5.5-i, 2-i, -10 );
			glColor3f	( 1, 1, 1 );
			glVertex3f	( 5.5-i, 9-i, -10 );
		glEnd ( );
		glBegin ( GL_LINE_LOOP );
			glColor3f	( 1, 0, 0 ); 
			glVertex3f	( 6-i, 9-i, -10 );
			glColor3f	( 0, 1, 0 );
			glVertex3f	( 6-i, 2-i, -10 );
			glColor3f	( 0, 0, 1 );
			glVertex3f	( 15.35-i, 2-i, -10 );
			glColor3f	( 1, 1, 1 );
			glVertex3f	( 15.35-i, 9-i, -10 );
		glEnd ( );
		glLoadIdentity	( );
	}
		glTranslatef	( i, j, zoom );
		if ( mmm == 0 )
		{
			t.service ( f ,r,r2,1);
		}
		mmm=1;
		r.power ( );
		glLoadIdentity ( );
		glTranslatef ( i, j, zoom );
		if ( k !=  3 ){
				 glRotatef ( 90, k1, k2, k3 );
				 if (k==1 )
				 glRotatef ( -10, 0, 0, 1);
		}
		pointer			( t, r, f, k );
		t.show			( f );
		glLoadIdentity	( );
		glTranslatef	( i, j, zoom );
		t.harekat		( );
		t.toor			( f ); 
		if ( k !=  3 ){
				  glRotatef ( 90, k1, k2, k3 );
				  if (k==1 )
				  glRotatef (-10 , 0, 0, 1);
		}
		f.show			( );
		glLoadIdentity	( );
		glTranslatef	( i, j, zoom );
	
		if ( k !=  3 ){
			glRotatef ( 90, k1, k2, k3 );
			if (k==1 )
			glRotatef (-10 , 0, 0, 1);
		 }
	
		r2.show			( f, 2 );
		glLoadIdentity	( );
		glTranslatef	( i, j, zoom );
	
		if ( k !=  3 ){
			glRotatef ( 90, k1, k2, k3 );
			if (k==1 )
			glRotatef	( -10, 0, 0, 1 );
		 }
    
		if ( r2.z>1.25 )
			r2.xz = 60;
		if ( r2.z<-1.25 ){
			r2.xz = -60;
		}
		r.show			( f, 1 );
		r.harekat		( f, keys, k , joy);
		c=t.Raket(r,r2,fff);
		if (c==1 )
		r.p = -0.002;
		if ( c==2 )
		r2.p = -0.002;
		if(c!=0)
		fff=1;
		if(c==0)
		fff=0;
		int p=0;
		if(t.x>=-0.01 && t.x<=+0.01 &&t.vx<0){
			//cout <<"salam bacha ha";
			t.checktoop( );
		//cout <<"kalam:"<<kalam<<endl;
		}
		int o1=0, o2=0, o3=0;
		t.manage(r2, o1, o2, o3);
		int lin = r2.actions.findIndex1(r2.actions.scale_xbarkhord (t.x),r2.actions.scale_zbarkhord (t.z),r2.actions.scale_vx (t.vx)
			,r2.actions.scale_vz (t.vz));
    r2.harekat1		( f, o1, o2, o3, lin);
	if(tr)
		t.barkhord		( f, gameAction,tr,r2, lin, episod);
 		
	//p=1;
  /*  kalam = t.manage( r2 );
    r2.harekat1		( f, kalam);
*/
}
void show::showallInTheFirstMove ( gameboard&f, toop&t, raket&r, raket&r2, int k, int k1, int k2, int k3, float i, float j, float zoom, bool keys[256], int alaK ){
	glLoadIdentity	( );
	glTranslatef	( 0, 0, -4 );
	glBegin			( GL_LINE_LOOP );
	    glColor3f	( 1, 0, 0 );
	    glVertex3f	( -6, 9, -10 );
	    glColor3f	( 0, 1, 0 );
	    glVertex3f	( -6, 2, -10 );
	    glColor3f	( 0, 0, 1 );
	    glVertex3f	( -15.35, 2, -10 );
	    glColor3f	( 1, 1, 1 );
	    glVertex3f	( -15.35, 9, -10 );
	glEnd ( );
	glBegin ( GL_LINE_LOOP );
	    glColor3f	( 1, 0, 0 );
	    glVertex3f	( -5.5, 9, -10 );
	    glColor3f	( 0, 1, 0 );
	    glVertex3f	( -5.5, 2, -10 );
	    glColor3f	( 0, 0, 1 );
	    glVertex3f	( 5.5, 2, -10 );
	    glColor3f	( 1, 1, 1 );
	    glVertex3f	( 5.5, 9, -10 );
	glEnd ( );
	glBegin ( GL_LINE_LOOP );
	    glColor3f	( 1, 0, 0 );
	    glVertex3f	( 6, 9, -10 );
	    glColor3f	( 0, 1, 0 );
	    glVertex3f	( 6, 2, -10 );
	    glColor3f	( 0, 0, 1 );
	    glVertex3f	( 15.35, 2, -10 );
	    glColor3f	( 1, 1, 1 );
	    glVertex3f	( 15.35, 9, -10 );
	glEnd ( );
	glLoadIdentity ( );
	glTranslatef	( i, j, zoom );
	if ( lll == 0 )
	{
		t.service ( f ,r,r2,1);

		lll = 1;
	}
	r.power			( );
	glLoadIdentity	( );
	glTranslatef ( i, j, zoom );
	if ( k !=  3 ){
             glRotatef ( 90, k1, k2, k3 );
             if (k==1 )
             glRotatef (-3 , 0, 0, 1);
    }
	pointer			( t, r, f, k );
	t.show			( f );
	glLoadIdentity	( );
	glTranslatef	( i, j, zoom );
	t.harekat		( );
	vector <Action2> alaki;
 	t.barkhord		( f, alaki, 0, r2, -4040, alaK);
 	t.toor ( f );
    if ( k !=  3 ){
              glRotatef ( 90, k1, k2, k3 );
              if (k==1 )
              glRotatef (-3 , 0, 0, 1);
    }
    f.show			( );
    glLoadIdentity	( );
	glTranslatef	( i, j, zoom );
	if ( k !=  3 ){
	    glRotatef ( 90, k1, k2, k3 );
	    if (k==1 )
	    glRotatef (-3 , 0, 0, 1);
     }
	r2.show			( f, 2 );
    glLoadIdentity	( );
	glTranslatef	( i, j, zoom );
	if ( k !=  3 ){
	    glRotatef ( 90, k1, k2, k3 );
	    if (k!=0 )
	    glRotatef (-10, 0, 0, 1);
     }
    if ( r2.z>1.25 )
        r2.xz = 60;
    if ( r2.z<-1.25 ){
        r2.xz = -60;
    }
	r.show				( f, 1 );
	int alak=0;
	c=t.Raket(r,r2,alak);
	if ( c==1 )
	r.p = 0.001;
	if ( c==2 )
	r2.p = 0.000;
   // kalam = t.manage	( r2 );
   // r2.harekat1			( f, kalam );

}
void show::showKTEMP (int o){
    glLoadIdentity ( );
	glTranslatef (0, 0, -4);

	if (o == 1){
		glBegin (GL_LINE_LOOP);
		    glColor3f	(1, 1, 0);
		    glVertex3f	(-6, 9, -10);
		    glVertex3f	(-6, 2, -10);
		    glVertex3f	(-15.35, 2, -10);
		    glVertex3f	(-15.35, 9, -10);
		glEnd ( );
	}

	if (o == 0){
		glBegin (GL_LINE_LOOP);
		    glColor3f	(1, 1, 0);
		    glVertex3f	(-5.5, 9, -10);
		    glVertex3f	(-5.5, 2, -10);
		    glVertex3f	(5.5, 2, -10);
		    glVertex3f	(5.5, 9, -10);
		glEnd ( );
	}

	if (o == 3){
		glBegin (GL_LINE_LOOP);
		    glColor3f	(1, 1, 0);
		    glVertex3f	(6, 9, -10);
		    glVertex3f	(6, 2, -10);
		    glVertex3f	(15.35, 2, -10);
		    glVertex3f	(15.35, 9, -10);
		glEnd ( );
	}
}
void show::showallTextures ( gameboard f, int k ){
	if (1){
		glLoadIdentity	( );
		glTranslatef	(0, 1, -2.75);
		GLfloat y = -2, kx = 0.75, ky = 1.125, x = -3; 
		glBindTexture	(GL_TEXTURE_2D, f.texture[5]);
		glBegin	(GL_QUADS);
			glColor3f	(1, 1, 1);
			glTexCoord2f(1, 1);
			glVertex3f	(x+ky, y, 0);
			glTexCoord2f(0, 1);
			glVertex3f	(x, y, 0);
			glTexCoord2f(0, 0);
			glVertex3f	(x, y-kx, 0);
			glTexCoord2f(1, 0);
			glVertex3f	(x+ky, y-kx, 0);
		glEnd ( );
		x += ky;
		x += 0.5;
		glLoadIdentity	( );
		glTranslatef	(0, 1, -2.75);
		if (k!=1){
			glBindTexture	(GL_TEXTURE_2D, f.texture[6]);
			glBegin	(GL_QUADS);
				glColor3f	(1, 1, 1);
				glTexCoord2f(0, 1);
				glVertex3f	(x,  y, 0);
				glTexCoord2f(1, 1);
				glVertex3f	(x+ky,  y, 0);
				glTexCoord2f(1, 0);
				glVertex3f	(x+ky, y-kx, 0);
				glTexCoord2f(0, 0);
				glVertex3f	(x, y-kx, 0);
			glEnd ( );
		}
		x += ky;
		x += 0.5;
		glLoadIdentity	( );
		glTranslatef	(0, 1, -2.75);
		if (k!=1){
			glBindTexture	(GL_TEXTURE_2D, f.texture[7]);
			glBegin	(GL_QUADS);
				glColor3f	(1, 1, 1);
				glTexCoord2f(0, 1);
				glVertex3f	(x,  y, 0);
				glTexCoord2f(1, 1);
				glVertex3f	(x+ky,  y, 0);
				glTexCoord2f(1, 0);
				glVertex3f	(x+ky,y-kx, 0);
				glTexCoord2f(0, 0);
				glVertex3f	(x,y-kx, 0);
			glEnd ( );
		}
		x += ky;
		x += 0.5;
		glLoadIdentity	( );
		glTranslatef	(0, 1, -2.75);
		glBindTexture	(GL_TEXTURE_2D, f.texture[8]);
		glBegin	(GL_QUADS);
			glColor3f	(1, 1, 1);
			glTexCoord2f(0, 1);
			glVertex3f	(x,  y, 0);
			glTexCoord2f(1, 1);
			glVertex3f	(x+ky,  y, 0);
			glTexCoord2f(1, 0);
			glVertex3f	(x+ky,y-kx, 0);
			glTexCoord2f(0, 0);
			glVertex3f	(x,y-kx, 0);
		glEnd ( );
	}
}
int uuu=0, uuuu=0;
void show::scoreBoard (gameboard f, toop &t, int& score1, int& score2,raket &r,raket&r2 ,int ki, vector <Action2>& game_actions, int&nobat/*, int& landa*/){
	int l=t.barande(f);
	if(ki==1){
	glLoadIdentity ();
	glTranslatef (1.5, 2.5, -4);
	if ( l == 2){
		t.issaved =1;
		int reward =1000;
		t.mn=2;
		if (uuu<361)
		glRotatef (uuu++, 1, 0.0, 0);
		if (uuu >= 360 ){
			nobat=0;
			if(((score1+score2)/2)%2==0)
			t.service( f,r,r2,1);
			else
			t.service(f,r2,r,-1);
			kalam=0;
			game_actions.clear ( );
			t.issaved=1;
			uuu=0;
			t.ah=0;
			t.ha=0;
			t.mn=0;
		}
		if (uuu == 150){
			score1++;
		}
		for (int i=0; i<r2.actions.len_xbarkhord *r2.actions.len_vx *r2.actions.len_zbarkhord *r2.actions.len_vz; i++){
			for (int j=0; j<r2.actions.len_angle * r2.actions.len_power; j++)
			{
				if (r2.actions.s_a[i][j].is_using == true)
				{
 					r2.actions.s_a[i][j].temp_reward = pow (GAMMA, (nobat-r2.actions.s_a[i][j].queue+1))*reward;
					r2.actions.s_a[i][j].is_using =false;
					r2.actions.s_a[i][j].queue =0;
					float gj= r2.actions.s_a[i][j].v * r2.actions.s_a[i][j].m;
					gj += r2.actions.s_a[i][j].temp_reward;
					r2.actions.s_a[i][j].m++;
					gj /= r2.actions.s_a[i][j].m;
					r2.actions.s_a[i][j].v = gj;
				}
			}
		} 
		nobat =0;
	}
	glBindTexture ( GL_TEXTURE_2D, f.texture [10+score1] );
	glBegin (GL_QUADS);
		glBindTexture ( GL_TEXTURE_2D, f.texture [10+score1] );
		glVertex3f	(-0.45, -0.75, 0);
		glTexCoord2f(0, 1);
		glVertex3f	(-0.45,0, 0);
		glTexCoord2f(1, 1);
		glVertex3f	(0, 0, 0);
		glTexCoord2f(1, 0);
		glVertex3f	(0, -0.75, 0);
	glEnd ( );
	glLoadIdentity ();
	glTranslatef (-1, 2.5, -4);
	if ( l == 1){
		t.issaved =1;
		int reward =3000;
		t.mn=1;
		if(uuuu<361)
		glRotatef (uuuu++, 1, 0, 0);
		if (uuuu >= 360 ){
			nobat =0;
			if(((score1+score2)/2)%2==0)
			t.service( f,r,r2,1);
			else
			t.service(f,r2,r,-1);
			kalam=0;
			game_actions.clear ( );
			t.issaved=1;
			uuuu=0;
			t.ah=0;
			t.ha=0;
			t.mn=0;
		}
		if (uuuu == 150)
		{
			score2++;

		}
		for (int i=0; i<r2.actions.len_xbarkhord *r2.actions.len_vx *r2.actions.len_zbarkhord *r2.actions.len_vz; i++){
			for (int j=0; j<r2.actions.len_angle * r2.actions.len_power; j++)
			{
				if (r2.actions.s_a[i][j].is_using == true)
				{					
					r2.actions.s_a[i][j].temp_reward = pow (GAMMA, (nobat-r2.actions.s_a[i][j].queue+1))*reward;
					r2.actions.s_a[i][j].is_using =false;
					r2.actions.s_a[i][j].queue =0;
					float gj= r2.actions.s_a[i][j].v * r2.actions.s_a[i][j].m;
					gj += r2.actions.s_a[i][j].temp_reward;
					r2.actions.s_a[i][j].m++;
					gj /= r2.actions.s_a[i][j].m;
					r2.actions.s_a[i][j].v = gj;
				}
			}
		}
		nobat =0;
	}
	glBindTexture ( GL_TEXTURE_2D, f.texture [10+score2] );
	glBegin (GL_QUADS);
		glColor3f   (1, 1, 1);
		glTexCoord2f(0, 0);
		glVertex3f  (-0.45, -0.75, 0);
		glTexCoord2f(0, 1);
		glVertex3f  (-0.45, 0, 0);
		glTexCoord2f(1, 1);
		glVertex3f  (0, 0, 0);
		glTexCoord2f(1, 0);
		glVertex3f  (0, -0.75, 0);
	glEnd ();
}
	if(ki==2){
	glLoadIdentity ();
	glTranslatef (1.5, 2.5, -4);
	if ( l == 2){
		t.issaved =1;
		int reward =1000;
		t.mn=2;
		if (uuu<361)
		glRotatef (uuu++, 0, 0.0, 0);
		if (uuu >= 360 ){
			nobat=0;
			if(((score1+score2)/2)%2==0)
			t.service( f,r,r2,1);
			else
			t.service(f,r2,r,-1);
			kalam=0;
			game_actions.clear ( );
			t.issaved=1;
			uuu=0;
			t.ah=0;
			t.ha=0;
			t.mn=0;
		}
		if (uuu == 150){
			score1++;
		}
		for (int i=0; i<r2.actions.len_xbarkhord *r2.actions.len_vx *r2.actions.len_zbarkhord *r2.actions.len_vz; i++){
			for (int j=0; j<r2.actions.len_angle * r2.actions.len_power; j++)
			{
				if (r2.actions.s_a[i][j].is_using == true)
				{
					r2.actions.s_a[i][j].temp_reward = pow (GAMMA, (nobat-r2.actions.s_a[i][j].queue+1))*reward;
					r2.actions.s_a[i][j].is_using =false;
					r2.actions.s_a[i][j].queue =0;
					float gj= r2.actions.s_a[i][j].v * r2.actions.s_a[i][j].m;
					gj += r2.actions.s_a[i][j].temp_reward;
					r2.actions.s_a[i][j].m++;
					gj /= r2.actions.s_a[i][j].m;
					r2.actions.s_a[i][j].v = gj;
				}
			}
		} 
		nobat =0;
	}
	glBindTexture ( GL_TEXTURE_2D, f.texture [10+score1] );
	glBegin (GL_QUADS);
		glBindTexture ( GL_TEXTURE_2D, f.texture [10+score1] );
		glVertex3f	(-0.45, -0.75, 0);
		glTexCoord2f(0, 1);
		glVertex3f	(-0.45,0, 0);
		glTexCoord2f(1, 1);
		glVertex3f	(0, 0, 0);
		glTexCoord2f(1, 0);
		glVertex3f	(0, -0.75, 0);
	glEnd ( );
	glLoadIdentity ();
	glTranslatef (-1, 2.5, -4);
	if ( l == 1){
		t.issaved =1;
		int reward =3000;
		t.mn=1;
		if(uuuu<361)
		glRotatef (uuuu++, 0, 0, 0);
		if (uuuu >= 360 ){
			nobat =0;
			if(((score1+score2)/2)%2==0)
			t.service( f,r,r2,1);
			else
			t.service(f,r2,r,-1);
			kalam=0;
			game_actions.clear ( );
			t.issaved=1;
			uuuu=0;
			t.ah=0;
			t.ha=0;
			t.mn=0;
		}
		if (uuuu == 150)
		{
			score2++;

		}
		for (int i=0; i<r2.actions.len_xbarkhord *r2.actions.len_vx *r2.actions.len_zbarkhord *r2.actions.len_vz; i++){
			for (int j=0; j<r2.actions.len_angle * r2.actions.len_power; j++)
			{
				if (r2.actions.s_a[i][j].is_using == true)
				{
					r2.actions.s_a[i][j].temp_reward = pow (GAMMA, (nobat-r2.actions.s_a[i][j].queue+1))*reward;
					r2.actions.s_a[i][j].is_using =false;
					r2.actions.s_a[i][j].queue =0;
					float gj= r2.actions.s_a[i][j].v * r2.actions.s_a[i][j].m;
					gj += r2.actions.s_a[i][j].temp_reward;
					r2.actions.s_a[i][j].m++;
					gj /= r2.actions.s_a[i][j].m;
					r2.actions.s_a[i][j].v = gj;
				}
			}
		}
		nobat =0;
	}
	glBindTexture ( GL_TEXTURE_2D, f.texture [10+score2] );
	glBegin (GL_QUADS);
		glColor3f   (1, 1, 1);
		glTexCoord2f(0, 0);
		glVertex3f  (-0.45, -0.75, 0);
		glTexCoord2f(0, 1);
		glVertex3f  (-0.45, 0, 0);
		glTexCoord2f(1, 1);
		glVertex3f  (0, 0, 0);
		glTexCoord2f(1, 0);
		glVertex3f  (0, -0.75, 0);
	glEnd ();
}
}

void show::showWhiteBack ( GLuint texture){
	glBindTexture (GL_TEXTURE_2D, texture);
	glLoadIdentity ( );
	glTranslatef (0, 0, -4);
	glBegin (GL_QUADS);
		glColor3f (1, 1, 1);
		glTexCoord2f (0, 0);
		glVertex3f (-4.4, 2.8, 0);
		glTexCoord2f (1, 0);
		glVertex3f (4.4, 2.8, 0);
		glTexCoord2f (1, 1);
		glVertex3f (4.4, -2.8, 0);
		glTexCoord2f (0, 1);
		glVertex3f (-4.4, -2.8, 0);
	glEnd ( );
}

void show::showPleaseWait ( GLfloat x_pos, GLfloat y_pos, GLfloat z_pos, int num )
{
	glColor3f (0, 0, 1);
	glLoadIdentity ( );
	glTranslatef (x_pos, y_pos, z_pos);
	unsigned static int gardesh =0;
	gardesh+=1;
	static int number = 0;
	(gardesh%30==0)?number++:0;
	for (int i=0; i<num; i++)//showing the PLEASE WAIT!
	{
		glLoadIdentity ( );
		glTranslatef (x_pos, y_pos, z_pos);
		glRotatef (-(360/num)*i, 0, 0, 1);
		glBegin (GL_QUADS);
			glColor3f (0, 0, 1);
			if (i==number%num)
				glColor3f (1, 0.5, 0);
			glVertex3f (  -0.1, 0.4, 0);
			glVertex3f (  -0.1, 1.15, 0);
			glVertex3f (   0.1, 1.15, 0);
			glVertex3f (   0.1, 0.4, 0);
		glEnd ( );
	}
}

