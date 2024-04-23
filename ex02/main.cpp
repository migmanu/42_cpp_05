#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.h"
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	try
	{
		std::cout << BGREEN << "* CONSTRUCTORS *" << RESET << std::endl;
		Bureaucrat manu("manu", 145);
		RobotomyRequestForm formR("Marvin");
		ShrubberyCreationForm formS("42 Berlin");
		std::cout << std::endl << "* PROGRAM *" << std::endl;
		formS.beSigned(manu);
		// formS.execute(manu);
		formR.beSigned(manu);
		formR.execute(manu);
	}
	catch (std::exception &exception)
	{
		std::cerr << std::endl << "* Exception caught: " << exception.what() << " *" << std::endl;
	}
	return 0;
}
