#include "AForm.hpp"

AForm::AForm(void) : _reqSignGrade(1), _reqExecGrade(1), _signed(false)
{
	std::cout << "AForm default constructor called" << std::endl;
	return;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _reqSignGrade(signGrade), _reqExecGrade(execGrade), _signed(false)
{
	std::cout << "AForm " << this->_name << " parameterized constructor called" << std::endl;
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
	std::cout << "AForm " << this->_name << " copy constructor called" << std::endl;
	return;
}

AForm::~AForm(void)
{
	std::cout << "AForm " << this->_name << " default destructor called" << std::endl;
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

void AForm::beSigned(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqSignGrade)
	{
		throw AForm::GradeTooLowException();
	}
	if (this->_signed == true)
	{
		std::cout << "AForm is already signed!" << std::endl;
		return;
	}
	std::cout << "AForm signed by " << agent.getName() << std::endl;
	this->_signed = true;
	return;
}

void AForm::signForm(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqExecGrade)
	{
		std::cout << "AForm could not be executed: agent " << agent.getName() << " has no execution privileges"
				  << std::endl;
		return;
	}
	if (this->_signed == false)
	{
		std::cout << "AForm could not be executed: not signed" << std::endl;
		return;
	}
	std::cout << "AForm executed by " << agent.getName() << std::endl;
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
