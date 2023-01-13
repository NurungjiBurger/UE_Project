// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProjectGameModeBase.h"
#include <Blueprint/UserWidget.h>

void AProjectGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
}

void AProjectGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

// 게임이 시작되었을때 유저 위젯을 만들어 표시하거나 제거하기 위해 Game Mode 클래스에 함수와 프로퍼티를 추가해서 사용. 모든 프로젝트에는 *GameModeBase 파일이 딸려 올 것. 여기에 작성.
// UE 는 한번에 다수의 위젯을 표시하고 처리가 가능하며 한번에 하나씩도 가능. 하지만 직접 소멸 시킬 필요는 없음. UE 의 가비지 컬렉션 시스템에서 해주기 때문.
// UE 클래스 cpp 구현시 머리부분에 A 꼭 붙히자...