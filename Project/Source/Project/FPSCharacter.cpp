// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include <Engine/Classes/Components/CapsuleComponent.h>

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());
	// 카메라의 위치를 캐릭터의 눈 위치보다 살짝 높게 잡고 폰이 카메라 로테이션을 제어하도록 함.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0 + BaseEyeHeight));
	FPSCameraComponent->bUsePawnControlRotation = true;

	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	// 해당 메시의 소유자만 메시를 볼 수 있음.
	FPSMesh->SetOnlyOwnerSee(true);
	FPSMesh->SetupAttachment(FPSCameraComponent);
	// 그림자를 그리지 않도록 설정.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	// 3인칭 메시를 불러와서 소유자는 3인칭 메시를 볼 수 없게 만듬.
	GetMesh()->SetOwnerNoSee(true);

	if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hello Start, this is FPS Character Class"));
    }
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &AFPSCharacter::MoveX);
	InputComponent->BindAxis("MoveY", this, &AFPSCharacter::MoveY);

	// 플레이어의 마우스에 따른 카메라 회전은 필수함수로 제공되고 있어서 MoveX 처럼 구현할 필요가 없음.
	InputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);


	InputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);

	InputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::MoveX(float AxisValue)
{
	// 캐릭터의 동작축을 카메라에 상대적으로 만들어줌. 이를 위해 PlayerController 사용하며 입력을 XY 면으로 제한시켜 위나 아래를 보더라도 땅과 평행으로 움직일 수 있게 구현. 
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, AxisValue);
}

void AFPSCharacter::MoveY(float AxisValue)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, AxisValue);
}

void AFPSCharacter::StartJump()
{
	// 마우스 입력이 이미 구현되어 있는것처럼 캐릭터의 점프가 bPressedJump 변수에 묶여있음.
	bPressedJump = true;
}

void AFPSCharacter::StopJump()
{
	bPressedJump = false;
}

void AFPSCharacter::Fire()
{
	if (ProjectileClass)
	{
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

		UWorld* World = GetWorld();
		if (World)
		{
			// 카메라의 위치와 방향을 구함.
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// 카메라의 위치와 방향을 통해 발사체가 생성될 위치를 구함.
			AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// 발사체 생성 및 발사
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}