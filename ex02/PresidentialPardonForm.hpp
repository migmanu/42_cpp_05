#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"
#include <cstdlib>
#include <string>

class PresidentialPardonForm : public AForm
{
  public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm(void);

	const std::string getTarget(void) const;
	virtual void beSigned(const Bureaucrat &agent);

  private:
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	virtual void signForm(const Bureaucrat &agent) const;
	const std::string _target;
};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs);

#endif // !PresidentialPardonForm_HPP
