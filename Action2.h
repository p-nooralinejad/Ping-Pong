#ifndef _ACTION2_H
#define _ACTION2_H
#include <fstream>
using namespace std;

const float GAMMA = 0.9; 
struct S_A{
	float v;
	int m;
	S_A ( ){
		v=0; 
		m=0;
	}
	bool is_using;
	int queue;
	float temp_reward; 
};

class  Action2{
public:
	bool is_defined;
	void readFromFile ( );
	int len_xbarkhord, len_zbarkhord, len_vx, len_vz;
	int len_power, len_angle;
	int scale_xbarkhord									(float xbarkhord); 
	int scale_zbarkhord									(float zbarkhord); 
	int scale_vx										(float vx);
	int scale_vz										(float vz); 
	int scale_power										(float power );
	int scale_angle										(float angle);
	S_A  ** s_a;
	Action2												( int len_xbarkhord, int len_zbarkhord, int len_power, int len_angle, int len_vx, int len_vz);
	void sendToFile										( );
	int findIndex1										( float param1, float param2, float param3, float param4);
	int findIndex2										( float param1, float param2);
};
#endif