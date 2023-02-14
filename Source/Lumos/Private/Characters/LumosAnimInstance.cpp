// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/LumosAnimInstance.h"
#include "Characters/LumosCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void ULumosAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	LumosCharacter = Cast<ALumosCharacter>(TryGetPawnOwner());
	if (LumosCharacter)
	{
		LumosCharacterMovement = LumosCharacter->GetCharacterMovement();
	}
}

void ULumosAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (LumosCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(LumosCharacterMovement->Velocity);
		IsFalling = LumosCharacterMovement->IsFalling();
		CharacterState = LumosCharacter->GetCharacterState();
	}
}
