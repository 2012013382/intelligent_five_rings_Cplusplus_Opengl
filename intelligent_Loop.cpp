#include"intelligent_Loop.h"
//一共有六个圆环，一个大环和五个小环，利用Loop数组表示即可，Loop中存储的是色子的颜色信息
//Loop[0]表示大圆环，1～5表示5个小圆环，大圆环有10个色子，小圆环有7个色子
//总共有5种颜色，分别为红（1），绿（2），蓝（3），浅蓝（4），紫（5）
//红色(1.0,0.3,0,0）
//绿色(0.3,1.0,0,0)
//蓝色(0.0,0.05,1.0,0)
//浅蓝(0.3,0.9,0.9,0)
//紫色(0.5,0.1,0.5,0)
////////////test////////////
int TestCount=0;
//////////////////////////
int Loop[6][11];//其中Loop[i][10]存储第i个圆环的颜色标记
int StartLoop[6][11];//用来存储圆盘的初始状态，用于后来的界面显示
int StepCount=0;//步数
int surflag;
int OnceFlag=1;
int Number=0;
Color Loop_Color[6][11];//用来存储颜色

StepSave Save[1000];//用于储存转动圆盘的方法

void Change_Loop_Color()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++)
		{
			switch(Loop[i][j]){
			case 0://赋值为红色
				{
					Loop_Color[i][j].InColor[0]=1.0;
					Loop_Color[i][j].InColor[1]=0.3;
					Loop_Color[i][j].InColor[2]=0.0;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 1://赋值为绿色
				{
					Loop_Color[i][j].InColor[0]=0.3;
					Loop_Color[i][j].InColor[1]=1.0;
					Loop_Color[i][j].InColor[2]=0.0;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 2://赋值为蓝色
				{
					Loop_Color[i][j].InColor[0]=0.0;
					Loop_Color[i][j].InColor[1]=0.05;
					Loop_Color[i][j].InColor[2]=1.0;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 3://赋值为浅蓝
				{
					Loop_Color[i][j].InColor[0]=0.3;
					Loop_Color[i][j].InColor[1]=0.9;
					Loop_Color[i][j].InColor[2]=0.9;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 4://赋值为紫色
				{
					Loop_Color[i][j].InColor[0]=0.5;
					Loop_Color[i][j].InColor[1]=0.1;
					Loop_Color[i][j].InColor[2]=0.5;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
			}
		}
	}
}

void Init_Loop()//对圆环中的色子颜色进行初始化
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++)
		{
			Loop[i][j]=i;
			Loop[i][10]=i;//表示Loop[i]的底盘颜色标记为i
		}
	}
}

void Loop_Clockwise(int Loop_Number)//圆环顺时针旋转
{
	if(Loop_Number==5)//如果为大圆环
	{
		int temp3;
		int temp4;
		temp3=Loop[0][3];
		temp4=Loop[0][4];
		Loop[0][3]=Loop[4][3];
		Loop[0][4]=Loop[4][4];
		for(int i=3;i>0;i--)
		{
			Loop[(i+1)][3]=Loop[i][3];
			Loop[(i+1)][4]=Loop[i][4];
		}
		Loop[1][3]=temp3;
		Loop[1][4]=temp4;
	}
	else //如果为小圆环
	{
		int temp=-1;
		temp=Loop[Loop_Number][6];
		for(int i=5;i>=0;i--)
		{
			Loop[Loop_Number][i+1]=Loop[Loop_Number][i];
		}
		Loop[Loop_Number][0]=temp;
	}
	Change_Loop_Color();
}

void Loop_Anticlockwise(int Loop_Number)//圆环逆时针旋转
{
	if(Loop_Number==5)//如果为大圆环
	{
		int temp3;
		int temp4;
		temp3=Loop[0][3];
		temp4=Loop[0][4];
		Loop[0][3]=Loop[1][3];
		Loop[0][4]=Loop[1][4];
		for(int i=1;i<=3;i++)
		{
			Loop[i][3]=Loop[i+1][3];
			Loop[i][4]=Loop[i+1][4];
		}
		Loop[4][3]=temp3;
		Loop[4][4]=temp4;
	}
	else //如果为小圆环
	{
		int temp=-1;
		temp=Loop[Loop_Number][0];
		for(int i=1;i<=6;i++)
		{
			Loop[Loop_Number][i-1]=Loop[Loop_Number][i];
		}
		Loop[Loop_Number][6]=temp;
	}
	Change_Loop_Color();
}



