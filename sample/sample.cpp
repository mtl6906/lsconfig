#include "ls/Config.h"
#include "iostream"

using namespace std;
using ls::json::Int;

class TestConfig : public ls::Config
{
	public:
		int id;
		int number;
		TestConfig()
		{
			char *configPath = getenv("TEST_CONFIG_PATH");
			if(NULL == configPath)
				configPath = (char *)"test.conf";
			load(configPath);
			GET_INT(root, "id", id);
			GET_INT(root, "number", number);
		}
};

int main()
{
	TestConfig tc;
	cout << "id: " << tc.id << endl;
	cout << "number: "<< tc.number << endl;
	return 0;
}
