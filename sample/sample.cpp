#include "ls/Config.h"
#include "iostream"

using namespace std;
using namespace ls;

class TestConfig : public ls::Config
{
	public:
		int id;
		int number;
		TestConfig()
		{
			load();
		}
	protected:
		std::string getConfigPath() override
		{
			char *configPath = getenv("TEST_CONFIG_PATH");
			if(NULL == configPath)
				configPath = (char *)"test.conf";
			return configPath;	
		}

		void init() override
		{
			json::api.get(root, "id", id);
			json::api.get(root, "number", number);
		}

};

int main()
{
	TestConfig tc;
	cout << "id: " << tc.id << endl;
	cout << "number: "<< tc.number << endl;
	return 0;
}
