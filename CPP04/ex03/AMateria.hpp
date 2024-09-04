/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:16:29 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/04 14:20:24 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
		
	protected:
		const std::string _type;
};

#endif