#pragma once
#include<iostream>
using namespace std;

template<class T>
struct greater : public binary_function<T,T,bool>
{
	bool operator()(const T&x, const T&y)
		const {
		return x >= y;
	}
};