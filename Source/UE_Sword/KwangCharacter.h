// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KwangCharacter.generated.h"

UCLASS()
class UE_SWORD_API AKwangCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKwangCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Forwards/Backwards Input
	void MoveForward(float value);

	// Right/Left Input
	void MoveRight(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Custom
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attack")
		bool isAttacking;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attack")
		bool saveAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attack")
		int attackNumber;


	//void Attack();

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Anims")
	//	class UAnimMontage* KwangAttackA;

};
