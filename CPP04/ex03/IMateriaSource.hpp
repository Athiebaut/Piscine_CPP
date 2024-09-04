/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:15:01 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/04 19:02:23 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource( void );
        	IMateriaSource( const IMateriaSource &other );
        	virtual ~IMateriaSource();
		IMateriaSource &operator=( const IMateriaSource &other );

        	virtual void learnMateria(AMateria*) = 0;
        	virtual AMateria* createMateria(std::string const & type) = 0;

		protected:
			AMateria *_inventory[4];
};

#endif
