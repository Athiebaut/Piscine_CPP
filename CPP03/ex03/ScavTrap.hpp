/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:22:36 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/16 17:10:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap(void);
		ScavTrap &operator=(ScavTrap const &other);
		
		std::string	getName(void) const;
		int		getHP(void) const;
		int		getEP(void) const;
		int		getAD(void) const;
		
		void		setName(std::string name);
		void		setHP(void);
		void		setEP(void);
		void		setAD(void);

		void attack(const std::string& target);
		void	guardGate();
	private:
};

#endif