// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGPlayerController.h"

void AUMGPlayerController::BeginPlay()
{
    Super::BeginPlay();
    // 게임과 UI 모두 입력이 가능한 상태로 만들어줌.
    SetInputMode(FInputModeGameAndUI());
}