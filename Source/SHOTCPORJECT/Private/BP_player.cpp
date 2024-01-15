// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_player.h"

// Sets default values
ABP_player::ABP_player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABP_player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//오른쪽 방향을 만들고 
	FVector P0 = GetActorLocation();
		//그 방향으로 이동하고싶다.
	FVector v = GetActorRightVector() * speed;
	FVector vt = v * DeltaTime; // DeltaTime = deltaSecond
	FVector newLoc = P0 + vt;
	SetActorLocation(newLoc);
	}

// Called to bind functionality to input
void ABP_player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

