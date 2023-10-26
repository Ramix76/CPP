/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:55:53 by framos-p          #+#    #+#             */
/*   Updated: 2023/09/15 16:38:29 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int j=1; j < argc; j++){
			for (int i=0; argv[j][i]; i++) {
				std::cout << static_cast<char>(std::toupper(argv[j][i]));
			}
		}
		std::cout << std::endl;
	}
}
