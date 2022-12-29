// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/StaticMeshComponent.h>
#include "Door.generated.h"

UCLASS()
class PROJECT_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UE static mesh component ÁöÁ¤
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DoorMesh;

	// between time about open and close
	UPROPERTY(EditAnywhere)
	float CloseTime;

	// how long time to open and close
	UPROPERTY(EditAnywhere)
	float DoorDeltaTime;

	// is open
	bool bOpen;

	FTimerHandle DoorTimerHandle;

	FRotator OriginRotation;

	void Open();

	void Close();

};
