#include <iostream>
#define NO_NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
using namespace std;

namespace	megaphone {
			int	no_noise() {
				std::cout << NO_NOISE << endl;
				return (0);
			}
			void	display_noise(char *noise) {
				int		i;
				bool	has_quotes;
				i = 0;
				if (noise[0] == '"')
				{
					has_quotes = true;
					i++;
				}
				else
					has_quotes = false;
				while (noise[i] != '\0')
				{
					if (noise[i] >= 'a' && noise[i] <= 'z')
						noise[i] -= 32;
					std::cout << noise[i];
					i++;
					if (has_quotes == true && noise[i + 1] == '\0')
						break;
				}
			}
}

using namespace megaphone;

int main(int argc, char **argv)
{
    int	i;

    if (argc == 1)
        return (no_noise());
    i = 1;
    while (i < argc)
    {
		display_noise(argv[i]);
		i++;
		std::cout << ' ';
    }
	std::cout << endl;
}
