/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:52:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 13:19:24 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    //std::cout << "Intern default constructor called!" << std::endl;
    return ;
}

Intern::~Intern()
{
    //std::cout << "Intern destructor called!" << std::endl;
    return ;
}

Intern::Intern(Intern const &intern)
{
    //std::cout << "Intern copy constructor called!" << std::endl;
    (void) intern;
    return ;
}

Intern &Intern::operator=(Intern const &other)
{
    (void) other;
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target) const
{
    PresidentialPardonForm presi = PresidentialPardonForm(target);
    RobotomyRequestForm robot = RobotomyRequestForm(target);
    ShrubberyCreationForm shrub = ShrubberyCreationForm(target);
    
    AForm *forms[] = {&presi, &robot, &shrub};

    for (int i = 0; i < 3; ++i)
    {
        if (formName.compare(forms[i]->getName()) == 0)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i]->clone());
        }
    }
    std::cout << "Form not created : Insert valid type" << std::endl;
    return (NULL);
    
}