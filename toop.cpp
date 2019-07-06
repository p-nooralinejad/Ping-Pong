#include"toop.h"
#include"gameboard.h"
#include < iostream > 
#include < fstream >
using namespace std;

toop::toop ( gameboard f ){
    r =0.06;
    x =- ( f.dx-0.1 );
    q =0.002;
    z =0;
    vz =0.0001;//jahat toop
    y =-0.3;
    vy =q;
    vx =0.1;
    a =0.000003;
    g =0.000009;
	hob=0;
	issaved=1;
	istime=0;
}



void toop::harekat (  ){
	if ( q > 0 )	
	{
		y += vy;
		vy -=a;
	}
		z += vz;
		x += vx;
	if ( q <=0 )
	{
		if ( vz > 0 && vz > g )
			vz -= g;
		if ( vz < 0 && vz < -g )
			vz += g;
		if ( vx > 0 && vx > g )
			vx -= g;
		if ( vx < 0 && vx < -g )
			vx += g;
		if (  ( vx < 0 && vx > -g ) ||  ( vx > 0 && vx < g ) )
			vx =0;
		if (  ( vz < 0 && vz > -g ) ||  ( vz > 0 && vz < g ) )
			vz =0;
	}

}

int toop::barande(gameboard f)
{
    int a=0;
	if(mn>0)
		return mn;
	if(ha>0)
		return ha;
	if(ah>0)
		return ah;
  /*  if((x>3.5||(z>f.z+r&&x>0))||((z<-f.z-r)&&x>0)&&makan1==1)
           a=1;
    if((x<(-3.5)||(z>f.z+r&&x<0)||(z<-f.z-r)&&x<0)&&makan2==1)
           a=2;*/
    if(makan2>=2)
         return 2;
    if(makan1>=2)
         return 1;
    if(a>0)
		   return a;
	if(y<f.y2)
		if(x>0)
			if(makan1==1)
				return 1;
			else
				return 2;
		else
			if(makan2==1)
				return 2;
			else 
				return 1;
    /*if(x>3.5)
	    return 2;
    if(x<-3.5)
	    return 1;*/
	return 0;
}
void toop::show ( gameboard f ){
	static int kk=0;
	glColor3f		( 1, 0.35, 0 );
	glTranslatef	( x, y, z );
	glRotatef (++kk, 1, 0, 0);
	glBindTexture (GL_TEXTURE_2D, f.texture[24]);
	gluSphere		( f.qu, r, 32, 32 );
}
void toop::barkhord ( gameboard f, vector <Action2>& board_actions, bool temp_test, raket&r2, int index , int&nobat){

    if ( y <=f.y1+r && x > -f.dx && x < f.dx && z > -f.z && z < f.z ){
		if(issaved==0 && x<0 && vx<0)
		{
			ac.xbarkhord=x;
			ac.zbarkhord=z;
			actions.push_back(ac);
			issaved=1;
		}
		if (x<0  && vx <0 && temp_test && index!= 4040){
			r2.set ( index, nobat );  
		}
		q -= g;
        vy = q;
        
		y = f.y1+r;
		//istime=0;
	if(x<0)
	{    
		makan2++;  
        makan1=0;
    }
    if(x>0)
	{      
        makan1++;
        makan2=0;
	} 
 } 
}
int toop::Raket ( raket r1, raket r2 ,int gh){
     if ( z <= ( r1.z+r1.r ) && z >= ( r1.z-r1.r ) )
         if ( x >=r1.x-r && x <=r1.x+r+vx )
     	   if ( y <= ( r1.y+r1.r+0.05 ) && y >= ( r1.y-r1.r-0.05 ) ){
			   if(!gh)
			   {
			   if(makan1==0)
			   {
				   if(hob==0)
				   ha=1;
				   else
					hob=0;
			   }
			   	vx*=-1;
			   if(vx<r1.v)
				   vx-=r1.v;
					if(x>0)
						vx-=r1.p;
			   
	
		/*if(r1.xz>90){
			if(r1.xz>270)
				vz-=((r1.xz-180)/180.0)/1000.0;
			else
				vz-=((r1.xz)/180.0)/1000.0;
		}
         if(r1.xz<90)
              vz+=((r1.xz)/180.0)/1000.0;
		 if(r1.xz>270)
			 vz+=((r1.xz-180)/180.0)/1000.0;
			   }*/
		if(r1.xz>90)
           vz-=((r1.xz)/180.0)/1000.0;
         if(r1.xz<90)
           vz+=((r1.xz)/180.0)/1000.0; 
			   }
        	   return 1;
        	   return 1;
		}

      if ( z <= ( r2.z+ r2.r ) && z >= ( r2.z-r2.r ) )
		  if (  ( x >= r2.x-r &&x <=r2.x+r ) )
           if ( y <= ( r2.y+r2.r+0.05 ) && y >= ( r2.y-r2.r-0.05 ) ){
			   if(!gh)
			   {
			   if(makan2==0)
			   {
				   if(hob==0)
				   ha=2;
				   else
					hob=0;
			   }
			vx *= -1;
			 if(r2.p>0.001){
					if(x<0)
					   vx+=r2.p;
					if(x>0)
						vx-=r2.p;
			 }
		if(r2.xz>90)
           vz-=((r2.xz)/180.0)/1000.0;
        if(r2.xz<90&&z<0)
           vz+=((r2.xz+180)/180.0)/1000.0; 
		if(r2.xz<90&&z>0)
           vz+=((r2.xz)/180.0)/1000.0; 
		}
        	   return 1;        	
         }
         return 0;
}
void toop::manage ( raket r2, int& output1, int& output2, int& output3){
	if (istime==0){
		//cout <<"beshi"<<endl;
		return;
	}
	float scale = 0.05;
	if (xbar <= r2.x+ scale && xbar>=r2.x-scale){
		output1 =1;
	}
	else if (xbar >= r2.x)
		output1 =2;
	else
		output1 =3;
	if (zbar <= r2.z+ scale && zbar>=r2.z-scale){
		output2 =1;
	}
	else if (zbar >= r2.z)
		output2 =2;
	else
		output2=3;
}
void toop::toor ( gameboard f ){
	if (  ( y < f.ht+q && x  <=r ) ||  ( y < f.ht ) ){
		if ( vx > 0 ){
			if ( x >=0-r-vx && x < 0+r ){
			vx *= -1;
			vx += 2*vx/3;
			x =-0.001-r;
			ah=2;
			}
		}
		if ( vx < 0 ){
		   if ( x <=0+r-vx && x > 0-r ){
				vx *= -1;
				vx -=2*vx/3;
				x =0.001+r;
				ah=1;
			}
		}
	}
}
bool toop::service ( gameboard f,raket&r,raket&r2,int m )
{
 	 vx = m*0.0004;
 	 x  = m*(f.dx-0.4);
 	 y  = 1;
 	 vy = 0;
	 z=0;
	 vz = 0;
		r.z=0;
		r.x=m*f.dx;
		r.y=-0.2;
		//r.p=0.002;
		r2.x=-m*f.dx;
		r2.z=0;
		r2.y=-0.2;
	r.xz=0;
	 r2.xz=0;
	 if(m<0) 
		 r.p=0.003;
	 else
		r.p=0.0005;
	 makan1=0;
	 makan2=0;
	 //xbar=-f.dx-1;
	 //zbar=0;
	 hob=1;
	// xbar = -f.dx+0.01;
	 istime=0;
	 return true;
}
void toop::checktoop ( )
{
	int c=0;
	for(int i=0;i<actions.size();i++)
		if(actions[i].z<z+0.05 && actions[i].z>z-0.05 && actions[i].y<=y+0.05 && actions[i].y>=y-0.05 && actions[i].vx<=vx+0.005 && actions[i].vx>=vx-0.05
			&& actions[i].vy<=vy+0.05 && actions[i].vy>=vy-0.05 && actions[i].vz<=vz+0.05 && actions[i].vz>=vz-0.05)
			{
				//cout <<actions[i].z<<" "<<actions[i].y<<" "<<actions[i].vx<< " "<<actions[i].vz<<" "<<actions[i].vx<<" "<<actions[i].vy<< " "<<
				//	actions[i].xbarkhord<< " "<<actions[i].zbarkhord<<endl;
				//system ("PAUSE");
				xbar=actions[i].xbarkhord-1;
				if (actions[i].zbarkhord <= 0.1 && actions[i].zbarkhord >=-0.1)
					zbar = actions[i].zbarkhord;
				
				else if (actions[i].zbarkhord >0){
					zbar = actions[i].zbarkhord +0.15;
				}
				else
					zbar = actions[i].zbarkhord -0.25;
				if (vx <= -0.003 && vy>0){
					if (actions[i].vz>0)
						zbar = zbar - 0.5;
					else
						zbar = zbar + 0.5;
				}
				//cout <<this ->vy<<endl;
				//system ("PAUSE");
				istime=1;
				issaved=1;
				c=1;
				break;
			}
		if(c==0)
		{
			//cout <<"saving"<<endl;
			issaved=0;
			ac.vx=vx;
			ac.y=y;
			ac.z=z;
			ac.vz=vz;
			ac.vy=vy;
			ac.zbarkhord = 0;
			ac.xbarkhord = -10;
		}
}

int toop::setreward(raket r,gameboard f,int x,int y){

	return 0;
}