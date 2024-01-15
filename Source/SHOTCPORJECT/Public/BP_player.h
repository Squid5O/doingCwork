// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BP_player.generated.h"

UCLASS()
class SHOTCPORJECT_API ABP_player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABP_player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVar")
	// EditAnywhere �ϴ볪 �� �� ���� _detail,  BlueprintReadOnly �б⸸ ����, BlueprintReadWrite ���⵵ ����. 
	//  category �� �𸮾� ���� ����. 
	float speed = 500;

};
