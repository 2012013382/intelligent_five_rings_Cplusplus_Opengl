#include<iostream>
#include<Windows.h>
#ifndef GLUT_DISABLE_ATEXIT_HACK  
#define GLUT_DISABLE_ATEXIT_HACK 
#endif  
#include <glut.h>
#include"View_Show.h"
using namespace std;
int main(int argc,char **argv)
{
	glutInit(& argc,argv);
    InitGraph();
	return 0;
}