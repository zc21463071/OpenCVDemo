#include <iostream>
#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>  
#include <fstream>
#include<list>



#define MAX(a,b) a>b?a:b

using namespace std;
using namespace cv;
//using namespace HalconCpp;

bool a(int,int &);
bool b(int a, int &b); 

bool lessthen(int v1, int v2); 
vector<int> filter(const vector<int>&vec, int filter_value, bool(*pmethon)(int  v1, int v2));
int main()
{
	//int number = cvcamGetCamerasCount();
	namedWindow("EX1",WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open(1);
	if (cap.isOpened())
	{
		Size size(cap.get(CAP_PROP_FRAME_WIDTH),cap.get(CAP_PROP_FRAME_HEIGHT));
	}
	Mat ca;
	
	while (cap.isOpened())
	{
		cap >> ca;
		imshow("EX1",ca);
		waitKey(10);
	}

	MAX(1, 2);
	list<int>  ccc;
	//ccc.end(); 
	vector<int> sd;
	int a1=1, b1=0;
	a(a1,b1);
	b(a1,b1);
	cout << b1 << endl;
	int ia[9] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> iaa(ia,ia+9);
	int iva = 1024;
	int &iva2 = iva;
	int cc = iva2;
	cout << iva2 << endl;
	cout << &iva << endl;
	cout << &iva2 << endl;

	cout << iva << endl;
	
	ofstream out("1.txt",ios_base::app);
	ifstream in("1.txt",ios_base::in);
	if (!out)
	{
		cout << "false" << endl;

	}
	else
	{
		out << "123" << " "
			<< "456" << " "
			<<endl;
		string name,name1,name2;
		in >> name;
		in >> name1;
		in >> name2;
		in >> name >> name1 >> name2;
	}
	Mat img = imread("C:\\Users\\Administrator\\Desktop\\782383359571036204.jpg");
	namedWindow("窗口1", WINDOW_AUTOSIZE);
	imshow("窗口1",img);


	waitKey(0);
	return 0;
}

bool a(int, int &)
{
	return true;
}
bool b(int a, int &b)
{
	static	int v[] = {1,2,3,4,5};
	
	b = 1;
	return true;
}


template <typename T>//模板范型
int C(T t)
{
	return	 1;
}


bool lessthen(int v1,int v2)
{
	return true;
}
vector<int> filter(const vector<int>&vec,int filter_value,bool (*pmethon)(int  v1,int v2))
{
	vector<int> fl;
	return  fl;
}