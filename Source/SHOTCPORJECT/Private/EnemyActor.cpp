// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp")); // h 에 작성한거 가져오기
	this->SetRootComponent(boxComp);

	//MeshComp를 만들어서 붙이고 싶다. 
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);  //attach는 필요! 꼭 root일 필요는 없엉

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();



	// PseudoCode : 30 % 확률로 목적지를 향하는 방향, 나머지 확률로 앞방향.
	int32 randValue = FMath::RandRange(0, 9);
	//만약 그 값이 randdomeRate 보다 작다면 플레이어 방향. 그렇지 않다면 앞방향.

	if (randValue < randomRate) {

		//플레이어 방향
		target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		direction = target->GetActorLocation() - this->GetActorLocation();
		direction.Normalize();
	}
	//그렇지 않다면 
	else {
		// 앞방향
		direction = GetActorForwardVector();
	}


}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector P0 = this->GetActorLocation();
	FVector vt = direction * speed * DeltaTime; //방향 * 속력 * 시간

	SetActorLocation(P0 + vt);
}

