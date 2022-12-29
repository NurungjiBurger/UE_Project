// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	// false�� ����� tick ��� ����
	PrimaryActorTick.bCanEverTick = false;

	// <> ���� Ÿ�� ������Ʈ�� �ڵ� �����ؼ� ��ȯ �ʱ�ȭ �Լ�
	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown Text"));
	// ����
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);

	// RootComponent��?
	RootComponent = CountdownText;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();

	// �ʱ�ȭ�� CountdownTime ���
	UpdateTimerDisplay();

	// Ÿ�̸� ����
	GetWorldTimerManager().SetTimer(COuntdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
	
}

void ACountdown::UpdateTimerDisplay() 
{
	CountdownText->SetText(FText::FromString(FString::FromInt(FMath::Max(CountdownTime, 0))));
}

void ACountdown::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();

	if (CountdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(COuntdownTimerHandle);
		CountdownHasFinished();
	}
}

void ACountdown::CountdownHasFinished_Implementation()
{
	CountdownText->SetText(FText::FromString("Go!"));
}