// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsModel.h"

// Sets default values for this component's properties
UStatsModel::UStatsModel() : Health(0.0), Mana(0.0), Agility(0.0), Strength(0.0), Intelligence(0.0),
	BaseDamage(0.0), PhisicalRes(0.0), MagicalRes(0.0), DamageDealAmp(0.0), DamageTakeAmp(0.0)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}


// Called when the game starts
void UStatsModel::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatsModel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStatsModel::ChangeStats(const UStatsModel* DeltaStats)
{
	Health += DeltaStats->Health;
	Mana += DeltaStats->Mana;
	Agility += DeltaStats->Agility;
	Strength += DeltaStats->Strength;
	Intelligence += DeltaStats->Intelligence;
	BaseDamage += DeltaStats->BaseDamage;
	PhisicalRes += DeltaStats->PhisicalRes;
	MagicalRes += DeltaStats->MagicalRes;
	DamageDealAmp += DeltaStats->DamageDealAmp;
	DamageTakeAmp += DeltaStats->DamageTakeAmp;

	for (auto it = OtherStats.begin(); it != OtherStats.end(); ++it) {
		const float* other = DeltaStats->OtherStats.Find(it->Key);
		if (other) {
			it->Value += *other;
		}
	}
}

