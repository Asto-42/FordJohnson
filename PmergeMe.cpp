/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/07/25 13:25:13 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
};

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
{
	std::cout << "Operator called for PmergeMe\n";
	if (this != &rhs)
	{
		this->C_list = rhs.C_list;
		this->D_list = rhs.D_list;
	}
	return (*this);
}

PmergeMe::PmergeMe(PmergeMe & rhs)
{
	// std::cout << "Copy constructor called\n";
	if (this != &rhs)
	{
		this->C_list = rhs.C_list;
		this->D_list = rhs.D_list;
	}
	return ;
}

struct PrintNumber
{
	void operator()(const int n) const
	{
		std::cout << n << std::setw(4);
	}
};

struct Printpair
{
	void operator()(const int n) const
	{
		std::cout << n << std::setw(4);
	}
};

template <typename T>
void	print_vector(T &tmp, int size, std::string c)
{
	std::vector<int> lst;
	for (int x = 0; x < size; x++)
		lst.push_back(tmp[x].value);
	std::vector<int> lst2;
	for (int x = 0; x < size; x++)
		lst2.push_back(tmp[x].pair);
	if (lst.empty() == 0)
	{
		std::cout << std::endl;
		std::cout << c << " =	";
		std::for_each(lst.begin(), lst.end(), PrintNumber());
		std::cout << std::endl;
		std::cout << "	";
		std::for_each(lst2.begin(), lst2.end(), Printpair());
		std::cout << std::endl;
	}
}

template <typename T>
void	SplitX2(T &lst)
{
	T main;
	T tmp;
	for (size_t x = 0; x < lst.size() - 1; x+= 2)
	{
		nb_comp++;
		if (lst[x].value > lst[x + 1].value)
			std::swap(lst[x].value, lst[x + 1].value);
	}
	if (lst.size() > 2)
	{
		int y = 0;
		for (size_t x = 0; x < lst.size(); x++)
		{
			if (lst.size() != 2 && x == lst.size() - 1)
			{
				tmp.push_back(lst[x]);
				tmp[y].pair = y;
			}
			else
			{
				tmp.push_back(lst[x + 1]);
				tmp[y].pair = y;
				if (x < lst.size() - 1)
				{
					main.push_back(lst[x]);
					main[y].pair = lst[x + 1].value;
				}
				x++;
			}
			y++;
		}
		SplitX2(tmp);
		for (size_t x = 0; x < main.size(); x++)
		{
			nb_comp++;
			if (main[x].pair == tmp[0].value)
			{
				tmp.insert(tmp.begin(), main[x]);
				main.erase(main.begin() + x);
				x = 0;
				break ;
			}
		}
		size_t nb_push = 0;
		while (main.size() > 0)
		{
			size_t y = 0;
			while (y < main.size())
			{
				for (size_t x = 0; x < tmp.size(); x++)
				{
					if (tmp[x].value == main[y].pair)
					{
						size_t x2 = 0;
						while (x2 + 1 < x)
						{
							nb_comp++;
							if (tmp[(x+x2)/2].value < main[y].value)
								x2 = (x + x2) / 2;
							else if (tmp[(x+x2)/2].value > main[y].value)
								x = (x + x2) / 2;
						}
						if (x2 != 0)
							tmp.insert(tmp.begin() + x2 + 1, main[y]);
						else
						{
							if (main[y].value < tmp[0].value)
								tmp.insert(tmp.begin(), main[y]);
							else
								tmp.insert(tmp.begin() + 1, main[y]);
						}
						nb_push++;
						main.erase(main.begin() + y);
						break ;
					}
				}
				y++;
			}
		}
		lst = tmp;
	}
}

template <typename T>
bool is_sorted(T &lst)
{
	for (size_t x = 0; x < lst.size() - 1; x++)
	{
		if (lst[x].value > lst[x + 1].value)
			return (0);
	}
	return (1);
}

template <typename T>
void	SplitX(T &lst, long long int max_comp)
{
	T main;
	T tmp;

	if (lst.size() >= 2)
	{
		int y = 0;
		for (size_t x = 0; x < lst.size(); x += 2)
		{
			nb_comp++;
			if (lst[x].value > lst[x + 1].value)
				std::swap(lst[x].value, lst[x + 1].value);
			tmp.push_back(lst[x + 1]);
			if (tmp[y].pair == 0)
				tmp[y].pair = y;
			main.push_back(lst[x]);
			if (main[y].pair == 0)
				main[y].pair = lst[x + 1].value;
			y++;
		}
		SplitX2(tmp);
	}
	for (size_t x = 0; x < main.size(); x++)
	{
		nb_comp++;
		if (main[x].pair == tmp[0].value)
		{
			tmp.insert(tmp.begin(), main[x]);
			main.erase(main.begin() + x);
			x = 0;
			break ;
		}
	}
	size_t nb_push = 0;
	while (main.size() > 0)
	{
		size_t y = 0;
		bool equal = 0;
		while (y < main.size())
		{
			for (size_t x = 0; x < tmp.size(); x++)
			{
				equal = 0;
				if (tmp[x].value == main[y].pair)
				{
					size_t x2 = 0;
					while (equal != 1 && x2 + 1 < x)
					{
						nb_comp++;
						if (tmp[(x+x2)/2].value < main[y].value)
							x2 = (x + x2) / 2;
						else if (tmp[(x+x2)/2].value > main[y].value)
							x = (x + x2) / 2;
						else if (tmp[(x+x2)/2].value == main[y].value)
							equal = 1;
					}
					if (equal != 1)
					{
						if (x2 != 0)
							tmp.insert(tmp.begin() + x2 + 1, main[y]);
						else
						{
							if (main[y].value < tmp[0].value)
								tmp.insert(tmp.begin(), main[y]);
							else
								tmp.insert(tmp.begin() + 1, main[y]);
						}
						nb_push++;
					}
					main.erase(main.begin() + y);
					break ;
				}
			}
			y++;
		}
	}
	lst = tmp;
	long long int result = max_comp - nb_comp;
	std::cout << "lst size = " << lst.size() << "\n";
	//print_vector(lst, lst.size(), "lst");
	std::cout << "Nb comp = " << nb_comp << std::endl;
	std::cout << "Diff = " << result << std::endl;
	nb_comp = 0;
	if (is_sorted(tmp) == 0)
		std::cout << "FALSE\n";
	else
		std::cout << "TRUE\n";
}

PmergeMe::PmergeMe(unsigned int size, char **argv, unsigned int max_comp, int x)
{
	if (x == 1)
	{
		this->n_c = size;
		t_pair pair;
		for (size_t x = 1; x <= this->n_c; x++)
		{
			pair.value = atoi(argv[x]);
			pair.pair = 0;
			this->C_list.push_back(pair);
		}
		SplitX(this->C_list, max_comp);
	}
	else
	{
		this->n_c = size;
		t_pair pair;
		for (size_t x = 1; x <= this->n_c; x++)
		{
			pair.value = atoi(argv[x]);
			pair.pair = 0;
			this->D_list.push_back(pair);
		}
		SplitX(this->D_list, max_comp);
	}
};

PmergeMe::~PmergeMe(void)
{
	//std::cout << "Default destructor called" << std::endl;
}
