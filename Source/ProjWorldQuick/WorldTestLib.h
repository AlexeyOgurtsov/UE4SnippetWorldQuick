#pragma once

#include "WorldTestLib.generated.h"

UCLASS()
class UWorldTestLib : public UBlueprintFunctionLibrary
{	
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Test, Meta = (WorldContext = WorldContextObject))
	void Test_All(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = Test, Meta = (WorldContext = WorldContextObject))
	void Test_Quick(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = Test, Meta = (WorldContext = WorldContextObject))
	void Test_LogWorlds(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = Test, Meta = (WorldContext = WorldContextObject))
	void Test_LoadWorld(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = Test, Meta = (WorldContext = WorldContextObject))
	void Test_LoadStreamLevel(UObject* WorldContextObject, const FName& InWorldName);

	UFUNCTION(BlueprintCallable, Category = Test, Meta = (WorldContext = WorldContextObject))
	void Test_LoadDefaultStreamLevel(UObject* WorldContextObject);
};