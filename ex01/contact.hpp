/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:58:04 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/28 11:22:39 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>
#include <string.h>

class Contact
{
	public:
		Contact();
		int	fill(int index);
		void	display_list();
		void	display_select();
	private:
		int	_index;
		std::string	_infos[5];
		std::string	_fields[5];
};

#endif
