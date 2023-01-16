// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProjectGameModeBase.h"

void AProjectGameModeBase::StartPlay()
{
    Super::StartPlay();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello Start, this is FPS Game"));
    }
}