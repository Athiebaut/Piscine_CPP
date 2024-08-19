/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:45:32 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/16 17:11:48 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap &operator=(FragTrap const &src);
		
		std::string	getName(void) const;
		int		getHP(void) const;
		int		getEP(void) const;
		int		getAD(void) const;
		
		void		setHP(void);
		void		setEP(void);
		void		setAD(void);
		void		setName(std::string name);
		
		void	highFivesGuys();
	private:

};

#endif