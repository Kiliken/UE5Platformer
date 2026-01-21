#pragma once


#include "CoreMinimal.h"



namespace PUTILS{

    static AActor* GetActorByName(FString actorName, UWorld* world);
    static TArray<AActor*> GetActorsByTag(FName tag, UWorld* world);
}
