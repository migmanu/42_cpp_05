#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	int grade = 4;
	Bureaucrat manu("manu", grade);
	Form f1("Anmeldung", 3, 3);
	for (int i = 0; i < grade - 1; i++)
	{
		try
		{
			if (f1.getSigned() == false)
			{
				f1.beSigned(manu);
			}
		}
		catch (std::exception &exception)
		{
			std::cerr << "* Exception caught: " << exception.what() << " *" << std::endl;
		}
		try
		{
			manu.incrementGrade();
		}
		catch (std::exception &exception)
		{
			std::cerr << "* Exception caught: " << exception.what() << " *" << std::endl;
		}
		f1.signForm(manu);
	}
	return 0;
}
