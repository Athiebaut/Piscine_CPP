/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:01:52 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/26 23:12:26 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		int		add();
		int		select();
		int		display_phonebook();
	private:
		Contact _contact[8];
		int	_nb;
};

#endif