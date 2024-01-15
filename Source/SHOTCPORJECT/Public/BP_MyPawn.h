// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BP_MyPawn.generated.h"

UCLASS()
class SHOTCPORJECT_API ABP_MyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABP_MyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	int32 number = 0;
	float pi = 3.14f;
	bool isOK = true;
	FString myName = TEXT("ohjaweng");

};
