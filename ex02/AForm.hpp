#ifndef AForm_HPP
#define AForm_HPP
#include "Bureaucrat.hpp"
#include <string>

class AForm
{
  public:
	// Constructors and Destructors
	AForm(void);
	AForm(const AForm &src);
	AForm(std::string name, int signGrade, int execGrade);
	virtual ~AForm(void);

	// Overloaded Operators
	AForm &operator=(const AForm &rhs);

	// Public Member Functions
	const std::string &getName(void) const;
	bool getSigned(void) const;
	int getReqSignGrade(void) const;
	int getReqExecGrade(void) const;
	virtual void beSigned(const Bureaucrat &agent) = 0;
	virtual void signForm(const Bureaucrat &agent) = 0;
	void execute(Bureaucrat const &executor);

	// Exception classes
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

  protected:
	const std::string _name;
	const int _reqSignGrade;
	const int _reqExecGrade;
	bool _signed;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif // !AForm_HPP
