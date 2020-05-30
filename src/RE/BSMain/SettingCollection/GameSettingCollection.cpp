#include "RE/BSMain/SettingCollection/GameSettingCollection.h"


namespace RE
{
	GameSettingCollection* GameSettingCollection::GetSingleton()
	{
		REL::Offset<GameSettingCollection**> singleton(Offset::GameSettingCollection::Singleton);
		return *singleton;
	}


	Setting* GameSettingCollection::GetSetting(const char* a_name)
	{
		auto it = settings.find(a_name);
		return it != settings.end() ? it->second : nullptr;
	}
}
