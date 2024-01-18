// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyActor.h"
#include "Kismet/GameplayStatics.h"

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
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABulletActor::OnMyCompBeginOverLap);
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

void ABulletActor::OnMyCompBeginOverLap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//ABP_player* player = Cast<ABP_player>(OtherActor);
	if (OtherActor->IsA<AEnemyActor>())   // isA �ƴ����Ͱ� player���~
	{
		UGameplayStatics::PlaySound2D(GetWorld(), expSFX2);

		OtherActor->Destroy();
		//�� �װ� �� ����
		this->Destroy();
	}

}

