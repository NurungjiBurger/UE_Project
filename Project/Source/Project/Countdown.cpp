// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	// false로 변경시 tick 사용 안함
	PrimaryActorTick.bCanEverTick = false;

	// <> 안의 타입 컴포넌트를 자동 생성해서 반환 초기화 함수
	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown Text"));
	// 정렬
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);

	// RootComponent란?
	RootComponent = CountdownText;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();

	// 초기화된 CountdownTime 출력
	UpdateTimerDisplay();

	// 타이머 실행
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