#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <string>

class PresidentialPardonForm : public AForm
{
  public:
	// Constructors and Destructors
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm(void);

	// Overloaded Operators
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	// Public Member Functions
	const std::string getTarget(void) const;
	virtual void beSigned(const Bureaucrat &agent);
	virtual void signForm(const Bureaucrat &agent);
	//void execute(Bureaucrat const &executor);

  private:
	const std::string _target;
};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs);

#endif // !PresidentialPardonForm_HPP

