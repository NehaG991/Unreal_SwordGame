// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "KwangCharacter.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			Main = Cast<AKwangCharacter>(Pawn);
		}
	}
}

void UMainAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.0f);
		MovementSpeed = LateralSpeed.Size();
		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
		
		// Setting yaw, pitch, and roll
		FRotator Rotation = Pawn->GetActorRotation();
		FRotator BaseAnimRotation = Pawn->GetBaseAimRotation();
		//FRotator Delta = UKismetMathLibrary::NormalizedDeltaRotator(Rotation, BaseAnimRotation);
		FRotator Delta = UKismetMathLibrary::NormalizedDeltaRotator(BaseAnimRotation, Rotation);
		UKismetMathLibrary::BreakRotator(Delta, Roll, Pitch, Yaw);

		// Getting YawDelta for lean
		Delta = UKismetMathLibrary::NormalizedDeltaRotator(Rotation, RotationLastFrame);
		float Target = Delta.Yaw / DeltaTime;
		float Interp = FMath::FInterpTo(YawDelta, Target, DeltaTime, 6.0f);
		YawDelta = FMath::Clamp(Interp, -90.0f, 90.0f);
		RotationLastFrame = Rotation; 


		if (Main == nullptr)
		{
			Main = Cast<AKwangCharacter>(Pawn);
		}

		if (Main)
		{
			if (Main->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0)
			{
				bIsAccelerating = true;
			}
			else
			{
				bIsAccelerating = false;
			}
		}
	}
}
