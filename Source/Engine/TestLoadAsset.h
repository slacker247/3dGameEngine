#include <stdio.h>

#include "String.h"
#include "LoadAsset.h"

#pragma once

namespace Testing
{
	namespace Loaders
	{
		class TestLoadAsset
		{
		public:
			TestLoadAsset(void);
			~TestLoadAsset(void);

			static void run();
			static Asset* loadAsset(String& file);
		};
	}
}