#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ostream>

static std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

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

Intern &Intern::operator=(const Intern &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Intern Assignment Operator called" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << RED << "Intern default destructor called" << RESET << std::endl;
	return;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *newForm;
	int i;

	for (i = 0; i < 3; i++)
	{
		if (name.compare(names[i]) == 0)
		{
			std::cout << name << " matches " << names[i].c_str() << std::endl;
			break;
		}
	}
	switch (i)
	{
		case 0:
		{
			std::cout << "Intern creates " << names[i] << " form." << std::endl;
			newForm = new ShrubberyCreationForm(target);
			break;
		}
		case 1:
		{
			std::cout << "Intern creates " << names[i] << " form." << std::endl;
			newForm = new RobotomyRequestForm(target);
			break;
		}
		case 2:
		{
			std::cout << "Intern creates " << names[i] << " form." << std::endl;
			newForm = new PresidentialPardonForm(target);
			break;
		}
		default:
		{
			std::cout << "Form does not exist!" << std::endl;
			return NULL;
		}
	}
	return newForm;
}
