// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5PlatformerGameMode.h"
#include "UE5PlatformerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5PlatformerGameMode::AUE5PlatformerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
