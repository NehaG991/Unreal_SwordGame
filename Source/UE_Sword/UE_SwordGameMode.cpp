// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_SwordGameMode.h"
#include "UE_SwordCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_SwordGameMode::AUE_SwordGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
