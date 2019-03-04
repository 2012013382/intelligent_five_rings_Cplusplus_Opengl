#ifndef defi_IL
#define defi_IL
#define CLOCKWISE 1//表示顺时针
#define ANTICLOCKWISE 0//表示逆时针
 typedef struct Color
{
	float InColor[4];
}Color;//用来存储颜色的值

typedef struct StepSave
{
	int loopNumber;//圆盘序号
	int Direction;//顺逆时针
}StepSave;

extern int StartLoop[6][11];//用来存储圆盘的初始状态，用于后来的界面显示
extern Color Loop_Color[6][11];//用来存储颜色
extern StepSave Save[1000];
extern int StepCount;//步数
extern int Number;
extern int Loop[6][11];//其中Loop[i][10]存储第i个圆环的颜色标记
///////////Test//////////
extern int TestCount;
///////////////////////
void Run();//程序的主要流程
void Start_Change_Loop_Color();
void Start_Loop_Clockwise(int Loop_Number);
void Start_Loop_Anticlockwise(int Loop_Number);//圆环逆时针旋转
void Intelligent_Loop();
void Loop_Anticlockwise(int Loop_Number);//圆环逆时针旋转
void Loop_Clockwise(int Loop_Number);//圆环顺时针旋转
void Start_Loop_Anticlockwise(int Loop_Number);//圆环逆时针旋转
void Start_Loop_Clockwise(int Loop_Number);
#endif