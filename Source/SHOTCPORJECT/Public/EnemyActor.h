// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class SHOTCPORJECT_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// PseudoCode :충돌체와 몸을 갖고싶다.
	// PseudoCode : 태어날 때 방향을 만들고
	// // PseudoCode : 30 %확률로 목적지를 향하는 방향, 나머지 확률은 앞방향으로 
	// PseudoCode : 살아가면서 그 방향으로 이동하고 싶다.

	UPROPERTY(EditAnywhere)   //컴포넌트 만들기
		class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)   //컴포넌트 만들기
		class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	int randomRate = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	FVector direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)   // 속도
	float speed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)    //actor
	AActor* target;

};
