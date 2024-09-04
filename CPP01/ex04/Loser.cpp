/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loser.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:20:57 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/03 12:41:01 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loser.hpp"

Loser::Loser()
{}

Loser::~Loser()
{}

bool Loser::Sed(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	Ofile;
	std::string	str;
	std::size_t	pos;

	Ofile.open(filename.c_str());
	if (!Ofile.is_open() || !Ofile.good())
	{
		std::cout << "Error: Failed to open the file." << std::endl;
		Ofile.close();
		return (1);
	}
	std::ofstream Cfile((filename + ".replace").c_str() , std::ios::trunc);
	if (!Cfile.good())
	{
		std::cout << "Error: Invalid file." << std::endl;
		Ofile.close();
		Cfile.close();
		return (1);	
	}
	if (s1.length() > 0 && s2.length() > 0)
	{
		while(std::getline(Ofile, str))
		{
			pos = 0;
			while((pos = str.find(s1, pos)) != std::string::npos)
			{
				str.erase(pos, s1.length());
				str.insert(pos, s2);
				pos = pos + s2.length();
			}
			Cfile << str << '\n';
		}
	}
	else
	{
		std::cout << "Error: One of the arguments if empty." << std::endl;
		Ofile.close();
		Cfile.close();
		return (1);
	}
	Ofile.close();
	Cfile.close();
	return (0);	
}