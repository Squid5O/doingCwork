// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMangerActor.h"
#include "Components/ArrowComponent.h"
#include "EnemyActor.h"

// Sets default values
AEnemyMangerActor::AEnemyMangerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// PseudoCode : arrowComp를 생성하고 싶다
	arrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("arrowComp"));
	arrowComp->SetupAttachment(RootComponent);
	arrowComp->SetWorldRotation(FRotator(-90, 0, 180));

	//(Pitch = -90, yaw = 0 , Roll = 180)
			// z     y       x
}

// Called when the game starts or when spawned
void AEnemyMangerActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle tHandle;
	GetWorld()->GetTimerManager().SetTimer(tHandle, this, &AEnemyMangerActor::MakeEnemy, makeTime , true);
	
}

// Called every frame
void AEnemyMangerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyMangerActor::MakeEnemy()
{
	GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, arrowComp->GetComponentTransform());
}

