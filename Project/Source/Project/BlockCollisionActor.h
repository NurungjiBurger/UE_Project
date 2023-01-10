// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockCollisionActor.generated.h"

UCLASS()
class PROJECT_API ABlockCollisionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockCollisionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 상속받은 함수를 만듦으로써 개발자가 원하는 동작을 처리하도록 하기 위해 선언해주어야만 함.
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere) UStaticMeshComponent* BoxMesh;

};
