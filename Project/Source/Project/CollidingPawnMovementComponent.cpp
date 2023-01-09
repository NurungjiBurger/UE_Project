// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawnMovementComponent.h"

void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // PawnOwner -> 현재 이 컴포넌트를 소유하고 있는 폰
    // UpdatedComponent -> 현재 클래스의 부모 클래스에 속하는 변수로 이 컴포넌트가 이동시키고 업데이트해야할 대상 컴포넌트
    // ShouldSkipUpdate -> 이동된 컴포넌트가 이동할 수 없거나 렌더링 되지 않은 경우인지 판별하여 알려주는 함수

    // 위 세가지를 활용해 현재 컴포넌트가 이동가능한 상태인지 판별
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    // ConsumeInputVector -> 입력된 이동 벡터를 가져옴
    // SafeMoveUpdatedComponent -> UE 피직스를 이용해 장애물을 피해서 컴포넌트를 이동시킴
    // 충돌이 발생한다면 -> SlideAlongSurface -> 제자리에 멈추지 않고 표면을 따라 미끄러지듯이 이동하도록 함.

    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

        if (Hit.IsValidBlockingHit())
        {
            SlideAlongSurface(DesiredMovementThisFrame, 1.0f - Hit.Time, Hit.Normal, Hit);
        }
    }
}

