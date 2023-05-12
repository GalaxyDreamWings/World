// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GodCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class WORLD_API AGodCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGodCharacter();

protected:

    UPROPERTY(VisibleAnywhere)
	USpringArmComponent* m_springArmComp;

	UPROPERTY(VisibleAnywhere);
	UCameraComponent* m_cameraComp;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);

	void MoveRight(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
