#include "ls/Config.h"
#include "ls/util.h"
#include "cstdlib"

using namespace std;

namespace ls
{
	void Config::Load(const string &pathname)
	{
		string text;
		if(ReadFullFile(pathname, text) < 0)
		{
			fprintf(stderr, "no config\n");
			exit(1);
		}
		root.ParseFrom(text);
	}
}
