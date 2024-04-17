#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("No target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << this->_name << " parameterized constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm " << this->_name << " copy constructor called" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm " << this->_name << " default destructor called" << std::endl;
	return;
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqSignGrade)
	{
		throw RobotomyRequestForm::GradeTooLowException();
	}
	if (this->_signed == true)
	{
		std::cout << "RobotomyRequestForm is already signed!" << std::endl;
		return;
	}
	std::cout << "RobotomyRequestForm signed by " << agent.getName() << std::endl;
	this->_signed = true;
	return;
}

void RobotomyRequestForm::signForm(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqExecGrade)
	{
		std::cout << "RobotomyRequestForm could not be executed: agent " << agent.getName()
				  << " has no execution privileges" << std::endl;
		return;
	}
	if (this->_signed == false)
	{
		std::cout << "RobotomyRequestForm could not be executed: not signed" << std::endl;
		return;
	}
	std::cout << "RobotomyRequestForm executed by " << agent.getName() << std::endl;
	return;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &rhs)
{
	o << rhs.getName();
	o << ", form required sign grade ";
	o << rhs.getReqSignGrade();
	o << ", required execution grade ";
	o << rhs.getReqExecGrade();
	o << std::endl;
	return o;
}
