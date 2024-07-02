/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 05:33:36 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 05:40:01 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string&	stringREF(str);

	std::cout << "str adress : " << &str << std::endl;
	std::cout << "adress in stringPTR : " << stringPTR << std::endl;
	std::cout << "adress in stringREF : " << &stringREF << std::endl << std::endl;

	std::cout << "str : " << str << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
}