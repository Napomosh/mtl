#include "mvector.h"

#include <iostream>
#include <string>

int main() {
	ns::mvector<std::string> v(5);
	//v.push_back("a");
	v.push_back("b");
	v.push_back("d");
	ns::mvector<std::string> v1();

	auto p = v.end();
	p--;
	std::cout << v << std::endl;

	v.erase(p);
	std::cout << v << std::endl;
	p = v.end();
	p--;
	v.insert("c", p);
	std::cout << v << std::endl;

	return 0;
}
