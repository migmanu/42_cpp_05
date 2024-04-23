#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
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
		Bureaucrat manu("manu", 5);
		RobotomyRequestForm formR("Marvin");
		ShrubberyCreationForm formS("42 Berlin");
		PresidentialPardonForm formP("Zaphod Beeblebrox");
		formP.beSigned(manu);
		manu.executeForm(formP);
		formS.beSigned(manu);
		manu.executeForm(formS);
		formR.beSigned(manu);
		manu.executeForm(formR);
	}
	catch (std::exception &exception)
	{
		std::cerr << std::endl << BGRAY << "* Exception caught: " << exception.what() << " *" << std::endl << RESET;
	}
	return 0;
}
