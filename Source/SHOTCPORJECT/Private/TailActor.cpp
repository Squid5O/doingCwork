// Fill out your copyright notice in the Description page of Project Settings.


#include "TailActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATailActor::ATailActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);   //this 써두됌
}

// Called when the game starts or when spawned
void ATailActor::BeginPlay()
{
	Super::BeginPlay();

	//태어날때 주인공을 찾아서  target에 담고 싶어욤
	target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//target = GetWorld() - > GetFirstPlayerConroller() -> GetPawn    : 얘도 됌 (포세스)
	
}

// Called every frame
void ATailActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//타겟 방향을 향해서 이동하고 싶다.
	
	FVector dir = target -> GetActorLocation() - this->GetActorLocation();
	//dir.Normalize(); // dir의 길이를 1로 만들고 싶다능.   -  아래에 dir.GetSafeNormal() 이거 써두 됨 사본 쓰는 거라 세이프
	FVector P0 = GetActorLocation();
	FVector vt = dir.GetSafeNormal() * speed * DeltaTime;
	SetActorLocation(P0 + vt);

	//*if(dir.Length() > 100000)
//	{}	이건뭐임?
}
	

