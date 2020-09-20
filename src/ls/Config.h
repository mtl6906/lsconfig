#ifndef LS_CONFIG_H
#define LS_CONFIG_H

#include "ls/json/Json.h"

namespace ls
{
	class Config
	{
		protected:
			json::Object root;
		public:
			Config() = default;
			void Load(const std::string &pathname);
	};
}

#endif
