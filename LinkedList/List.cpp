#include<iostream>
#include<functional>
#include<algorithm>
#include<numeric>
#include<vector>
#include"list.h"
using namespace std;

int compare(const void * a, const void * b)
{
	return(*(int*)a - *(int*)b);
}

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
	/*list.Delete();
	list.Display();*/
	list.Sort(true, list.GetTheHeadNode(), list.GetTheEndNode());
	list.Display();
	list.Sort(false, list.GetTheHeadNode(), list.GetTheEndNode());
	list.Display();

	string strIN = "123";
	while (strIN != "exit")
	{
		cout << "Input \"exit\" to exit !\n";
		cin >> strIN;
	}

	system("pause");
	return 0;
}