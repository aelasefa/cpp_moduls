#include <iostream>

char *ft_upper(char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return str;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return 1;
	}
	int i = 1;
	while (i < ac)
	{
		ft_upper(av[i]);
		std::cout << av[i];
		std::cout << '\n';
		i++;
	}
	return 0;
}
