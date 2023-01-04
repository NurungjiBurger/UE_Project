// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class PROJECT_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

	// 프로퍼티가 UE 및 에디터에 해당 프로퍼티의 존재를 알리고 연결시 어떻게 작동할지 결정
	//UPROPERTY()
	//int32 IntVariable;

	// 기존에 사용하던 short, int, long 은 플랫폼마다 지정된 길이가 다를 수 있기 때문에 길이를 한정해서 사용해야함.
	// short s; int i; long l;
	// intN N개의 비트를 사용해서 정수를 표현하겠다. uintN 음수의 표현이 필요없다면 u를 붙혀줌.
	//int8 i8;
	//int16 i16;
	//int32 i32;
	//int64 i64;

	//float f;
	//double d;

	// 기존 string에 넣는 것 처럼 "" 를 사용해서 넣어줄 수 없음. TEXT 매크로 사용.
	//FString str;

	//bool b;


	// UPROPERTY매크로 지정자들
	// EditAnywhere 어디서나 편집 가능, VisibleAnywhere 어디서나 볼 수 있음 ( 편집 x ), Transient 휘발성 프로퍼티로 저장 x

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageTimeInSeconds;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category="Damage")
	float DamagePerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAttackable;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
