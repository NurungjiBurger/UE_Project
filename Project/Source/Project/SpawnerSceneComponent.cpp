// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerSceneComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
USpawnerSceneComponent::USpawnerSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	// CreateDefaultSubobject 는 생성자에서만 사용할 수 있는 함수이며 TICK 이나 다른 함수안에서 이를 수행하고자한다면 다른 방법을 사용해야함.
	for(int i = 0; i < 3; i++)
	{
		// 생성시 이름이 같으면 에러가 발생하므로 i 넘버링을 통해 이를 예방
		UStaticMeshComponent* Child = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Child"), i));
		Child->SetupAttachment(this);
		ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
		if (MeshAsset.Succeeded())
		{
			UE_LOG(LogTemp, Error, TEXT("실행은 됨"));
			Child->SetStaticMesh(MeshAsset.Object);
		}
		while(Mesh == NULL)
		Child->SetStaticMesh(Mesh);
		float radian = (2.0f * PI) / 3.0f;
		radian *= i;
		FVector Location = FVector(FMath::Cos(radian), FMath::Sin(radian), 0.0f) * 100.0f;
		Child->SetRelativeLocation(Location);
		Childs.Add(Child);
	}

	DestroyTimer = 3.0f;
}



// Called when the game starts
void USpawnerSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnerSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	DestroyTimer -= DeltaTime;
	if (DestroyTimer < 0.0f)
	{
		for(int i = 0; i < Childs.Num(); i++)
		{
			Childs[i]->DestroyComponent();
		}
		DestroyComponent();
	}
}

