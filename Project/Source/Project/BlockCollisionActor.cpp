// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockCollisionActor.h"

// Sets default values
ABlockCollisionActor::ABlockCollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	RootComponent = BoxMesh;
}

// Called when the game starts or when spawned
void ABlockCollisionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlockCollisionActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Log, TEXT("NotifyHit"));
}

// Called every frame
void ABlockCollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Collision 감지를 위해서는 감지하기 위한 함수들을 오버라이딩 해줘야함
// 블록의 경우 -> NotifyHit
// 오버랩의 경우 -> NotifyActorBeginOverlap & NotifyActorEndOverlap

// Collision 종류
// 블록 - 콜리젼이 블록으로 설정된 두 오브젝트의 충돌. 오브젝트가 서로의 이동을 불가능하게 만듬. ( Simulation Generates Hit Event 프로퍼티를 true 로 설정해 블록 충돌을 트리거로 사용 가능 )
// 겹침 - 다른 오브젝트를 통과시키는게 기본이지만 콜리젼 옵션에서 Generate Overlap Events 프로퍼티가 활성화된 상태라면 Overlap Event를 발생시킴. 해당 이벤트가 발생하기 위해서는 두 오브젝트의 콜리젼이 모두 겹침 이상으로 설정 되어 있어야함.
// 무시 - 모든 오브젝트와 트레이스를 통과시키고 어떠한 이벤트도 발생시키지 않음.

// editor details
// 모빌리티 -> 무버블 / 피직스 -> Simulate Physics  떨어지는 물체 구현 가능 했음.
// 위의 Generate Hit event 같은 프로퍼티들은 해당 오브젝트의 메쉬 디테일 패널의 콜리젼 파트에서 찾을 수 있음.
// 콜리젼 파트에서 블록 이벤트를 감지할지 오버랩 이벤트를 감지할지 설정할 수 있으며 콜리젼 프리셋도 설정 가능 ( 프리셋 설정 시 다른 모든 오브젝트와의 관계가 프리셋대로 설정 )
// 의문 -> 분명 블록 이벤트의 경우 두 오브젝트가 true 가 아니어도 감지가 되는데 겹침 이벤트는 무조건 두 오브젝트가 true 이어야 함. 위에랑 말이 다른데?
