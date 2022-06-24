// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsModel.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_API UStatsModel : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsModel();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Mana;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Agility;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Strength;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Intelligence;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float BaseDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float PhisicalRes;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float MagicalRes;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float DamageDealAmp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float DamageTakeAmp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TMap<FString, float> OtherStats;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category = "Import")
	virtual void ChangeStats(const UStatsModel* DeltaStats);
};
