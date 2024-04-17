#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main(void)
{
	Bureaucrat manu("manu", 1);
	RobotomyRequestForm formR(manu.getName());
	formR.beSigned(manu);
	formR.execute(manu);
	return 0;
}
