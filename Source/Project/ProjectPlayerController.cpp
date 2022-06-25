// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "ProjectCharacter.h"
#include "Engine/World.h"

AProjectPlayerController::AProjectPlayerController() : bDisableMoving(false)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AProjectPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI());
}

void AProjectPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void AProjectPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AProjectPlayerController::OnMoveForwardPressed);
	InputComponent->BindAxis("MoveRight", this, &AProjectPlayerController::OnMoveRightPressed);

}

void AProjectPlayerController::OnMoveForwardPressed(float Axis)
{
	Cast<AProjectCharacter>(GetPawn());
	if (!bDisableMoving) {
		FRotationMatrix rotationM(GetControlRotation());
		GetPawn()->AddMovementInput(rotationM.GetUnitAxis(EAxis::X), Axis);
	}
}

void AProjectPlayerController::OnMoveRightPressed(float Axis)
{
	if (!bDisableMoving) {
		FRotationMatrix rotationM(GetControlRotation());
		GetPawn()->AddMovementInput(rotationM.GetUnitAxis(EAxis::Y), Axis);
	}
}
