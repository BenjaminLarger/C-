#include <iostream>
#define NO_NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
using namespace std;

namespace	megaphone {
			int	no_noise()
			{
				std::cout << NO_NOISE << endl;
				return (0);
			}
			void	display_noise(char *noise)
			{
				bool	has_quotes;
				int		i;

				has_quotes = noise[0] == '"';
				i = has_quotes ? 1 : 0;
				while (noise[i] != '\0')
				{
					std::cout << static_cast<char>(std::toupper(noise[i]));
					i++;
					if (has_quotes == true && noise[i] == '"' && noise[i + 1] == '\0')
						break;
				}
			}
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return (megaphone::no_noise());
    for(int i = 1; i < argc; i++)
    {
		megaphone::display_noise(argv[i]);
		if (i < argc - 1)
			std::cout << ' ';
    }
	std::cout << endl;
}
