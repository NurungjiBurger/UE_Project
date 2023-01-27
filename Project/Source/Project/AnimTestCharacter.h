// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimTestCharacter.generated.h"

UCLASS()
class PROJECT_API AAnimTestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimTestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveX(float AxisValue);

	UFUNCTION()
		void MoveY(float AxisValue);

	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* TPSCameraSpringArmComponent;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* TPSCameraComponent;

};
