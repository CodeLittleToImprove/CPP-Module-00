/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:51 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 16:10:52 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

void	megaphone(int argc, char *argv[])
{
	std::string	input;
	std::string default_output;
	size_t		index = 1;

	if (argc > 1)
	{
		while(argv[index] != NULL)
		{
			input = argv[index];
			for (size_t x = 0; x < input.length(); x++)
				input[x] = static_cast<char>(std::toupper(input[x]));
			std::cout << input;
			index++;
		}
		std::cout << std::endl;
	}

	else if (argc == 1)
	{
		default_output = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << default_output << std::endl;
	}

}
int	main(int argc, char *argv[])
{
	megaphone(argc, argv);
	return (0);
}

