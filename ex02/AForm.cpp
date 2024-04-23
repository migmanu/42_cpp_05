#include "AForm.hpp"
#include "colors.h"

AForm::AForm(void) : _reqSignGrade(1), _reqExecGrade(1), _signed(false)
{
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
	return;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _reqSignGrade(signGrade), _reqExecGrade(execGrade), _signed(false)
{
	std::cout << GREEN << "AForm " << this->_name << " parameterized constructor called" << RESET << std::endl;
	if (_reqSignGrade < 1 || _reqExecGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (_reqSignGrade > 150 || _reqExecGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
	return;
}

AForm::AForm(const AForm &src)
	: _name(src.getName()), _reqSignGrade(src.getReqSignGrade()), _reqExecGrade(src.getReqExecGrade()),
	  _signed(src.getSigned())
{
	std::cout << GREEN << "AForm " << this->_name << " copy constructor called" << RESET << std::endl;
	return;
}

AForm::~AForm(void)
{
	std::cout << RED << "AForm " << this->_name << " default destructor called" << RESET << std::endl;
	return;
}

const std::string &AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

int AForm::getReqSignGrade(void) const
{
	return this->_reqSignGrade;
}

int AForm::getReqExecGrade(void) const
{
	return this->_reqExecGrade;
}

void AForm::execute(Bureaucrat const &agent)
{
	if (agent.getGrade() > this->_reqExecGrade)
	{
		std::cout << this->_name << " could not be executed: agent " << agent.getName()
				  << " has no execution privileges" << std::endl;
		return;
	}
	if (this->_signed == false)
	{
		std::cout << this->_name << " could not be executed: not signed" << std::endl;
		return;
	}
	this->signForm(agent);
	return;
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs)
{
	o << rhs.getName();
	o << ", form required sign grade ";
	o << rhs.getReqSignGrade();
	o << ", required execution grade ";
	o << rhs.getReqExecGrade();
	o << std::endl;
	return o;
}
