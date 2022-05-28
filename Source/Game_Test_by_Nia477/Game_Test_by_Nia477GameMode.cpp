// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game_Test_by_Nia477GameMode.h"
#include "Game_Test_by_Nia477PlayerController.h"
#include "Game_Test_by_Nia477Character.h"
#include "UObject/ConstructorHelpers.h"

AGame_Test_by_Nia477GameMode::AGame_Test_by_Nia477GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGame_Test_by_Nia477PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}