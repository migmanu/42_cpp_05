#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

static int SignLevel = 25;
static int ExecLevel = 5;

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", SignLevel, ExecLevel), _target("No target")
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", SignLevel, ExecLevel), _target(target)
{
	std::cout << GREEN << "PresidentialPardonForm for " << this->_target << " parameterized constructor called" << RESET
			  << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("PresidentialPardonForm", SignLevel, ExecLevel), _target(src.getTarget())
{
	std::cout << GREEN << "PresidentialPardonForm for " << this->_target << " copy constructor called" << RESET
			  << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED << "PresidentialPardonForm for " << this->_target << " default destructor called" << RESET
			  << std::endl;
	return;
}

const std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqSignGrade)
	{
		std::cout << this->getName() << " target: " << this->getTarget() << " throws exception" << std::endl;
		throw PresidentialPardonForm::GradeTooLowException();
	}
	if (this->_signed == true)
	{
		std::cout << "PresidentialPardonForm is already signed!" << std::endl;
		return;
	}
	std::cout << "PresidentialPardonForm signed by " << agent.getName() << std::endl;
	this->_signed = true;
	return;
}

void PresidentialPardonForm::signForm(const Bureaucrat &agent) const
{
	if (agent.getGrade() > this->_reqExecGrade)
	{
		std::cout << "PresidentialPardonForm could not be executed: agent " << agent.getName()
				  << " has no execution privileges" << std::endl;
		return;
	}
	if (this->_signed == false)
	{
		std::cout << "PresidentialPardonForm could not be executed: not signed" << std::endl;
		return;
	}
	std::cout << this->getTarget() << " has been pardoned by " << agent.getName() << "!" << std::endl;
	return;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs)
{
	o << rhs.getName();
	o << ", form required sign grade ";
	o << rhs.getReqSignGrade();
	o << ", required execution grade ";
	o << rhs.getReqExecGrade();
	o << std::endl;
	return o;
}
