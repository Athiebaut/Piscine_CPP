/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loser.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:05:32 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 09:25:04 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOSER_HPP
#define LOSER_HPP

#include <iostream>
#include <fstream>
#include <filesystem>

class Loser
{
	public:
		Loser();
		~Loser();
		static bool	Sed(std::string filename, std::string s1, std::string s2);	

	private:

};

#endif