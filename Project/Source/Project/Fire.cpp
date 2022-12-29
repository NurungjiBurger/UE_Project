// Fill out your copyright notice in the Description page of Project Settings.

#include "Fire.h"

// Sets default values
AFire::AFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 파티클 생성 및 루트 컴포넌트 할당
	FireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));
	RootComponent = FireParticle;

	FireTime = 5;

}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();

	// &AFire::Combustion 1초 마다 반복 호출
	GetWorldTimerManager().SetTimer(FireTImerHandle, this, &AFire::Combustion, 1.0f, true);
	
}

// Called every frame
void AFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFire::Combustion()
{
	--FireTime;
	if (FireTime <= 0)
	{
		OffFire();
	}
}

void AFire::OffFire()
{
	GetWorldTimerManager().ClearTimer(FireTImerHandle);
	// 파티클 비활성화
	FireParticle->DeactivateSystem();
}
