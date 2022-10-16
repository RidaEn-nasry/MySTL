


// recursion , what is recursion ??? 
// why do we recursion and how deos this kind of problem solving technique helps us, well first is it a problem solving techniquq, 
//
//

#include <iostream>

int factorial(int n) {
	if (n == 0) 
		return 1;
	return n * factorial(n - 1);
}


// int factorial( long n) {
// 	long res = 0;
// 	while (n != 1) 
// 	{
// 		res += (n * (n - 1));
// 		n--;
// 	}
// 	return (res);
// }

int main ( ) {
	std::cout << factorial(6) << std::endl;
	std::cout << factorial((long)6) << std::endl;
}
