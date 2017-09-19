#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//结点定义
template<typename type> class Node
{
public:
	type data;
	Node<type> *pNext;
};
//链表定义
template<typename type> class SingleList
{
public:
	SingleList();
	~SingleList();
	void CreatList(int size);
	void InsertNode(int position, type data);
	void Add(type data);
	void Delete(int position);
	void Delete();
	void Display();
private:
	Node<type> *head;//头结点
	int listSize;
};

template<typename type>
SingleList<type>::SingleList()
{
	head = new Node<type>;
	head->data = 0;
	head->pNext = NULL;
}

template<typename type>
SingleList<type>::~SingleList()
{
	cout << "Call the destructor function" << endl;
	
	delete head;
}

template<typename type> void SingleList<type>::CreatList(int size)
{
	listSize = size;

	if (size < 1)
	{
		cout << "Illegal size !" << endl;
		return;
	}

	Node<type> *pNew, *pTemp;
	pTemp = head;
	int i = size;
	while (size-- > 0)
	{
		pNew = new Node<type>;
		cout << "Please input the " << i - size << "th data: ";
		cin >> pNew->data;
		pNew->pNext = NULL;
		pTemp->pNext = pNew;
		pTemp = pNew;
	}	
}

template<typename type>
inline void SingleList<type>::InsertNode(int position, type data)
{
	if (position < 0 || position > listSize + 1)
	{
		cout << "Position is error or beyond size!" << endl;
		return;
	}
	Node<type> *pNew, *pTemp;
	pTemp = head;

	pNew = new Node<type>;
	pNew->data = data;
	pNew->pNext = NULL;

	while (position-- > 1)
		pTemp = pTemp->pNext;

	pNew->pNext = pTemp->pNext;
	pTemp->pNext = pNew;

	listSize++;
}
//在结点的最后添加一个数据
template<typename type>
inline void SingleList<type>::Add(type data)
{
	int length = listSize;

	Node<type> *pNew, *pTemp;
	pTemp = head;

	pNew = new Node<type>;
	pNew->data = data;
	pNew->pNext = NULL;

	do
	{
		pTemp = pTemp->pNext;
	} while (length-- >1);

	pNew->pNext = pTemp->pNext;
	pTemp->pNext = pNew;

	listSize++;
}

template<typename type>
inline void SingleList<type>::Delete(int position)
{
	if (position < 1 || position > listSize)
	{
		cout << "Position is error or beyond size!" << endl;
		return;
	}

	Node<type> *pTemp = head, *pDelete;

	while (position-- > 1)
		pTemp = pTemp->pNext;

	pDelete = pTemp->pNext;
	pTemp->pNext = pDelete->pNext;
	delete pDelete;

	pDelete = NULL;

	listSize--;
}

template<typename type>
inline void SingleList<type>::Delete()
{
	string isDelete;
	cout << "WARNING !!\n" << "Are you sure delete the whole list ??" << endl;
	cout << "If you want go on, please input \"YES\" !" << endl;

	cin >> isDelete;
	if (isDelete == "YES")
	{
		Node<type> *pDelete = head->pNext, *pTemp;
		while (pDelete != NULL)
		{
			pTemp = pDelete->pNext;
			head->pNext = pTemp;
			delete pDelete;
			pDelete = pTemp;

			listSize--;
		}
	}
	else
	{
		cout << "Function has exited" << endl;
		return;
	}
}

template<typename type>
inline void SingleList<type>::Display()
{
	if (listSize == 0)
	{
		cout << "List is not exist !" << endl;
		return;
	}

	Node<type> *p = head->pNext;
	while (p != NULL)
	{
		cout << p->data << "   ";
		p = p->pNext;
	}
	cout << endl << "All data has been displayed !" << endl;
}
