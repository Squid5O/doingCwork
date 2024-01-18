// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BP_player.h"

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

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("enemy"));   // SetRootComponent create 한 이후에 쓰지 않으면 null 값에 들어가서 오류뜸

	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();


	// PseudoCode : 박스컴포넌트의 충동을 감지하고 싶다. 
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyActor::OnMyCompBeginOverLap); // 이거 불러서 박스 컴프 오버랩에 적용시켜줘



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

void AEnemyActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//너(OtherActor) 죽고
	//OtherActor->Destroy();
	 // 나(this )죽자
	;
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("AAAAAAA"));
}


void AEnemyActor::OnMyCompBeginOverLap(
	UPrimitiveComponent* OnComponentBeginOverlap,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("AAAAAAA")); // -1 은 무시하셈 , 문자만 출력
	GEngine->AddOnScreenDebugMessage(-1, 9, FColor::Green, FString::Printf(TEXT("OnMyCompBeginOverlap :: %s"), *OtherActor->GetName()));  //숫자 출력 
	//OtherActor->Destroy();
//	ABP_player* player = Cast<ABP_player>(OtherActor); 둘중 하나 쓰셈
	if (OtherActor->IsA<ABP_player>())   // isA 아더액터가 player라면~
	{

		// PseudoCode : 죽이기 전에 폭팔 소리 내버리쟈
		UGameplayStatics::PlaySound2D(GetWorld(), expSFX);
	// PseudoCode : 폭팔 VFX를 생성해서 배치
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), expVFX, GetActorLocation());

		OtherActor->Destroy();
		//너 죽고 나 죽자
		this->Destroy();
	}
}

