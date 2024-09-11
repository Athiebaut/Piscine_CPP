/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:54 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:39:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
	public:
		ICharacter();
		ICharacter(std::string const name);
		ICharacter(const ICharacter &other);
		virtual ~ICharacter();
		ICharacter &operator=(const ICharacter &other);

		virtual std::string const &getName() const = 0;
		
        	virtual void equip(AMateria *am) = 0;
       		virtual void unequip(int index) = 0;
		virtual void use(int index, ICharacter& target) = 0;

		protected:
        		AMateria *_inventory[4];
		
};


#endif