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
	// EditAnywhere 암대나 쓸 수 있음 _detail,  BlueprintReadOnly 읽기만 가능, BlueprintReadWrite 쓰기도 간으. 
	//  category 로 언리얼내 구분 가능. 
	float speed = 500;

};
