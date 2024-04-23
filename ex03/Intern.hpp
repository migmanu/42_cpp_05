#ifndef Intern_HPP
#define Intern_HPP
#include "AForm.hpp"
#include <string>
class Intern
{
  public:
	Intern(void);
	Intern(const Intern &src);
	~Intern(void);

	AForm *makeForm(std::string name, std::string target);

  private:
	Intern &operator=(const Intern &rhs);
};

#endif // !Intern_HPP
