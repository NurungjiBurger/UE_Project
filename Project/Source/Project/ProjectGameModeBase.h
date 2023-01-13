// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	// TSubClassOf - 전달된 대상이 <> 안에 넣어준 템플릿 인자의 타입과 일치하거나 해당 타입을 상속받은 타입인지를 런타임 중 확인해주는 클래스
public:
	UFUNCTION(BlueprintCallable, Category = "UMG_Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetclass);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
	UUserWidget* CurrentWidget;
};

// UMG - 언리얼 모션 그래픽 ( UI와 관련된 기능을 사용하기 위한 모듈 )
// 모듈은 *.Build.cs 파일의 PublicDependencyMoculeNames 에 추가해서 사용하며 PrivateDependencyModuleNames 부분에 UMG 외의 다른 모듈도 포함 가능.
