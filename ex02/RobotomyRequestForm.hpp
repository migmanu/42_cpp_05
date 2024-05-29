#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"
#include <cstdlib>
#include <string>

class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm(void);

	const std::string getTarget(void) const;
	virtual void beSigned(const Bureaucrat &agent);

  private:
	RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	virtual void signForm(const Bureaucrat &agent) const;
	const std::string _target;
};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &rhs);

#endif // !RobotomyRequestForm_HPP
