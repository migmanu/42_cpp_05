#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "colors.h"
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	try
	{
		Bureaucrat manu("manu", 5);
		Intern intern;
		AForm *formP = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
		AForm *formS = intern.makeForm("shrubbery creation", "42 School");
		AForm *formR = intern.makeForm("robotomy request", "Marvin");
		// AForm *formW = intern.makeForm("wrong request", "Marvin");
		// delete formW;

		formP->beSigned(manu);
		manu.executeForm(*formP);
		formS->beSigned(manu);
		manu.executeForm(*formS);
		formR->beSigned(manu);
		manu.executeForm(*formR);

		delete formP;
		delete formS;
		delete formR;
	}
	catch (std::exception &exception)
	{
		std::cerr << std::endl << BGRAY << "* Exception caught: " << exception.what() << " *" << std::endl << RESET;
	}
	return 0;
}
