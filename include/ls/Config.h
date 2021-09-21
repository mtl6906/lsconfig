#ifndef LS_CONFIG_H
#define LS_CONFIG_H

#include "ls/json/API.h"

namespace ls
{
	class Config
	{
		public:
			virtual ~Config();
		protected:
			void load();
			virtual std::string getConfigPath() = 0;
			virtual void init() = 0;
			json::Object root;
	};
}

#endif
