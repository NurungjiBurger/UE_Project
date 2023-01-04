// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
	: TotalDamage(200), DamageTimeInSeconds(1.0f), CharacterName(TEXT("UE")), bAttackable(true)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TotalDamage = 500;
	CharacterName = TEXT("����");

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
