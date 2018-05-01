#include <string>

enum movieType
{
	regular, children, newRelease
};

class Movie
{
		public:
		int code;
		std::string title;
		movieType type;

		Movie();
		Movie(int c, std::string t, movieType m);


};
