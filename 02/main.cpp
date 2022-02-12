#include <iostream>
#include "include/V.h"

//#define COMPILATION_ERROR

int main() {
	V v1(3);		
	const V v2(4);	

	v1.at(0) = 2;
	v1.at(1) = 3;
	const V v3 = v1;
	v1.at(1) = 0;
	v3.at(2) = 2;

	v1.print("v1: ");
	v2.print("v2: ");
	v3.print("v3: ");

	double prod = V::dot(v1, v3); 
	std::cout << "Dot product = " << prod << std::endl;
	std::cout << "Another dot product: " << std::endl;
	V::dot(v1,v2);

	double norm = static_cast<double>(v3); // == v3.norm();
	std::cout << "Norm = " << norm << ", " << v3.norm() << std::endl;
	
	V v4 = V::sum(v1, v3); 
	v4.print("v1 + v3: ");

	V v5 = std::move(V::sum(v1, v3));
	v5.print("v1 + v3: ");

	V::sum(v1, 3).print("v1 + 3 : ");
	
	#ifdef COMPILATION_ERROR
	V strange = 5;
	#endif
}
/*
//Output:
v1: (2, 0, 0)
v2: (0, 0, 0, 0)
v3: (2, 3, 2)
Dot product = 4
Another dot product: 
Error, vectors of different dimensions!
Norm = 4.12311, 4.12311
v1 + v3: (4, 3, 2)
v1 + v3: (4, 3, 2)
v1 + 3 : (5, 3, 3)
*/