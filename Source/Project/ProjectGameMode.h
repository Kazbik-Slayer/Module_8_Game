// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectGameMode.generated.h"

UCLASS(minimalapi)
class AProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	AProjectGameMode();

	UFUNCTION(BlueprintCallable, Category = "Project")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Project")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;

	UPROPERTY(EditAnyWhere, Category = "Class Types")
		TSubclassOf<UUserWidget> MainMenuWidgetClass;

	virtual void BeginPlay() override;
};