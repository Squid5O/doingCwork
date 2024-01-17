// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//충동체를 생성하고 싶다.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	//충돌체를 루트컴포넌트로 하고 싶다.
	this->SetRootComponent(boxComp);

	//몸을 생성하고 싶다.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//몸을 충돌체에 붙이고 싶다. 
	MeshComp->SetupAttachment(RootComponent);  //boxComp 도 가능


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
	FVector vt = dir * speed * GetWorld()->GetDeltaSeconds();  //DeltaTime 대신 사용 가능. GetWorld()->GetDeltaSeconds(); 

	SetActorLocation(P0 + vt);
}

