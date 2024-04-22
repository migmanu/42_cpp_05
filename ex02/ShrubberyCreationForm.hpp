#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  public:
	// Constructors and Destructors
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm(void);

	// Overloaded Operators
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	// Public Member Functions
	const std::string getTarget(void) const;
	virtual void beSigned(const Bureaucrat &agent);

  private:
	virtual void signForm(const Bureaucrat &agent);
	const std::string _target;
};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &rhs);

#endif // !ShrubberyCreationForm_HPP

