
#include<vector>
#include<cstdlib>
# include<iostream>
# include<stdio.h>
#include <string>    
#include<algorithm>
#include<fstream>
using namespace std;

void IN(void);//����
void initialization();//��ʼ��
void go(int a, int b, vector<int> bulin,int lj, string prin);//�ݻ�
void last(void);//�����ж������


string prin="";


vector<vector<int>  > ptp;//�㵽��֮�����̾����
vector<vector<int>  > save;//�洢��Ԫ�����߹�������
vector<vector<string>  > sptp;//�㵽��֮�����̾���string��
int cs;//������
int zdlj = 0;//��������·��
int out = 0;//�����·��
int hang;//��Ԫ���������м���
int ND;//����ֱ��
int NDx,NDy;//����ֱ��
string PD;//��̵�����ֱ����·��
string OPD;//��PD


int start;



void main(void) {
	IN();
	initialization();

	for (int i1 = 0; i1 < hang; i1++) {
		for (int i2 = i1 + 1; i2 < hang; i2++) {
			 zdlj=0;//��������·��
			 out=0;//�����·��
			vector<int> bulin;//�洢��Ԫ���Ƿ��߹�	 
			for (int i3 = 0; i3 < hang; i3++) { bulin.push_back(1); } //���ֱ����
			//cout <<"i1>i2: "<< i1 <<">"<< i2<<endl;
			start = i1;
			prin = to_string(i1);
			go(i1, i2, bulin,out,prin);
			
			//cout << endl; system("PAUSE");

		}

		
	}
	
		last();
		system("PAUSE");

}



void go(int a,int b,vector<int> bulin, int lj,string prin)//���루��㣬�յ�,���֣�
{	
	if (a == b)//����
	{
		if (lj < ptp[start][b] || ptp[start][b] == -1)//���
		{
			ptp[start][b] = lj; ptp[b][start] = lj;
			sptp[start][b] = prin; sptp[b][start] = prin;
			prin = "";
		}
	
	
	
		return ;}
		
	
	else {
		for (int i1 = 0; i1 < hang; i1++)//��Ѱa���ӵ�����ȥ
		{
			if ((save[a][i1] == 1) && (bulin[i1] == 1)) //a���ӵ�i1ʱ����i1û���߹���
			{
				bulin[i1] = 0;//�߹���,���ֱ����
				
				go(i1, b, bulin,lj+1, (prin + " " + to_string(i1)) );//��i1��ʼ������b��
				bulin[i1] = 1;
				
				
				
			}
		}
		
	}
	



		
	
	return ;
	}











void IN(void) {

	ifstream fin("save.txt");
	fin >> hang;
	for (int i0 = 0; i0 < hang; i0++) {
		vector <int> yihang;
		int mx;
		int my;
		for (int i1 = 0; i1 < hang; i1++) {
			int ppp;
			fin >> ppp;
			yihang.push_back(ppp);
		}
		save.push_back(yihang);
	}
	fin.close();
	
}


void initialization() {

	
	
	//ptp��100
	vector<int>zero;
	for (int i2 = 0; i2 < hang; i2++) { zero.push_back(-1); }
	for (int i3 = 0; i3 < hang; i3++) { ptp.push_back(zero); }
	vector<string>OO;
	string o= "";
	for (int i2 = 0; i2 < hang; i2++) { OO.push_back(o); }
	for (int i3 = 0; i3 < hang; i3++) { sptp.push_back(OO); }

}

void last() {

	cout << "!!PTP!!" << endl;
	for (int i0 = 0; i0 < hang; i0++) {
		for (int i1 = 0; i1 < hang; i1++) {
			cout << ptp[i0][i1] << " ";
			if (ptp[i0][i1] > ND) { ND = ptp[i0][i1]; NDx = i0; NDy = i1; }

		}
		cout << endl;
	}

	cout << "!!SPTP!!" << endl;
	for (int i0 = 0; i0 < hang; i0++) {
		for (int i1 = 0; i1 < hang; i1++) {
			cout << "[" << i0 << "]" << ">" << "[" << i1 << "]: ";
			cout << sptp[i0][i1] << endl;

		}
		cout << endl;
	}
	cout << "network diameter is " << ND << endl;
	cout << "Path of the diameter is " << sptp[NDx][NDy] << endl;
}
