/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:01:52 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/28 16:14:03 by athiebau         ###   ########.fr       */
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
		int	_oldest;
};

#endif