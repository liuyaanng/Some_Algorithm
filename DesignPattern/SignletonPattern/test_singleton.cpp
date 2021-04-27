#include <iostream>
#include "Singleton.h"
using namespace std;

int main()
{
	s1::Singleton * s1 = s1::Singleton::getInstance();
	s1::Singleton * s2 = s1::Singleton::getInstance();

	if(s1 == s2) cout << "s1 == s2" << endl;
	else cout << "s1 != s2" << endl;



	return 0;
}


