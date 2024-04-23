#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << GREEN << "Bureaucrat " << this->_name << " parameterized constructor called" << RESET << std::endl;
	if (grade < 1)
	{
		throw Bureaucrat::GradeToHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeToLowException();
	}
	_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << GREEN << "Bureaucrat " << this->_name << " copy constructor called" << RESET << std::endl;
	return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Bureaucrat Assignment Operator called" << std::endl;
	this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "Bureaucrat " << this->_name << " default destructor called" << RESET << std::endl;
	return;
}

const std::string &Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
	{
		throw Bureaucrat::GradeToHighException();
	}
	this->_grade--;
	std::cout << "Incremented " << this->_name << "'s grade to: " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
	{
		throw Bureaucrat::GradeToLowException();
	}
	this->_grade++;
	std::cout << "Decremented " << this->_name << "'s grade to: " << this->_grade << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &exception)
	{
		std::cerr << this->getName() << " tried to execute " << form.getName() << " but failed! :(" << std::endl;
		return;
	}
	std::cerr << this->getName() << " executed " << form.getName() << " succesfully! :)" << std::endl;
	return;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName();
	o << ", bureaucrat grade ";
	o << rhs.getGrade();
	o << std::endl;
	return o;
}
