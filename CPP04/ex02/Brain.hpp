/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:03:57 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 15:57:23 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain const &other);
		virtual ~Brain();
		Brain &operator=(Brain const &other);
	
		std::string ideas[100]; 
};