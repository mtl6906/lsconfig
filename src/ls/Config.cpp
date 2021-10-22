#include "ls/Config.h"
#include "ls/Buffer.h"
#include "ls/file/API.h"
#include "ls/io/Factory.h"

using namespace std;

namespace ls
{
	Config::~Config()
	{
	
	}

	void Config::load()
	{
		auto configFile = file::api.get(getConfigPath());
		io::InputStream in(configFile -> getReader(), new Buffer());
		in.read();
		root = json::api.decode(in.split());
		init();
	}
}
