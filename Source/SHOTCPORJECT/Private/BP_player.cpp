// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_player.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "BulletActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABP_player::ABP_player()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//boxComp�� �����ؼ�
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	//boxComp�� ��Ʈ������Ʈ�� �ϰ�ʹ�.
	this->SetRootComponent(boxComp);



	//MeshComp�� ���� ���̰� �ʹ�. 
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent); // boxComp ��Ή� (box�ȿ� mesh�� ���ϱ�)
	//SetRootComponent() �� �ڽ��� ���� �� ���?


	//�浹 ����
	 	boxComp->SetGenerateOverlapEvents(true);
		boxComp->SetCollisionProfileName(TEXT("player"));
	 //	boxComp->SetCollisionEnabled(ECollisionEnabled:: QueryAndPhysics);

		//boxComp->SetCollisionObjectType(ECollisionChannel::ECC_EngineTraceChannel1);
		//boxComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		//boxComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
	
		// PseudoCode : //���� �浹ü�� NoCollision ��Ű�� �ʹ�.'
		MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);





	//Arrow������Ʈ�� ����� 
	firePositon = CreateDefaultSubobject<UArrowComponent>(TEXT("firePositon"));
	// Root�� ���̰�ʹ�.
	firePositon->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void ABP_player::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABP_player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	////������ ������ �����     
	//FVector P0 = GetActorLocation();
	//	//�� �������� �̵��ϰ�ʹ�.
	//FVector v = GetActorRightVector() * speed;                  //v ��������
	//FVector vt = v * DeltaTime; // DeltaTime = deltaSecond
	//FVector newLoc = P0 + vt;
	//SetActorLocation(newLoc);   //���� �̵�

		//ȭ��ǥ �̵� ? // �¿����Ʒ��̵�
	{
		//Pseudo Code(�ǻ��ڵ�)
		//������� �Է��� �ް�	
		//�� �Է°����� ������ �����
		FVector dir = FVector(0, h, v);
		dir.Normalize();
		//�� �������� �̵��ϰ� �ʹ�.
		FVector P0 = GetActorLocation();
		//	FVector _v = dir * speed;                  //v ��������
		FVector vt = dir * speed * DeltaTime; // DeltaTime = deltaSecond
		//FVector newLoc = P0 + vt;
		SetActorLocation(P0 + vt);
	}


	/*
	���� isAutoFIre ture ���
	�ð��� �帣�ٰ� current Time += DeltaSec
	 ���� �߻�ð��� �Ǹ�
	MakeBUllet �Լ��� ȣ���ϰ� �ʹ�.
	currentTIme = 0;
	*/

	if (isAutoFIre) {  // 0�� �ƴϸ� Ʈ��
		//int a = 1
		//if(a)     true
		currentTime += DeltaTime;
		if (currentTime >= fireTime) {
			MakeBullet();
			currentTime = 0;
		}
	}

}

// Called to bind functionality to input
void ABP_player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ABP_player::OnMyAxisHorizontal);// ������ ���� , BindAxis - �����ε�

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ABP_player::OnMyAxisVertical);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ABP_player::OnMyActionFirePressed);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &ABP_player::OnMyActionFireReleased);

}

void ABP_player::OnMyAxisHorizontal(float value)  //Ŭ������ ���� �ɹ� �Լ��� �̸� �� Ǯ���� "ABP_player::OnMyAxisHorizontal"
{
	h = value;
}

void ABP_player::OnMyAxisVertical(float value)
{
	v = value;
}

void ABP_player::OnMyActionFirePressed()
{
	/*
		//PseudoCode :�ѼҸ��� ���� �ʹ�,
		UGameplayStatics::PlaySound2D(GetWorld(), fireSound);

		FTransform t = firePositon->GetComponentToWorld();
		// �Ѿ��� ���� �ѱ���ġ�� ��ġ�ϰ� �ʹ�.
		//GetWorld()->SpawnActor(ABulletActor::GetClass()) // (ABulletActor::GetClass() _ Uclass�� ������ ���� �� C++�� �Ҷ�
		GetWorld()->SpawnActor<ABulletActor>(bulletFactory, t);


	*/

	isAutoFIre = true;
	MakeBullet();
}

void ABP_player::OnMyActionFireReleased()
{
	isAutoFIre = false;
	currentTime = 0;
}

void ABP_player::MakeBullet()
{

	//PseudoCode :�ѼҸ��� ���� �ʹ�,
	UGameplayStatics::PlaySound2D(GetWorld(), fireSound);

	FTransform t = firePositon->GetComponentToWorld();
	//PseudoCode :�Ѿ��� ���� �ѱ���ġ�� ��ġ�ϰ� �ʹ�.
	GetWorld()->SpawnActor<ABulletActor>(bulletFactory, t);

}

