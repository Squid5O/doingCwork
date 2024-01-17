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

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp")); // h �� �ۼ��Ѱ� ��������
	this->SetRootComponent(boxComp);

	//MeshComp�� ���� ���̰� �ʹ�. 
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);  //attach�� �ʿ�! �� root�� �ʿ�� ����

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();



	// PseudoCode : 30 % Ȯ���� �������� ���ϴ� ����, ������ Ȯ���� �չ���.
	int32 randValue = FMath::RandRange(0, 9);
	//���� �� ���� randdomeRate ���� �۴ٸ� �÷��̾� ����. �׷��� �ʴٸ� �չ���.

	if (randValue < randomRate) {

		//�÷��̾� ����
		target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		direction = target->GetActorLocation() - this->GetActorLocation();
		direction.Normalize();
	}
	//�׷��� �ʴٸ� 
	else {
		// �չ���
		direction = GetActorForwardVector();
	}


}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector P0 = this->GetActorLocation();
	FVector vt = direction * speed * DeltaTime; //���� * �ӷ� * �ð�

	SetActorLocation(P0 + vt);
}

