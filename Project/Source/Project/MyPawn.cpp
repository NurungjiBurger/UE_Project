// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include <Engine/Classes/Camera/CameraComponent.h>

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������ ���۵Ǹ� �ڵ����� �÷��̾��� �Է��� ����ǵ��� ��.
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// ī�޶� ������Ʈ
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	// ������ ���̰Ե� ������Ʈ
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float currentScale = OurVisibleComponent->GetComponentScale().X;
	if (Growing)
	{
		if (InputTime > 0.0f && InputTime <= 0.5f)
		{
			currentScale = 2.0f;
		}
		else
		{
			currentScale += DeltaTime;
		}
	}
	else
	{
		currentScale -= DeltaTime * 0.5f;
	}
	currentScale = FMath::Clamp(currentScale, 1.0f, 2.0f);
	OurVisibleComponent->SetWorldScale3D(FVector(currentScale));

	if (!CurrentVelocity.IsZero())
	{
		InputTime += DeltaTime;
		FVector newLocation = GetActorLocation() + (CurrentVelocity * DeltaTime * (InputTime <= 1.0f ? 1.0f : 3.0f));
		SetActorLocation(newLocation);
	}
	else
	{
		InputTime = 0.0f;
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	PlayerInputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StopGrowing);

	PlayerInputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
	PlayerInputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);

}

void AMyPawn::Move_XAxis(float AxisValue)
{
	// clamp�� �̿��� -1 ~ 1������ ������ ���� ( ���� ó���� �ؾ��ϴ� �Է��� ���ÿ� ������ ��� �ջ�Ǿ� ó���Ǳ� ������ �׸� �����ϱ� ���� )
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::Move_YAxis(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::StartGrowing()
{
	Growing = true;
}

void AMyPawn::StopGrowing()
{
	Growing = false;
}