// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5PlatformerGameMode.h"
#include "UE5PlatformerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "GameController.h"

AUE5PlatformerGameMode::AUE5PlatformerGameMode()
{
	UWorld* const World = GetWorld();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	
    if (World)
    {
        // Setup game controller
        AGameController* GameContoller = World->SpawnActor<AGameController>();

        if (GameContoller)
        {
            // Further configuration can be done here after spawning
            UE_LOG(LogTemp, Log, TEXT("Successfully spawned NewActor!"));
        }
    }
}
