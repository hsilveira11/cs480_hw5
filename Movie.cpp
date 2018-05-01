#include "Movie.hpp"

Movie::Movie()
{
	code=0;
	title=" ";
	type=regular;
}

Movie::Movie(int c, std::string t, movieType m)
{
	code=c;
	title=t;
	type=m;

}
