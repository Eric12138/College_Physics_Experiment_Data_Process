#include<iostream>
#include <stdio.h>
#include<math.h>

using namespace std;
//*****************************************
//计算平均值 
//***************************************** 
double average(double data[],int n)
{
	int i=0;
	double sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+data[i];
	}
	return sum/n;
}

//*****************************************
//计算第一类不确定度 
//***************************************** 
double calculate_eror_1(double data[],int n)
{
	int i=0;
	double avg=average(data,n);
	double error_square_sum=0;
	for(i=0;i<n;i++)
	{
		error_square_sum=error_square_sum+(data[i]-avg)*(data[i]-avg);
	}
	double eror_1=0;
	eror_1=sqrt(error_square_sum/(n*(n-1)));
	return eror_1;
}


int main()
{
	int n;
	double data[100];
	cout<<"本软件开源代码地址：https://github.com/Eric12138/College_Physics_Experiment_data_process" <<endl;
	cout<<"输入你的数据的数量：";
	cin>>n;
	if(n>100||n<=0)							//增加鲁棒性 
	{
		cout<<"你丫的调戏我是吧，还让不让人好好抄实验报告了(╯‵□′)╯︵┻━┻"<<endl;
		system("pause");
		return 0;
	}
	else if(n==1)							//增加鲁棒性 
	{
		cout<<"就一个数据你还不手算，懒死了你～(TロT)σ放学别走！"<<endl;
		system("pause");
		return 0;
	}
	else
	{
		cout<<"依次输入你的数据："<<endl;
		int i=0;
		for(i=0;i<n;i++)
		{
			cin>>data[i];														//数组储存输入数据 
		}
		cout<<"请输入B类不确定度:";
		double error_2=0;
		cin>>error_2;															//键盘获得仪器本身的第二类不确定度 
		double avg=average(data,n);
		cout<<"平均值="<<avg<<endl;
		double error_1=calculate_eror_1(data,n);								//调用函数计算第一类不确定度 
		cout<<"A不确定度:"<<error_1<<endl;
		cout<<"合成不确定度:"<<sqrt(error_1*error_1+error_2*error_2)<<endl;		//输出结果 
		system("pause");
	}
}



