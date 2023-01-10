// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapCollisionActor.h"

// Sets default values
AOverlapCollisionActor::AOverlapCollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	RootComponent = BoxMesh;
}

// Called when the game starts or when spawned
void AOverlapCollisionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOverlapCollisionActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("NotifyActorBeginOverlap"));
}

void AOverlapCollisionActor::NotifyActorEndOverlap(AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("NotifyActorEndOverlap"));
}

// Called every frame
void AOverlapCollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

