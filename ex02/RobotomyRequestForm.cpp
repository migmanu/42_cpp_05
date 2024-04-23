#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

static int SignLevel = 72;
static int ExecLevel = 45;

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", SignLevel, ExecLevel), _target("No target")
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", SignLevel, ExecLevel), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm for " << this->_target << " parameterized constructor called" << RESET
			  << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("RobotomyRequestForm", SignLevel, ExecLevel), _target(src.getTarget())
{
	std::cout << GREEN << "RobotomyRequestForm for " << this->_target << " copy constructor called" << RESET
			  << std::endl;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "RobotomyRequestForm Assignment Operator called." << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << "RobotomyRequestForm for " << this->_target << " default destructor called" << RESET
			  << std::endl;
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
		std::cout << this->getName() << " target: " << this->getTarget() << " throws exception" << std::endl;
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

void RobotomyRequestForm::signForm(const Bureaucrat &agent) const
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
	std::srand(std::time(0));
	int flag = std::rand();
	if (flag % 2 == 0)
	{
		std::cout << this->_target << " robotomized by " << agent.getName() << std::endl;
		return;
	}
	std::cout << "Romotomization failed!" << std::endl;
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
