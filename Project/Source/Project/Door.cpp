// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 오브젝트 생성 및 할당
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = DoorMesh;

	CloseTime = 3.0f;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	// 게임 시작 당시의 액터의 회전 상태 저장
	OriginRotation = GetActorRotation();
	// &ADoor::Open 함수를 0.03 초 마다 반복 호출
	GetWorldTimerManager().SetTimer(DoorTimerHandle, this, &ADoor::Open, 0.03f, true);
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorDeltaTime += DeltaTime;
}

void ADoor::Open()
{
	if (!bOpen)
	{
		bOpen = true;
		DoorDeltaTime = 0.0f;
	}

	// 현재 액터의 회전 상태를 가져와서
	FRotator rotation = GetActorRotation();
	// 시간이 점점 지남에 따라 열리도록 회전값을 변경
	rotation = OriginRotation + FRotator(0.0f, FMath::Lerp(0.0f, 90.0f, DoorDeltaTime), 0.0f);
	// 변경된 회전값으로 액터의 회전 상태를 변경
	SetActorRotation(rotation);
	if (DoorDeltaTime > 1.0f)
	{
		GetWorldTimerManager().ClearTimer(DoorTimerHandle);
		GetWorldTimerManager().SetTimer(DoorTimerHandle, this, &ADoor::Close, 0.03f, true, CloseTime);
	}
}

void ADoor::Close()
{
	if (bOpen)
	{
		bOpen = false;
		DoorDeltaTime = 0.0f;
	}

	FRotator rotation = GetActorRotation();
	// 시간이 지남에 따라 닫히도록 회전값 변경
	rotation = OriginRotation + FRotator(0.0f, FMath::Lerp(90.0f, 0.0f, DoorDeltaTime), 0.0f);
	SetActorRotation(rotation);
	if (DoorDeltaTime > 1.0f)
	{
		GetWorldTimerManager().ClearTimer(DoorTimerHandle);
	}
}
