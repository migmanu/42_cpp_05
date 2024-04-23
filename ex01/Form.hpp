#ifndef Form_HPP
#define Form_HPP
#include "Bureaucrat.hpp"
#include <string>

class Form
{
  public:
	Form(void);
	Form(const Form &src);
	Form(std::string name, int signGrade, int execGrade);
	~Form(void);

	const std::string &getName(void) const;
	bool getSigned(void) const;
	int getReqSignGrade(void) const;
	int getReqExecGrade(void) const;
	void beSigned(const Bureaucrat &agent);
	void signForm(const Bureaucrat &agent);

	class GradeTooHighException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return "Grade too high";
		}
	};
	class GradeTooLowException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return "Grade too low";
		}
	};

  private:
	Form &operator=(const Form &rhs);
	const std::string _name;
	const int _reqSignGrade;
	const int _reqExecGrade;
	bool _signed;
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif // !Form_HPP
