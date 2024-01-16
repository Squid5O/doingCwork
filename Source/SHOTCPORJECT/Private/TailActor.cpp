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
	MeshComp->SetupAttachment(RootComponent);   //this ��Ή�
}

// Called when the game starts or when spawned
void ATailActor::BeginPlay()
{
	Super::BeginPlay();

	//�¾�� ���ΰ��� ã�Ƽ�  target�� ��� �;��
	target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//target = GetWorld() - > GetFirstPlayerConroller() -> GetPawn    : �굵 �� (������)
	
}

// Called every frame
void ATailActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Ÿ�� ������ ���ؼ� �̵��ϰ� �ʹ�.
	
	FVector dir = target -> GetActorLocation() - this->GetActorLocation();
	//dir.Normalize(); // dir�� ���̸� 1�� ����� �ʹٴ�.   -  �Ʒ��� dir.GetSafeNormal() �̰� ��� �� �纻 ���� �Ŷ� ������
	FVector P0 = GetActorLocation();
	FVector vt = dir.GetSafeNormal() * speed * DeltaTime;
	SetActorLocation(P0 + vt);

	//*if(dir.Length() > 100000)
//	{}	�̰ǹ���?
}
	

