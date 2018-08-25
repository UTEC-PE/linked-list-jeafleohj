/*
  main.cpp -- 	
*/

#include <iostream>
#include "list.h"

using namespace std;

int main(){
    List<int> test;
	for(int i = 0; i<10; ++i) {
		test.push_back(i);
	}
	test.print();
	test.print_reverse();
    List<int> test2;	
	for(int i = 10; i<20; ++i) {
		test2.push_front(i);
	}
	test2.print();
	test2.concat(test);
	test2.print();
	test.print();
	test2.clear();
	test2.print();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.print();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.print();
	test.print_reverse();	
	cout << test.get(2) << "\n";
	cout << test.get(4) << "\n";	
    return 0;
}
