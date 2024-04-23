#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
	return;
}

Intern::Intern(const Intern &src)
{
	std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
	*this = src;
	return;
}

Intern::~Intern(void)
{
	std::cout << RED << "Intern default destructor called" << RESET << std::endl;
	return;
}
