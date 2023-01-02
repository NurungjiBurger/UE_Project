// Fill out your copyright notice in the Description page of Project Settings.


#include "GameActor.h"

// Sets default values
AGameActor::AGameActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TotalDamage = 200;
	DamageTimeInSeconds = 1.0f;

	str = TEXT("test");

}

// Called when the game starts or when spawned
void AGameActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameActor::FunctionName()
{

}

void AGameActor::CalculateDPS()
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

void AGameActor::PostInitProperties()
{
	// 부모클래스 함수를 한번 실행해주어야 실제 처리하는게 제대로 돌아간다???
	Super::PostInitProperties();
	CalculateDPS();
}

void AGameActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangeEvent)
{
	CalculateDPS();
	Super::PostEditChangeProperty(PropertyChangeEvent);
}

