// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyZoneActor.h"
#include "Components/BoxComponent.h"

// Sets default values
ADestroyZoneActor::ADestroyZoneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// PseudoCode : �ڽ� ������Ʈ�� ������ �ʹ�.
	boxComp2 = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp2")); // h �� �ۼ��Ѱ� ��������
	SetRootComponent(boxComp2);
	// PseudoCode : �ڽ� ������� 1���ͷ�!
	boxComp2->SetBoxExtent(FVector(0.5f));
	boxComp2->SetGenerateOverlapEvents(true);
	boxComp2->SetCollisionProfileName(TEXT("destroy"));

}

// Called when the game starts or when spawned
void ADestroyZoneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestroyZoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestroyZoneActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	OtherActor->Destroy();
}

