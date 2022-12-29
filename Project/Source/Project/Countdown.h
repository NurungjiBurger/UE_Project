// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components//TextRenderComponent.h>
#include "Countdown.generated.h"

UCLASS()
class PROJECT_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// UPROPERTY 전 주석을 달아두면 UE 에디터에서도 주석이 보이므로 변수에 대한 설명으로 활용 가능
	// How long, in seconds
	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay();

	void AdvanceTimer();

	// 블루프린트로도 사용 가능하게 만들어주는 함수
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();
	// 카운트다운이 끝났을때 타이머가 종료되도록 핸들하기 위함
	FTimerHandle COuntdownTimerHandle;

};
