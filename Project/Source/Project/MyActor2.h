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

	// ������Ƽ�� UE �� �����Ϳ� �ش� ������Ƽ�� ���縦 �˸��� ����� ��� �۵����� ����
	//UPROPERTY()
	//int32 IntVariable;

	// ������ ����ϴ� short, int, long �� �÷������� ������ ���̰� �ٸ� �� �ֱ� ������ ���̸� �����ؼ� ����ؾ���.
	// short s; int i; long l;
	// intN N���� ��Ʈ�� ����ؼ� ������ ǥ���ϰڴ�. uintN ������ ǥ���� �ʿ���ٸ� u�� ������.
	//int8 i8;
	//int16 i16;
	//int32 i32;
	//int64 i64;

	//float f;
	//double d;

	// ���� string�� �ִ� �� ó�� "" �� ����ؼ� �־��� �� ����. TEXT ��ũ�� ���.
	//FString str;

	//bool b;


	// UPROPERTY��ũ�� �����ڵ�
	// EditAnywhere ��𼭳� ���� ����, VisibleAnywhere ��𼭳� �� �� ���� ( ���� x ), Transient �ֹ߼� ������Ƽ�� ���� x

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
