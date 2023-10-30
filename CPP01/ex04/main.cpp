/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:20:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/30 14:46:00 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool	replaceInString(std::string &input, const std::string &s1, const std::string &s2)
{
	size_t	pos = 0;
	bool	found = false;
	while ((pos = input.find(s1, pos)) != std::string::npos)
	{
		input.replace(pos, s1.length(), s2);
		pos += s2.length();
		found = true;
	}
	return (found);
}

int	main(int argc, char **argv)
{
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	std::string line;

	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (s1 == "" || s2 == "")
		std::cerr << "Error: Cannot work with empty inputs." << std::endl;
	std::ifstream input(filename);
	if (!input.is_open())
	{
		std::cerr << "Error: Unable to open file." << filename << std::endl;
		return (2);
	}
	std::string output_filename = filename + ".replace";
	std::ofstream output(output_filename);
	if (!output.is_open())
	{
		std::cerr << "Error: Unable to create or open the output file." << output_filename << std::endl;
		return (3);
	}
	while (std::getline(input, line))
	{
		if (replaceInString(line, s1, s2))
			output << line << '\n';
		else
			output << line << '\n';
	}
	input.close();
	output.close();
	std::cout << "File " << filename << " processed.Modified content saved to " << output_filename << std::endl;
	return (0);
}
