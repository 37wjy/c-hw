#include <iostream>

int main(int argc, char const *argv[])
{
	for(int i=0;i<10;i++){
		std::cout << i++ << std::endl;
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << ++i << std::endl;
		/* code */
	}
	
	return 0;
}