// Fill out your copyright notice in the Description page of Project Settings.


#include "KwangCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Animation/AnimInstance.h"

// Sets default values
AKwangCharacter::AKwangCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the Controller rotates. Let that just affect the camera 
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure Character Movement

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input
	//GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 300.0f, 0.0f); // at this rotation rate
}

// Called when the game starts or when spawned
void AKwangCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKwangCharacter::MoveForward(float value)
{

	if ((Controller != NULL) && (value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get Forward Vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AKwangCharacter::MoveRight(float value)
{

	if ((Controller != NULL) && (value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get Right Vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

// Called every frame
void AKwangCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//// Attack Method
//void AKwangCharacter::Attack()
//{
//	if (isAttacking)
//	{
//		return;
//	}
//
//	isAttacking = true;
//
//	// Plays Attack Montage A
//	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
//	if (AnimInstance && KwangAttackA)
//	{
//		AnimInstance->Montage_Play(KwangAttackA);
//	}

//}

// Called to bind functionality to input
void AKwangCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AKwangCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKwangCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	//PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AKwangCharacter::Attack);
}

