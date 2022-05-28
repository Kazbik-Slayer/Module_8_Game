// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "ProjectCharacter.h"
#include "Engine/World.h"

AProjectPlayerController::AProjectPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
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
	GetPawn()->AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), Axis);
}

void AProjectPlayerController::OnMoveRightPressed(float Axis)
{
	GetPawn()->AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), Axis);
}
