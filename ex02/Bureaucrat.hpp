#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include "colors.h"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat
{
  public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);

	const std::string &getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void executeForm(AForm const &form);

	class GradeToHighException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return "Grade too high";
		}
	};
	class GradeToLowException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return "Grade too low";
		}
	};

  private:
	Bureaucrat &operator=(const Bureaucrat &rhs);
	Bureaucrat(void);
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
