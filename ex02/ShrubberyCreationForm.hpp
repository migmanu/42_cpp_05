#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm
{
  public:
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm(void);

	const std::string getTarget(void) const;
	virtual void beSigned(const Bureaucrat &agent);

  private:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	virtual void signForm(const Bureaucrat &agent) const;
	const std::string _target;
};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &rhs);

#endif // !ShrubberyCreationForm_HPP
