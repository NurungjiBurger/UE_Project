// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyInputFire.h"

// Sets default values
AKeyInputFire::AKeyInputFire()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ��ƼŬ ���� �� ��Ʈ ������Ʈ �Ҵ�
	RootComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("RootComponent"));
	FireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));
	FireParticle->SetupAttachment(RootComponent);

	FireTime = 5;

}

// Called when the game starts or when spawned
void AKeyInputFire::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AKeyInputFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKeyInputFire::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("OFF", EInputEvent::IE_Pressed, this, &AKeyInputFire::OffFire);

}

void AKeyInputFire::Combustion()
{
	--FireTime;
	if (FireTime <= 0)
	{
		OffFire();
	}
}

void AKeyInputFire::OffFire()
{
	//GetWorldTimerManager().ClearTimer(FireTImerHandle);
	// ��ƼŬ ��Ȱ��ȭ
	FireParticle->DeactivateSystem();
}
