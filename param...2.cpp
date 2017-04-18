// param...2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <type_traits>
#include <exception>

template< typename T>
auto addKilogramm(const T& t, const std::string& weight)
{
	if (std::is_integral<T>::value && weight == "g")
		return t + 1000;
	else if (std::is_floating_point<T>::value && weight == "kg")
		return t + 1;
	else
	{
		throw std::invalid_argument("Invalid Argument");
	}
}

int main()
{
	try
	{
		std::cout << addKilogramm(100, "g") << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << addKilogramm("100", "g") << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}

