// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameActor.generated.h"

UCLASS()
class PROJECT_API AGameActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageTimeInSeconds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category = "Damage")
	float DamagePerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	FString str;

	// 블루프린트에서 구현된 기능을 CPP 에서도 사용하기 위한 매크로 BlueprintImplementableEvent 이 경우 함수 본체를 만들 필요가 없지만 BP 에 구현이 안되어있을경우 빈 함수가 호출됨.
	// 두번째 매크로는 BlueprintNativeEvent 로 아래 주석 부분과 같이 쓸 수 있고 위의 매크로와 달리 BP 에 구현이 안되어있는 경우 동작할 기본 기능을 CPP에서 구현할 수 있게 해줌.
	UFUNCTION(BlueprintImplementableEvent, Category = "Damage")
	void CallFromCpp();

	//UFUNCTION(BlueprintNativeEvent, Category = "Damage")
	//void CallFromCpp();
	//virtual void CallFromCpp_Implementation();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FunctionName();

	// 블루프린트에서 사용하기 위한 UFUCNTION 해당 클래스를 기반으로 블루프린트 스크립트 생성시 C++ 코드를 기반으로 초기화 됨.
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void CalculateDPS();


	// 부모 클래스에 있는 함수를 가져다 재정의 해서 사용할 것이므로 virtual 과 overrid 사용
	virtual void PostInitProperties() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangeEvent) override;

};
