// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BP_playerBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOTCPORJECT_API ABP_playerBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override;

public: UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int score;

	UFUNCTION(BlueprintCallable)
	void AddScore(int value);

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> scoreUIFactory;

	UPROPERTY()
	class UScoreWidget* scoreUI;
};