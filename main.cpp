/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:41:53 by jquil             #+#    #+#             */
/*   Updated: 2024/09/10 13:00:27 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int calcul_max_comp(int nb)
{
	int max_comp;

	max_comp = (nb * log2(nb)) - (1.415 * (nb));
	max_comp = max_comp * 1.1;
	std::cout << "For " << nb << " integers, the max comp is " << max_comp << std::endl;
	return (max_comp);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (0);
	}

	//Vector Part
	const clock_t begin_time = clock();

	PmergeMe data((unsigned int)argc - 1, argv, calcul_max_comp(argc - 1), 1);
	const clock_t end_time = clock();
	std::cout << ((end_time - begin_time) * 1000) / CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << ((end_time - begin_time) * 1000 * 1000) / CLOCKS_PER_SEC << " µs" << std::endl;

	//Deque Part
	const clock_t begin_time_2 = clock();

	PmergeMe data2((unsigned int)argc - 1, argv, calcul_max_comp(argc - 1), 2);
	const clock_t end_time_2 = clock();
	std::cout << ((end_time_2 - begin_time_2) * 1000) / CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << ((end_time_2 - begin_time_2) * 1000 * 1000) / CLOCKS_PER_SEC << " µs" << std::endl;
	return (0);
}
