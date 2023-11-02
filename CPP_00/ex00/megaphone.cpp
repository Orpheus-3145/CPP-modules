/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 17:33:06 by fra           #+#    #+#                 */
/*   Updated: 2023/09/27 17:52:15 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_args(int argc, char **argv)
{
	int	j;

	for (int i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 'a') && (argv[i][j] <= 'z'))
				std::cout << (char) (argv[i][j] - 32);
			else
				std::cout << (char) argv[i][j];
			j++;
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_args(argc, argv);
	return (0);
}
