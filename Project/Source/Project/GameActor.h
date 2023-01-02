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

	// �������Ʈ���� ������ ����� CPP ������ ����ϱ� ���� ��ũ�� BlueprintImplementableEvent �� ��� �Լ� ��ü�� ���� �ʿ䰡 ������ BP �� ������ �ȵǾ�������� �� �Լ��� ȣ���.
	// �ι�° ��ũ�δ� BlueprintNativeEvent �� �Ʒ� �ּ� �κа� ���� �� �� �ְ� ���� ��ũ�ο� �޸� BP �� ������ �ȵǾ��ִ� ��� ������ �⺻ ����� CPP���� ������ �� �ְ� ����.
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

	// �������Ʈ���� ����ϱ� ���� UFUCNTION �ش� Ŭ������ ������� �������Ʈ ��ũ��Ʈ ������ C++ �ڵ带 ������� �ʱ�ȭ ��.
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void CalculateDPS();


	// �θ� Ŭ������ �ִ� �Լ��� ������ ������ �ؼ� ����� ���̹Ƿ� virtual �� overrid ���
	virtual void PostInitProperties() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangeEvent) override;

};
