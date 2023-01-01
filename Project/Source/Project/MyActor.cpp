// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Project.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// UE 매크로 ( 로그카테고리, 로그 상태, 로그메시지 )
	
	// 로그 카테고리 ( 어떤 시스템에서 발생한 로그인가? )
	// UE는 기본적으로 90개 이상의 로그 카테고리를 제공하지만 필요한게 없을 경우 직접 선언해서 사용
	// 직접 선언하기 위해서는 해당 프로젝트의 헤더파일에서 선언하고 CPP 파일에서는 DEFINE 해주면됨.
	// DECLARE_LOG_CATEGORY_EXTERN( 생성할 로그 카테고리 이름 , 로그 상태 수준, 컴파일 타임에서의 로그 상태 수준 ) 
	// DEFINE_LOG_CATEGORY( 생성할 로그 카테고리 이름 );
	// 최종적으로 해당 로그를 사용할 파일에 프로젝트 헤더를 인클루드해서 사용하면 됨.
	
	// 로그 상태 ( 로그의 중요도, 위험수준 )
	// Fatal :: 콘솔 및 로그 파일 O, 로그가 비활성화 된 상태에서도 모든 작동 중단
	// Error :: 콘솔 및 로그 파일 O, 빨간색
	// Warning :: 콘솔 및 로그 파일 O, 노란색
	// Display :: 콘솔 및 로그 파일 O
	// Log :: 콘솔 x 로그파일 O, UE 에디터의 출력 로그 패널에서는 출력
	// Verbose :: 콘솔 x 로그파일 O, 자세한 로깅 및 디버깅용
	// VeryVerbose :: 콘솔 X 로그파일 O, 대량 로그를 통한 상세한 로깅

	UE_LOG(LogTemp, Error, TEXT("Error Message"));
	UE_LOG(LogTemp, Warning, TEXT("Warning Message"));
	UE_LOG(LogTemp, Display, TEXT("Display Message"));

	UE_LOG(MyLogCategory, Log, TEXT("My Category Log"));

	// 스트링 같은경우 포인터타입으로 넣어주어야함 ( %s 가 TChar* 를 받음. 이는 *FStirng에 대응함 )
	FString CharacterName = TEXT("HiWer");
	UE_LOG(LogTemp, Log, TEXT("Charcater Name = %s"), *CharacterName);

	// 불 타입의 경우 지정자가 따로 없기 때문에 삼항 연산자를 이용해 직접 TEXT를 넣어주어야함
	bool isAttackalbe = true;
	UE_LOG(LogTemp, Log, TEXT("IS Attackable = %s"), isAttackalbe ? TEXT("true") : TEXT("false"));
	int hp = 100;
	UE_LOG(LogTemp, Log, TEXT("HP = %d"), hp);
	float AttackSpeed = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("Attack Speed = %f"), AttackSpeed);

	// 벡터의 경우 벡터함수내에 있는 투스트링을 활용해 %s 에 대응 이때도 포인터사용 필수
	FVector CharacterPosition = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("Position = %s"), *CharacterPosition.ToString());

	// 한번에 출력해보기
	UE_LOG(LogTemp, Log, TEXT("Character Name = %s, HP = %d, Attack Speed = %f, Position = %s, is Attackable = %s"), *CharacterName, hp, AttackSpeed, *CharacterPosition.ToString(), isAttackalbe ? TEXT("true") : TEXT("false"));
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

