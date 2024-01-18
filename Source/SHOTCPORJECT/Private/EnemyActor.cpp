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

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp")); // h �� �ۼ��Ѱ� ��������
	this->SetRootComponent(boxComp);

	//MeshComp�� ���� ���̰� �ʹ�. 
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);  //attach�� �ʿ�! �� root�� �ʿ�� ����

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("enemy"));   // SetRootComponent create �� ���Ŀ� ���� ������ null ���� ���� ������

	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();


	// PseudoCode : �ڽ�������Ʈ�� �浿�� �����ϰ� �ʹ�. 
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyActor::OnMyCompBeginOverLap); // �̰� �ҷ��� �ڽ� ���� �������� ���������



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

void AEnemyActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//��(OtherActor) �װ�
	//OtherActor->Destroy();
	 // ��(this )����
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
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("AAAAAAA")); // -1 �� �����ϼ� , ���ڸ� ���
	GEngine->AddOnScreenDebugMessage(-1, 9, FColor::Green, FString::Printf(TEXT("OnMyCompBeginOverlap :: %s"), *OtherActor->GetName()));  //���� ��� 
	//OtherActor->Destroy();
//	ABP_player* player = Cast<ABP_player>(OtherActor); ���� �ϳ� ����
	if (OtherActor->IsA<ABP_player>())   // isA �ƴ����Ͱ� player���~
	{

		// PseudoCode : ���̱� ���� ���� �Ҹ� ��������
		UGameplayStatics::PlaySound2D(GetWorld(), expSFX);
	// PseudoCode : ���� VFX�� �����ؼ� ��ġ
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), expVFX, GetActorLocation());

		OtherActor->Destroy();
		//�� �װ� �� ����
		this->Destroy();
	}
}

