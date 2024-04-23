#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	Bureaucrat manu("manu", 1);
	RobotomyRequestForm formR("Marvin");
	ShrubberyCreationForm formS("42 Berlin");
	formR.beSigned(manu);
	formR.execute(manu);
	formS.beSigned(manu);
	formS.execute(manu);
	return 0;
}
