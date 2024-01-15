// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_MyPawn.h"

// Sets default values
ABP_MyPawn::ABP_MyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABP_MyPawn::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello World!!"));

	UE_LOG(LogTemp, Warning, TEXT("number : %d, pi : %f"), number, pi);

	UE_LOG(LogTemp, Warning, TEXT("isOK : %d"), isOK); //false 0 아니면 다 true

	UE_LOG(LogTemp, Warning, TEXT("myName : %s"), *myName);  // 포인터 주소 값

	
}

// Called every frame
void ABP_MyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABP_MyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

