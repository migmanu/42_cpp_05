#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	try
	{
		Bureaucrat manu("manu", 14);
		for (int i = 10; i > 0; i--)
		{
			std::cout << manu;
			manu.incrementGrade();
		}
		Bureaucrat src("unam", 141);
		Bureaucrat unam(src);
		for (int i = 10; i > 0; i--)
		{
			std::cout << unam;
			unam.decrementGrade();
		}
		// Bureaucrat tooHigh("crazy", 0);
		// Bureaucrat tooLow("crazy", 151);
	}
	catch (std::exception &exception)
	{
		std::cerr << "* Exception caught: " << exception.what() << " *" << std::endl;
	}
	return 0;
}
