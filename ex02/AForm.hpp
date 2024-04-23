#ifndef AForm_HPP
#define AForm_HPP
#include "Bureaucrat.hpp"
#include <string>

class AForm
{
  public:
	AForm(void);
	AForm(const AForm &src);
	AForm(std::string name, int signGrade, int execGrade);
	virtual ~AForm(void);

	const std::string &getName(void) const;
	bool getSigned(void) const;
	int getReqSignGrade(void) const;
	int getReqExecGrade(void) const;
	void execute(Bureaucrat const &agent) const;

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
	class FormNotSignedException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return "Form not previously signed";
		}
	};

  protected:
	virtual void beSigned(const Bureaucrat &agent) = 0;
	virtual void signForm(const Bureaucrat &agent) const = 0;
	const std::string _name;
	const int _reqSignGrade;
	const int _reqExecGrade;
	bool _signed;

  private:
	AForm &operator=(const AForm &rhs);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif // !AForm_HPP
