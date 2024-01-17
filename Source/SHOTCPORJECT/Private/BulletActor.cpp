// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//�浿ü�� �����ϰ� �ʹ�.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	//�浹ü�� ��Ʈ������Ʈ�� �ϰ� �ʹ�.
	this->SetRootComponent(boxComp);

	//���� �����ϰ� �ʹ�.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//���� �浹ü�� ���̰� �ʹ�. 
	MeshComp->SetupAttachment(RootComponent);  //boxComp �� ����


	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("bullet"));

	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector dir = GetActorForwardVector();

	FVector P0 = GetActorLocation();
	FVector vt = dir * speed * GetWorld()->GetDeltaSeconds();  //DeltaTime ��� ��� ����. GetWorld()->GetDeltaSeconds(); 

	SetActorLocation(P0 + vt);
}

