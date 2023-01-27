// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimTestCharacter.h"
#include <Engine/Classes/Camera/CameraComponent.h>
#include <Engine/Classes/Components/CapsuleComponent.h>
#include <Engine/classes/GameFrameWork/SpringArmComponent.h>

// Sets default values
AAnimTestCharacter::AAnimTestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TPSCameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPSCameraSpringArm"));
	TPSCameraSpringArmComponent->SetupAttachment(GetCapsuleComponent());
	TPSCameraSpringArmComponent->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight));
	TPSCameraSpringArmComponent->bUsePawnControlRotation = true;

	TPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TPSCamera"));
	TPSCameraComponent->SetupAttachment(TPSCameraSpringArmComponent, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void AAnimTestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimTestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAnimTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Move_X", this, &AAnimTestCharacter::MoveX);
	InputComponent->BindAxis("Move_Y", this, &AAnimTestCharacter::MoveY);
	InputComponent->BindAxis("Turn", this, &AAnimTestCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AAnimTestCharacter::AddControllerPitchInput);


}

void AAnimTestCharacter::MoveX(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}

void AAnimTestCharacter::MoveY(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}