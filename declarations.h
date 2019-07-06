#ifndef __DECLARATIONS_H
#define __DECLARATIONS_H
using namespace std;

//ifstream in ("action.txt");
//ofstream out ("val.txt");
bool	keys[256];
int sd[80][2];
GLfloat j =0;
int k =3, k1, k2, k3,ki=1;
GLfloat x =0, y =0, z =-1;
gameboard f;
raket r (1, f), r2 (2, f), r3 (1, f), r4 (2, f);
toop t (f);
GLfloat LightAmbient [ ] = { 0.5f , 0.5f , 0.5f , 1.0f };
GLfloat LightDiffuse [ ] = { 1.0f , 1.0f , 1.0f , 1.0f };
GLfloat LightPosition [ ] = { 0.0f , 0.0f , 2.0f , 1.0f };
int oops =0, nnn =0, count1 =0, count2 =0, c3=0;
float uuu =0;
int  f2 =0, f3 =0;
show showall;
int ktemp =1;
int K;
toop t2( f );
ofstream out ("Data/Files/out1.txt");
ifstream in ("Data/Files/out1.txt");
ofstream out2 ("Data/Files/out2.txt");
ifstream in2 ("Data/Files/out2.txt");
ofstream out3 ("Data/Files/out3.txt");
ifstream in3 ("Data/Files/out3.txt");
int score1=0, score2=0;
vector <Action2> game_actions;
vector <Action2> Alaki;
ostream& operator <<   (ostream& fout, raket r){
	/*for (int i=0; i<r.actions.size ( );i++){
		fout << r.actions[i].angle << " " << r.actions[i].power << " "<< r.actions[i].reward << " " << r.actions[i].vx << " " <<r.actions[i].vy
			<<" "<<r.actions[i].vz<<" "<<r.actions[i].xbarkhord << " "<<r.actions[i].zbarkhord<<" ";
	}
	*/
	return fout;
}

istream& operator >>   (istream& fin, raket& r){
	return fin;
}

ifstream& operator>>    (ifstream& fin,toop& t){
   Action tmp;
   int i=0;
   if(!fin.eof()){
       fin>>tmp.y;
       i++;
   }
   if(!fin.eof()){
	   fin>>tmp.z;
	   i++;
   }
	if(!fin.eof()){
		fin>>tmp.vx;
		i++;
	}
	if(!fin.eof()){
		fin>>tmp.vy;
		i++;
	}
	if(!fin.eof()){
		fin>>tmp.vz;
		i++;
	}
	if(!fin.eof()){
		fin>>tmp.xbarkhord;
		i++;
	}
	if(!fin.eof()){
		fin>>tmp.zbarkhord;
		i++;
	}
	if(i==7)
        t.actions.push_back(tmp);
   return fin;
}

ostream& operator<< (ostream& fout, toop a ){
	
	for (int i=0;i<a.actions.size();i++){
		fout << (a.actions[i].y) << " " << (a.actions[i].z) << " " << (a.actions[i].vx) << " " <<	(a.actions[i].vy) 
			<< " " << a.actions[i].vz<< " " << a.actions[i].xbarkhord << " " << a.actions[i].zbarkhord<< endl;
	}
	return fout;
}

void makeToop( ){
	ifstream toopin("Data/Files/toop.txt");
	in.close ( );
//	cin >> t;
}

void readFromFile (Action2 & actions, show showall){
	actions.is_defined = true;
	ifstream input ("Data/Files/raket.txt");
	int g=actions.len_xbarkhord * actions.len_zbarkhord * actions.len_vx *actions.len_vz;
	int g_prime = actions.len_power * actions.len_angle;
	actions.s_a = new S_A*[g];
	for(int i=0;i<g;i++)
		actions.s_a[i] = new S_A [g_prime];
	for (int i=0; i<g;i++){
		for (int j=0; j<g_prime;j++){
			//showall.showPleaseWait (0, 0, -4, 8);
			input >> actions.s_a[i][j].v;
			input >> actions.s_a[i][j].m;
			actions.s_a[i][j].is_using = false; 
		}
	}
	input.close ( );
}

void finishToop(void){
	if (!t.is_defined)
		return;
	ofstream toopout("Data/Files/toop.txt");
	toopout << t;
	toopout.close ( );
}

void recall( ){
	f.texture[0]=texture[1];
	f.texture[1]=texture[2];
	f.texture[2]=texture[3];
	f.texture[3]=texture[4];
	f.texture[5]=texture[6];
	f.texture[6]=texture[7];
	f.texture[7]=texture[5];
	f.texture[8]=texture[8];
	for (int i=10; i<=25; i++){
		if (i!=25)
			f.texture[i]=texture[i];
	}
}

void makefile ( ){
	ifstream inn ("Data/Files/nobat.txt");
	int a;
	if (!inn.eof ( ) )
		inn >> a;
	if (a==0)
		ki = 1;
	if (a==1)
		ki=2;
	inn.close ( );
	ofstream outn ("Data/Files/nobat.txt");
	outn << (a+1)%2;
}


int InitGL (GLvoid)										// All Setup For OpenGL Goes Here
{
	if (!LoadGLTextures ( ))
		return false;
	glShadeModel		(GL_SMOOTH);							        // Enable Smooth Shading
	glClearColor		(0.3f,  0.4f,  0.4f,  0.5f);				    // Black Background
	glClearDepth		(1.0f);									        // Depth Buffer Setup
	glEnable			(GL_DEPTH_TEST);							    // Enables Depth Testing
	glDepthFunc			(GL_LEQUAL);								    // The Type Of Depth Testing To Do
	glHint				(GL_PERSPECTIVE_CORRECTION_HINT,  GL_NICEST);	// Really Nice Perspective Calculations
	f.qu =gluNewQuadric ( );
	gluQuadricNormals	(f.qu, GL_SMOOTH);
	gluQuadricTexture	(f.qu, GL_TRUE);
	f.qu2 =gluNewQuadric ( );
	gluQuadricNormals	(f.qu2, GL_SMOOTH);
	glEnable			(GL_TEXTURE_2D);
	glLightfv			(GL_LIGHT1, GL_AMBIENT , LightAmbient );
	glLightfv			(GL_LIGHT1 , GL_DIFFUSE , LightDiffuse );
	glLightfv			(GL_LIGHT1 , GL_POSITION , LightPosition );
	return TRUE;										// Initialization Went OK
}
#endif