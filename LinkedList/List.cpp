#include<iostream>
#include"list.h"
using namespace std;

int main()
{
	SingleList<double> list;
	list.CreatList(5);
	list.Add(123.234);
	list.Display();
	list.InsertNode(3, 34.34);
	list.Display();
	list.Delete(2);
	list.Display();
	list.Delete();
	list.Display();
	system("pause");
	return 0;
}