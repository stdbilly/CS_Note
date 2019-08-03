 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-29 11:27:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 1;
	printf("sizeof(a) = %d\n", sizeof a);
	printf("sizeof(a) = %d\n", sizeof(a));

	return 0;
}