///////Test////////////
void Start_Change_Loop_Color()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++)
		{
			switch(StartLoop[i][j]){
			case 0://赋值为红色
				{
					Loop_Color[i][j].InColor[0]=1.0;
					Loop_Color[i][j].InColor[1]=0.3;
					Loop_Color[i][j].InColor[2]=0.0;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 1://赋值为绿色
				{
					Loop_Color[i][j].InColor[0]=0.3;
					Loop_Color[i][j].InColor[1]=1.0;
					Loop_Color[i][j].InColor[2]=0.0;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 2://赋值为蓝色
				{
					Loop_Color[i][j].InColor[0]=0.0;
					Loop_Color[i][j].InColor[1]=0.05;
					Loop_Color[i][j].InColor[2]=1.0;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 3://赋值为浅蓝
				{
					Loop_Color[i][j].InColor[0]=0.3;
					Loop_Color[i][j].InColor[1]=0.9;
					Loop_Color[i][j].InColor[2]=0.9;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
				case 4://赋值为紫色
				{
					Loop_Color[i][j].InColor[0]=0.5;
					Loop_Color[i][j].InColor[1]=0.1;
					Loop_Color[i][j].InColor[2]=0.5;
					Loop_Color[i][j].InColor[3]=0.0;
					break;
				}
			}
		}
	}
}

void Start_Loop_Clockwise(int Loop_Number)
{
	
	if(Loop_Number==5)//如果为大圆环
	{
		int temp3;
		int temp4;
		temp3=StartLoop[0][3];
		temp4=StartLoop[0][4];
		StartLoop[0][3]=StartLoop[4][3];
		StartLoop[0][4]=StartLoop[4][4];
		for(int i=3;i>0;i--)
		{
			StartLoop[(i+1)][3]=StartLoop[i][3];
			StartLoop[(i+1)][4]=StartLoop[i][4];
		}
		StartLoop[1][3]=temp3;
		StartLoop[1][4]=temp4;
	}
	else //如果为小圆环
	{
			////////////////Test////////////
		if(TestCount==8)
		{
			int llll=0;
			llll=llll+1;
		}

		/////////////////////
		int temp=-1;
		temp=StartLoop[Loop_Number][6];
		for(int i=5;i>=0;i--)
		{
			StartLoop[Loop_Number][i+1]=StartLoop[Loop_Number][i];
		}
		StartLoop[Loop_Number][0]=temp;
	}
	Start_Change_Loop_Color();
}

void Start_Loop_Anticlockwise(int Loop_Number)//圆环逆时针旋转
{
	if(Loop_Number==5)//如果为大圆环
	{
		int temp3;
		int temp4;
		temp3=StartLoop[0][3];
		temp4=StartLoop[0][4];
		StartLoop[0][3]=StartLoop[1][3];
		StartLoop[0][4]=StartLoop[1][4];
		for(int i=1;i<=3;i++)
		{
			StartLoop[i][3]=StartLoop[i+1][3];
			StartLoop[i][4]=StartLoop[i+1][4];
		}
		StartLoop[4][3]=temp3;
		StartLoop[4][4]=temp4;
	}
	else //如果为小圆环
	{
	
		int temp=-1;
		temp=StartLoop[Loop_Number][0];
		for(int i=1;i<=6;i++)
		{
			StartLoop[Loop_Number][i-1]=StartLoop[Loop_Number][i];
		}
		StartLoop[Loop_Number][6]=temp;
	}
	Start_Change_Loop_Color();
}
/////////////////////









int hideTwoChesses(int j)
{

	/////////////////test////////////
	if(Loop[4][3]==3&&Loop[4][4]==3&&Loop[4][2]==2&&Loop[4][1]==2)
	{

	}
	////////////////////////////
	int i;
	int chess,temp1,temp2,temp3,temp4,temp5,temp6;
	chess=Loop[j][10];//令chess等于圆盘j的底色
	for(i=0;i<5;i++)
	{
		temp1=Loop[i][1];
		temp2=Loop[i][2];
		temp3=Loop[i][3];
		temp4=Loop[i][4];
		temp5=Loop[i][5];
		temp6=Loop[i][6];

		if(chess==Loop[i][10])
		{
			
            if(temp3==chess)
            {

                break;
            }
            else
                continue;
		}
		else
		{
			if(temp3==chess)
			{
				//逆时针旋转i环
				Loop_Anticlockwise(i);
				Save[StepCount].Direction=ANTICLOCKWISE;
				Save[StepCount].loopNumber=i;
				StepCount++;

				//逆时针旋转i环
				Loop_Anticlockwise(i);
				Save[StepCount].Direction=ANTICLOCKWISE;
				Save[StepCount].loopNumber=i;
				StepCount++;

				break;
			}
			  else if(temp5==chess || temp2==chess)
            {
                surflag=1;          //标志置1
                break;
            }
		}


	}
	return i;
}


void Intelligent_Loop()
{
	

	int temp1,temp2,temp3,temp4;
	int i;
	int firstFlag=1;//全局变量，控制“第一步完成”的出提示只出现一次
	while(1)
	{
		for(int i=0;i<5;i++)//依次检查小环的状态
		{
			int flag1=0;
			for(int j=0;j<7;j++)
			{
				if(Loop[i][j]!=Loop[i][10]&&Loop[i][(j+1)%7]!=Loop[i][10])
					flag1=1;//存在连续两个色子的颜色都和当前转盘颜色不同
				if(Loop[i][j]==Loop[i][(j+1)%7]&&Loop[i][j]!=Loop[i][10])
				{//表示存在连续两个色子的颜色相同，且当前色子与该环的颜色不同
					flag1=2;
					break;
				}
			}

			for(int j=0;j<6;j++)
			{
				temp1=Loop[i][3];
				temp2=Loop[i][4];

				if(flag1==1)
				{
					if(temp1==Loop[i][10]||temp2==Loop[i][10])
					{
						Loop_Clockwise(i);//顺时针旋转环i
						Save[StepCount].Direction=CLOCKWISE;
						Save[StepCount].loopNumber=i;
						StepCount++;
					}
				}
				else if(flag1==0)
				{
					if(	temp2==Loop[i][10])
					{
					Loop_Clockwise(i);//顺时针旋转环i
					    Save[StepCount].Direction=CLOCKWISE;
						Save[StepCount].loopNumber=i;
						StepCount++;
					}
				}
				else if(flag1==2)
				{
					if(temp1!=temp2 || temp1==Loop[i][10] || temp2==Loop[i][10])
					{
						Loop_Clockwise(i);//顺时针旋转环i
						Save[StepCount].Direction=CLOCKWISE;
						Save[StepCount].loopNumber=i;
						StepCount++;
					}
				}
				else   //不同则退出
					break;
			}

		}

		bool flag = 0;
		int temp;
		int j[5];
		for(int i=0;i<5;i++)
		{
			for(j[i]=1;j[i]<6;j[i]++)//小环上除3号圆环和4号圆环是否与小环颜色相同
			{
				temp=(4+j[i])%7;
				temp1=Loop[i][temp];
				if(temp1!=Loop[i][10])
				{
					flag=1;
					break;
				}
			}

			if(flag)
			{
				break;
			}
		}

		 for(i = 0; i < 5; i++)
        {//表示颜色不同
            if(j[i]<=5)
                break;
        }


		 if(i==5)//表示颜色相同
		 {
			  if(firstFlag==1)
            {

                firstFlag=0;
            }

            int flag=0;
			for(int i=0;i<5;i++)
			{

				temp1=Loop[i][3];
				temp2=Loop[i][4];

				if(temp1==temp2)
				{
					flag++;
					continue;
				}
				else if(temp1!=Loop[i][10] && temp2!=Loop[i][10])
				{

				}
				else if(temp1!=Loop[i][10] && temp2==Loop[i][10])
				{
					Loop_Anticlockwise(i);//逆时针旋转i环
		                Save[StepCount].Direction=ANTICLOCKWISE;
						Save[StepCount].loopNumber=i;
						StepCount++;

						int j=0;
						//由于上一步的转动，Loop[i][3]和已经转到Loop[i][2]，现做如下调整；
						temp1=Loop[i][3];
						temp3=Loop[i][2];
						while(j<5 && temp1!=temp3)
						{
							Loop_Clockwise(5);//不满足条件，顺时针转动大盘
							Save[StepCount].Direction=CLOCKWISE;
							Save[StepCount].loopNumber=5;
							StepCount++;

							temp1=Loop[i][3];//由于大盘转动，现在更新数据
							temp3=Loop[i][2];
							j++;
						}
						Loop_Clockwise(i);//顺时针转动i环
						Save[StepCount].Direction=CLOCKWISE;
						Save[StepCount].loopNumber=i;
						StepCount++;
				}
				else
				{
					    Loop_Clockwise(i);//顺时针转动i环
						Save[StepCount].Direction=CLOCKWISE;
						Save[StepCount].loopNumber=i;
						StepCount++;

						int j=0;
						//由于上一步的转动，Loop[i][4]和已经转到Loop[i][5]，现做如下调整；
						temp2=Loop[i][4];
						temp4=Loop[i][5];

						while(j<5 && temp2 != temp4)
						{
							 Loop_Clockwise(5);//顺时针转动大环
						     Save[StepCount].Direction=CLOCKWISE;
						     Save[StepCount].loopNumber=5;
						     StepCount++;

							 temp2=Loop[i][4];
							 temp4=Loop[i][5];
							 j++;
						}
						     Loop_Anticlockwise(i);//逆时针转动i环
						     Save[StepCount].Direction=ANTICLOCKWISE;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
				}
			}
			if(flag==5)//此时大环上已经实现了颜色的两两配对了
			{
				 int i,step,surplus; //step 大环需要转动的步数，surplus,恢复步数

				  int direction;  //根据surflag的值确定小环的转动方向;
				  
				  for(int j=0;j<5;j++)
				  {
					  i=hideTwoChesses(j);
					  step=j-i;

					

					  if(step<0)
					  {
						  surplus=5+step;
						  while(step<0)
						  {
							  //顺时针转动大环
							 Loop_Clockwise(5);
						     Save[StepCount].Direction=CLOCKWISE;
						     Save[StepCount].loopNumber=5;
						     StepCount++;
							  step++;
						  }

						  if(surflag==1)
						  {
							  int temp2,temp5;

							  temp2=Loop[i][2];
							  temp5=Loop[i][5];

							  if(temp2!=Loop[i][10])
							  {
								  direction=1;
							  }

							  if(temp5!=Loop[i][10])
							  {
								  direction=0;
							  }
							  surflag=0;
						  }
						  else
						  {
							  direction=1;
						  }

						  //旋转i环
						  if(direction==1)
						  {
						  	 Loop_Clockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }
						  else
						  {
							 Loop_Anticlockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }
						  //旋转i环
						  if(direction==1)
						  {
						  	 Loop_Clockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }
						  else
						  {
							 Loop_Anticlockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }
							  
						  for(int i=0;i<surplus;i++)
						  {
							  //顺时针旋转大环
							  Loop_Clockwise(5);
							  Save[StepCount].Direction=CLOCKWISE;
							  Save[StepCount].loopNumber=5;
							  StepCount++;
						  }
					  }
					  else if(step>0)
					  {
						  surplus=5-step;
						   while(step>0)
						   {
							   //不满足条件，逆时针旋转大盘
							    Loop_Anticlockwise(5);
							  Save[StepCount].Direction=ANTICLOCKWISE;
							  Save[StepCount].loopNumber=5;
							  StepCount++;

							  step--;
						   }

						   if(surflag==1)
						   {
							   int temp2,temp5;

							   temp2=Loop[i][2];
							   temp5=Loop[i][5];

                               if(temp2!=Loop[i][10])
							   {
								   direction=1;
							   }
							   if(temp5!=Loop[i][10])
							   {
								   direction=0;
							   }

							   surflag=0;
						   }
						   else
							   direction=1;
						     //旋转i环
						  if(direction==1)
						  {
						  	 Loop_Clockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }
						  else
						  {
							 Loop_Anticlockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }

						        //旋转i环
						  if(direction==1)
						  {
						  	 Loop_Clockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }
						  else
						  {
							 Loop_Anticlockwise(i);
						     Save[StepCount].Direction=direction;
						     Save[StepCount].loopNumber=i;
						     StepCount++;
						  }

						   for(int i=0;i<surplus;i++)
						   {
							   //逆时针转动大盘
							   Loop_Anticlockwise(5);
							   Save[StepCount].Direction=ANTICLOCKWISE;
							   Save[StepCount].loopNumber=5;
							   StepCount++;

						   }

					  }
					  else
					  {
                       int temp2,temp5;
					   temp2=Loop[i][2];
					   temp5=Loop[i][5];

					   if(temp2!=Loop[i][10])
					   {
						   //顺时针旋转环i
						   Loop_Clockwise(i);
						   Save[StepCount].Direction=CLOCKWISE;
						   Save[StepCount].loopNumber=i;
						   StepCount++;

						   //顺时针旋转环i
						   Loop_Clockwise(i);
						   Save[StepCount].Direction=CLOCKWISE;
						   Save[StepCount].loopNumber=i;
						   StepCount++;

						   j--;

						   continue;
					   }
					   else if(temp5!=Loop[i][10])
					   {
						   //逆时针旋转i环
						   Loop_Anticlockwise(i);
						   Save[StepCount].Direction=ANTICLOCKWISE;
						   Save[StepCount].loopNumber=i;
						   StepCount++;

						    //逆时针旋转i环
						   Loop_Anticlockwise(i);
						   Save[StepCount].Direction=ANTICLOCKWISE;
						   Save[StepCount].loopNumber=i;
						   StepCount++;

						   j--;
                           continue;
					   }
					   else
					   {
						   continue;
					   }

					  }
				  }
				  break;
			}

		 }



		 //不满足情况，顺时针转动大盘
		 Loop_Clockwise(5);
		 Save[StepCount].Direction=CLOCKWISE;
		 Save[StepCount].loopNumber=5;
		 StepCount++;
	}//此时除过大圆盘外，其他小环其他5个子都已经实现颜色归位

}

void Run()//程序的主要流程
{
	//初始化圆盘
	if(OnceFlag)
	{
	Init_Loop();
	Change_Loop_Color();//初始化圆盘颜色
	

	 OnceFlag=0;
	}
}