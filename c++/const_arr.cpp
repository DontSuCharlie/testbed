#include <iostream>

int main()
{
	// case 1: using an immutable variable works
	// constexpr auto size = 5;
	// int arr[size];
	// arr[0] = 29;
	// std::cout << arr[0] << std::endl;

	// case 2: using a mutable variable works too
	// auto size = 5;
	// int arr[size];
	// arr[0] = 29;
	// std::cout << arr[0] << std::endl;	

	auto size = 5;
	int arr[size];
	arr[0] = 29;
	std::cout << arr[0] << std::endl;

}