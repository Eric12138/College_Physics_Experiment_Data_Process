#include<iostream>
#include <stdio.h>
#include<math.h>

using namespace std;
//*****************************************
//����ƽ��ֵ 
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
//�����һ�಻ȷ���� 
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
	cout<<"�������Դ�����ַ��https://github.com/Eric12138/College_Physics_Experiment_data_process" <<endl;
	cout<<"����������ݵ�������";
	cin>>n;
	if(n>100||n<=0)							//����³���� 
	{
		cout<<"��Ѿ�ĵ�Ϸ���ǰɣ����ò����˺úó�ʵ�鱨����(�s�F����)�s��ߩ���"<<endl;
		system("pause");
		return 0;
	}
	else if(n==1)							//����³���� 
	{
		cout<<"��һ�������㻹�����㣬�������㡫(T��T)�ҷ�ѧ���ߣ�"<<endl;
		system("pause");
		return 0;
	}
	else
	{
		cout<<"��������������ݣ�"<<endl;
		int i=0;
		for(i=0;i<n;i++)
		{
			cin>>data[i];														//���鴢���������� 
		}
		cout<<"������B�಻ȷ����:";
		double error_2=0;
		cin>>error_2;															//���̻����������ĵڶ��಻ȷ���� 
		double avg=average(data,n);
		cout<<"ƽ��ֵ="<<avg<<endl;
		double error_1=calculate_eror_1(data,n);								//���ú��������һ�಻ȷ���� 
		cout<<"A��ȷ����:"<<error_1<<endl;
		cout<<"�ϳɲ�ȷ����:"<<sqrt(error_1*error_1+error_2*error_2)<<endl;		//������ 
		system("pause");
	}
}



