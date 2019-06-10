#include "WorldTestLib.h"
#include "Util/LogUtilLib.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void UWorldTestLib::Test_All(UObject* WorldContextObject)
{
	UE_LOG(MyLog, Log, TEXT("Test_All..."));
	
	Test_Quick(WorldContextObject);

	Test_LogWorlds(WorldContextObject);

	Test_LoadWorld(WorldContextObject);

	Test_LoadDefaultStreamLevel(WorldContextObject);

	UE_LOG(MyLog, Log, TEXT("Test_All DONE"));
}

void UWorldTestLib::Test_Quick(UObject* WorldContextObject)
{
	UE_LOG(MyLog, Log, TEXT("Test_Quick..."));
	UE_LOG(MyLog, Error, TEXT("Not yet impl"));
	UE_LOG(MyLog, Log, TEXT("Test_Quick DONE"));
}

void UWorldTestLib::Test_LoadWorld(UObject* WorldContextObject)
{
	UE_LOG(MyLog, Log, TEXT("Test_LoadWorld..."));

	FName const NextLevelName { "LevelTwo", FNAME_Add };
	bool const bAbsolute = false; // Should we reset options?

	UWorld* W = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(W)
	{
		UE_LOG(MyLog, Log, TEXT("UGameplayStatic::OpenLevel; NextLevelName=\"%s\""), *NextLevelName.ToString());
		UGameplayStatics::OpenLevel(W, NextLevelName);
	}
	else
	{
		UE_LOG(MyLog, Error, TEXT("GetWorldFromContextObject returned nullptr!"));
	}
	

	UE_LOG(MyLog, Log, TEXT("Test_LoadWorld DONE"));
}

void UWorldTestLib::Test_LoadStreamLevel(UObject* WorldContextObject, const FName& InLevelName)
{
	UE_LOG(MyLog, Log, TEXT("Test_LoadStreamLevel..."));

	const bool bMakeVisibleAfterLoad = true;
	const bool bShouldBlockonLoad = true;

	// LatentActionInfo - may be used as default;
	FLatentActionInfo LatentActionInfo;

	UGameplayStatics::LoadStreamLevel(WorldContextObject, InLevelName, bMakeVisibleAfterLoad, bShouldBlockonLoad, LatentActionInfo);

	UE_LOG(MyLog, Log, TEXT("Test_LoadStreamLevel DONE"))
}

void UWorldTestLib::Test_LoadDefaultStreamLevel(UObject* WorldContextObject)
{
	UE_LOG(MyLog, Log, TEXT("Test_LoadDefaultStreamLevel..."));
	const FName LevelName = { "" }; // @TODO
	Test_LoadStreamLevel(WorldContextObject, LevelName);
	UE_LOG(MyLog, Log, TEXT("Test_LoadDefaultStreamLevel DONE"))
}

void UWorldTestLib::Test_LogWorlds(UObject* WorldContextObject)
{
	UE_LOG(MyLog, Log, TEXT("Test_LogWorlds..."));
	UE_LOG(MyLog, Error, TEXT("Not yet impl"));
	UE_LOG(MyLog, Log, TEXT("Test_LogWorlds DONE"));
}