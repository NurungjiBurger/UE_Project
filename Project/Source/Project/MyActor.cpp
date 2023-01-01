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

	// UE ��ũ�� ( �α�ī�װ�, �α� ����, �α׸޽��� )
	
	// �α� ī�װ� ( � �ý��ۿ��� �߻��� �α��ΰ�? )
	// UE�� �⺻������ 90�� �̻��� �α� ī�װ��� ���������� �ʿ��Ѱ� ���� ��� ���� �����ؼ� ���
	// ���� �����ϱ� ���ؼ��� �ش� ������Ʈ�� ������Ͽ��� �����ϰ� CPP ���Ͽ����� DEFINE ���ָ��.
	// DECLARE_LOG_CATEGORY_EXTERN( ������ �α� ī�װ� �̸� , �α� ���� ����, ������ Ÿ�ӿ����� �α� ���� ���� ) 
	// DEFINE_LOG_CATEGORY( ������ �α� ī�װ� �̸� );
	// ���������� �ش� �α׸� ����� ���Ͽ� ������Ʈ ����� ��Ŭ����ؼ� ����ϸ� ��.
	
	// �α� ���� ( �α��� �߿䵵, ������� )
	// Fatal :: �ܼ� �� �α� ���� O, �αװ� ��Ȱ��ȭ �� ���¿����� ��� �۵� �ߴ�
	// Error :: �ܼ� �� �α� ���� O, ������
	// Warning :: �ܼ� �� �α� ���� O, �����
	// Display :: �ܼ� �� �α� ���� O
	// Log :: �ܼ� x �α����� O, UE �������� ��� �α� �гο����� ���
	// Verbose :: �ܼ� x �α����� O, �ڼ��� �α� �� ������
	// VeryVerbose :: �ܼ� X �α����� O, �뷮 �α׸� ���� ���� �α�

	UE_LOG(LogTemp, Error, TEXT("Error Message"));
	UE_LOG(LogTemp, Warning, TEXT("Warning Message"));
	UE_LOG(LogTemp, Display, TEXT("Display Message"));

	UE_LOG(MyLogCategory, Log, TEXT("My Category Log"));

	// ��Ʈ�� ������� ������Ÿ������ �־��־���� ( %s �� TChar* �� ����. �̴� *FStirng�� ������ )
	FString CharacterName = TEXT("HiWer");
	UE_LOG(LogTemp, Log, TEXT("Charcater Name = %s"), *CharacterName);

	// �� Ÿ���� ��� �����ڰ� ���� ���� ������ ���� �����ڸ� �̿��� ���� TEXT�� �־��־����
	bool isAttackalbe = true;
	UE_LOG(LogTemp, Log, TEXT("IS Attackable = %s"), isAttackalbe ? TEXT("true") : TEXT("false"));
	int hp = 100;
	UE_LOG(LogTemp, Log, TEXT("HP = %d"), hp);
	float AttackSpeed = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("Attack Speed = %f"), AttackSpeed);

	// ������ ��� �����Լ����� �ִ� ����Ʈ���� Ȱ���� %s �� ���� �̶��� �����ͻ�� �ʼ�
	FVector CharacterPosition = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("Position = %s"), *CharacterPosition.ToString());

	// �ѹ��� ����غ���
	UE_LOG(LogTemp, Log, TEXT("Character Name = %s, HP = %d, Attack Speed = %f, Position = %s, is Attackable = %s"), *CharacterName, hp, AttackSpeed, *CharacterPosition.ToString(), isAttackalbe ? TEXT("true") : TEXT("false"));
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

