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
	// PseudoCode :�浹ü�� ���� ����ʹ�.
	// PseudoCode : �¾ �� ������ �����
	// // PseudoCode : 30 %Ȯ���� �������� ���ϴ� ����, ������ Ȯ���� �չ������� 
	// PseudoCode : ��ư��鼭 �� �������� �̵��ϰ� �ʹ�.

	UPROPERTY(EditAnywhere)   //������Ʈ �����
		class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)   //������Ʈ �����
		class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	int randomRate = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	FVector direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)   // �ӵ�
	float speed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)    //actor
	AActor* target;

	// PseudoCode :�÷��̾�� �ε����� ���� �Ҹ��� ���� �ʹ�. ���� ����Ʈ�� �����ؼ� ��ġ�ϰ� �ʹ�.
	UPROPERTY(EditAnywhere)
	class USoundBase* expSFX;

		UPROPERTY(EditAnywhere)
	class UParticleSystem* expVFX;

};
