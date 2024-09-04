/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:15:11 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/04 19:02:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		virtual ~MateriaSource();
		MateriaSource &operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria *a);
		virtual AMateria *createMateria(std::string const &type);
};


#endif