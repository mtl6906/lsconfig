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
		int ec;
		root = json::api.decode(ec, in.split());
		if(ec < 0)
			throw Exception(ec);
		init();
	}
}
