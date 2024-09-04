/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:22:36 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/04 14:26:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		~Character();
		Character &operator=(const Character &other);

		virtual std::string const &getName() const;
		virtual void equip(AMateria *am);
		virtual void unequip(int index);
		virtual void use(int index, ICharacter &target);

	private:
		const std::string _name;
		int _count;
};

#endif