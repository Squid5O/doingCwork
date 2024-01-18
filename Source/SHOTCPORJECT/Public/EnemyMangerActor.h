// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyMangerActor.generated.h"

UCLASS()
class SHOTCPORJECT_API AEnemyMangerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyMangerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere)
	class UArrowComponent* arrowComp;

	UPROPERTY(EditAnywhere)
	float makeTime = 2;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemyActor> enemyFactory;

	void MakeEnemy();
};
