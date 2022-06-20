// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE_SWORD_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;


	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
		void UpdateAnimationProperties(float DeltaTime);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		float MovementSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		bool bIsInAir;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		bool bIsAccelerating;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class APawn* Pawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		class AKwangCharacter* Main;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		float YawDelta;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		FRotator RotationLastFrame;

	// CUSTOM STUFF NOT IN BOOK
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		float Yaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		float Pitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		float Roll;


};
