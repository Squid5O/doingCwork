// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class SHOTCPORJECT_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// PseudoCode : �Ѿ˰� �ε����� ���װ� ���װ� �ϱ��ʹ�.

		UFUNCTION()
	void OnMyCompBeginOverLap(
		UPrimitiveComponent* OnComponentBeginOverlap, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex,
		bool bFromSweep, 
		const FHitResult& SweepResult);


	//�浹ü�� ��(StaticMeshComp)�� ���� �ʹ�.
	// �չ������� ��� �̵��ϰ� �ʹ�. forwardvaceter spped 

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)   // �ӵ�
		float speed = 1000;

	UPROPERTY(EditAnywhere)
	class USoundBase* expSFX2;


};
