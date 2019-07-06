#include "Action2.h"
#include <cstdlib>
Action2::Action2 ( int len_xbarkhord, int len_zbarkhord, int len_power, int len_angle, int len_vx, int len_vz): len_xbarkhord(len_xbarkhord), len_zbarkhord (len_zbarkhord)
	, len_power(len_power), len_angle (len_angle), len_vx(len_vx), len_vz(len_vz)
{
	
}

void Action2::readFromFile ( ){
	is_defined = true;
	ifstream input ("Data/Files/raket.txt");
	int g=len_xbarkhord * len_zbarkhord * len_vx *len_vz;
	int g_prime = len_power * len_angle;
	s_a = new S_A*[g];
	for(int i=0;i<g;i++)
		s_a[i] = new S_A [g_prime];
	for (int i=0; i<g;i++){
		for (int j=0; j<g_prime;j++){
			input >> s_a[i][j].v;
			input >> s_a[i][j].m;
			s_a[i][j].is_using = false;
		}
	}
	input.close ( );
}
void Action2::sendToFile ( ){
	if (!is_defined)
		return;
	ofstream om ("Data/Files/raket.txt");
	int g=len_xbarkhord * len_zbarkhord * len_vx *len_vz;
	int g_prime = len_power * len_angle;
	for ( int i=0; i<g;i++){
		for (int j=0; j<g_prime;j++){
			om << s_a[i][j].v;
			om << " ";
			om << s_a [i][j].m;
			om << " ";

		}
		om<< endl;
	}
	om.close ( );
}

int Action2::findIndex1 (float param1, float param2, float param3, float param4){
	return ( param1*(len_zbarkhord*len_vx*len_vz) + param2 *len_vx*len_vz + param3 *len_vz + param4  );
}

int Action2::findIndex2 (float param1, float param2){
	return ( param1*len_angle + param2);
}

int Action2::scale_xbarkhord (float xbarkhord){
	 return abs(xbarkhord/0.1);
}

int Action2::scale_zbarkhord (float zbarkhord){
	if ( zbarkhord > 0.05 )
	{
		return (1.25-zbarkhord) /0.1;
	}
	else
	{
		return abs(1.25-zbarkhord)/0.1;
	}
}

int Action2::scale_vx (float vx){
	if (abs(vx) >2)
		return 0;
	else if (abs(vx) > 1)
		return 0; 
	else if (abs(vx) > 0.1)
		return 2;
	else if (abs(vx) > 0.05)
		return 3;
	else 
		return 4;
}

int Action2::scale_vz( float vz){
	if (vz>0){
		if (vz >0.01)
			return 0;
		else if (vz >0.001)
			return 1;
		else
			return 2;
	}
	else {
		if (abs(vz)>0.01)
			return 3;
		else if (abs(vz) >0.001)
			return 3;
		else
			return 5;
	}
}

int Action2::scale_angle ( float angle){
	return (angle/18);
}

int Action2::scale_power (float power){
	if (power <0)
		return 0;
	else if (power <0.002)
		return 1;
	else 
		return 2;
}