#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
  public:
	// Constructors and Destructors
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm(void);

	// Overloaded Operators
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	// Public Member Functions
	const std::string getTarget(void) const;
	virtual void beSigned(const Bureaucrat &agent) = 0;
	virtual void signForm(const Bureaucrat &agent) = 0;
	//void execute(Bureaucrat const &executor);

  private:
	const std::string _target;
};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &rhs);

#endif // !RobotomyRequestForm_HPP
