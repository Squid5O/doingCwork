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

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION()
	void OnMyCompBeginOverLap(
		UPrimitiveComponent* OnComponentBeginOverlap, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex,
		bool bFromSweep, 
		const FHitResult& SweepResult);

	/** Delegate for notification of end of overlap with a specific component */

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

	// PseudoCode :플레이어와 부딪히면 폭발 소리를 내고 싶다. 폭팔 이펙트도 생성해서 배치하고 싶다.
	UPROPERTY(EditAnywhere)
	class USoundBase* expSFX;

		UPROPERTY(EditAnywhere)
	class UParticleSystem* expVFX;

};
