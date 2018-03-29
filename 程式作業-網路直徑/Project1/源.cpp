
#include<vector>
#include<cstdlib>
# include<iostream>
# include<stdio.h>
#include <string>    
#include<algorithm>
#include<fstream>
using namespace std;

void IN(void);//输入
void initialization();//初始化
void go(int a, int b, vector<int> bulin,int lj, string prin);//递回
void last(void);//最后的判断与输出


string prin="";


vector<vector<int>  > ptp;//点到点之间的最短距离表
vector<vector<int>  > save;//存储二元树连线规则阵列
vector<vector<string>  > sptp;//点到点之间的最短距离string表
int cs;//测试用
int zdlj = 0;//两点间最短路径
int out = 0;//两点间路径
int hang;//二元树的数字有几个
int ND;//网络直径
int NDx,NDy;//网络直径
string PD;//最短的网络直径的路径
string OPD;//旧PD


int start;



void main(void) {
	IN();
	initialization();

	for (int i1 = 0; i1 < hang; i1++) {
		for (int i2 = i1 + 1; i2 < hang; i2++) {
			 zdlj=0;//两点间最短路径
			 out=0;//两点间路径
			vector<int> bulin;//存储二元树是否走过	 
			for (int i3 = 0; i3 < hang; i3++) { bulin.push_back(1); } //布林表归零
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



void go(int a,int b,vector<int> bulin, int lj,string prin)//输入（起点，终点,布林）
{	
	if (a == b)//到达
	{
		if (lj < ptp[start][b] || ptp[start][b] == -1)//最短
		{
			ptp[start][b] = lj; ptp[b][start] = lj;
			sptp[start][b] = prin; sptp[b][start] = prin;
			prin = "";
		}
	
	
	
		return ;}
		
	
	else {
		for (int i1 = 0; i1 < hang; i1++)//搜寻a连接到哪里去
		{
			if ((save[a][i1] == 1) && (bulin[i1] == 1)) //a连接到i1时（且i1没被走过）
			{
				bulin[i1] = 0;//走过了,布林标记下
				
				go(i1, b, bulin,lj+1, (prin + " " + to_string(i1)) );//从i1开始继续往b走
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

	
	
	//ptp归100
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
