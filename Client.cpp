#include<iostream>
using namespace std;

#include "btree.h"
#include <typeinfo>


template <typename T>
void disp(T begin, T end)
{
	while(begin != end)
		cout << *begin++ <<" ";
	cout << endl;
}


template<typename T>
class myPred
{
public:
	bool operator()(const T& a, const T& b) const
	{
		return a > b;
	}
};

int main()
{
	int a[30];
	for(int i=0;i<30;++i)
		a[i] = i+10;

	Tree <int> t(a,a+30);

	cout << "Tree after bulk loading : \n";

	t.disp_like_tree();

	Tree <char, 4, myPred<char> >c;

	

	for(int i=0;i<10;++i)
	{
		t.push(i);
		c.push(65+i);
	}

	cout<<endl;


	cout<<"Tree of int with default order (6) [display using iterators] : \n";
	disp(t.begin(),t.end());

	cout<<"Tree of int with default order (6) : \n";
	t.disp_like_tree();

	cout<<"Tree of char with order 10 : \n";
	c.disp_like_tree();
	cout << "Searching 34 in integer tree \n";

	auto ft = t.find(34);

	if (ft == t.end())
		cout << "34 not found\n";
	else cout << "Found!\n";
}
