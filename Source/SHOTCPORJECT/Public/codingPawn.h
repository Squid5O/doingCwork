// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "codingPawn.generated.h"

UCLASS()
class SHOTCPORJECT_API AcodingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AcodingPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	
	
public:
	///(Edit / Visible) + (Anywhere/ Defaults / Instance)
	UPROPERTY(VisibleAnyWhere)
	int32 number = 0;
	UPROPERTY(EditAnyWhere)
	float pi = 3.14f;
	UPROPERTY(EditAnyWhere)
	bool isOK = true;
	UPROPERTY(EditAnyWhere)
	FString myName = TEXT("ohjaweng");
};
