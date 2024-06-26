/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:58:04 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/26 22:50:34 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib> 

class Contact
{
	public:
		Contact();
		int	fill(int index);
	private:
		int	_index;
		std::string	_infos[5];
		std::string	_fields[5];
};

#endif
