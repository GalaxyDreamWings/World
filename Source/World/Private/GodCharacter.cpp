// Fill out your copyright notice in the Description page of Project Settings.


//#include "GodCharacter.h"   //默认生成的是这个头文件，但是路径不一样，分别位于Private和Public下
#include "World/Public/GodCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AGodCharacter::AGodCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_springArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	m_springArmComp->SetupAttachment(RootComponent);

	m_cameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	m_cameraComp->SetupAttachment(m_springArmComp);
	
	
}

// Called when the game starts or when spawned
void AGodCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGodCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(),value);
}

void AGodCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(),value);
}

// Called every frame
void AGodCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGodCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&AGodCharacter::MoveForward);

	PlayerInputComponent->BindAxis("MoveRight",this,&AGodCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis("LookUp",this,&APawn::AddControllerPitchInput);

}

