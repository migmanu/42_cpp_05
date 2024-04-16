#include "Form.hpp"

Form::Form(void) : _reqSignGrade(1), _reqExecGrade(1), _signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
	return;
}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _reqSignGrade(signGrade), _reqExecGrade(execGrade), _signed(false)
{
	std::cout << "Form " << this->_name << " parameterized constructor called" << std::endl;
	if (_reqSignGrade < 1 || _reqExecGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (_reqSignGrade > 150 || _reqExecGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
	return;
}

Form::Form(const Form &src)
	: _name(src.getName()), _reqSignGrade(src.getReqSignGrade()), _reqExecGrade(src.getReqExecGrade()),
	  _signed(src.getSigned())
{
	std::cout << "Form " << this->_name << " copy constructor called" << std::endl;
	return;
}

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " default destructor called" << std::endl;
	return;
}

const std::string &Form::getName(void) const
{
	return this->_name;
}

bool Form::getSigned(void) const
{
	return this->_signed;
}

int Form::getReqSignGrade(void) const
{
	return this->_reqSignGrade;
}

int Form::getReqExecGrade(void) const
{
	return this->_reqExecGrade;
}

void Form::beSigned(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqSignGrade)
	{
		throw Form::GradeTooLowException();
	}
	if (this->_signed == true)
	{
		std::cout << "Form is already signed!" << std::endl;
		return;
	}
	std::cout << "Form signed by " << agent.getName() << std::endl;
	this->_signed = true;
	return;
}

void Form::signForm(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqExecGrade)
	{
		std::cout << "Form could not be executed: agent " << agent.getName() << " has no execution privileges"
				  << std::endl;
		return;
	}
	if (this->_signed == false)
	{
		std::cout << "Form could not be executed: not signed" << std::endl;
		return;
	}
	std::cout << "Form executed by " << agent.getName() << std::endl;
	return;
}

std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
	o << rhs.getName();
	o << ", form required sign grade ";
	o << rhs.getReqSignGrade();
	o << ", required execution grade ";
	o << rhs.getReqExecGrade();
	o << std::endl;
	return o;
}
