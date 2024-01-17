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

	//boxComp를 생성해서
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	//boxComp를 루트컴포넌트로 하고싶다.
	this->SetRootComponent(boxComp);



	//MeshComp를 만들어서 붙이고 싶다. 
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent); // boxComp 써두됌 (box안에 mesh가 들어가니까)
	//SetRootComponent() 나 자신을 붙일 때 사용?


	//충돌 설정
	 	boxComp->SetGenerateOverlapEvents(true);
		boxComp->SetCollisionProfileName(TEXT("player"));
	 //	boxComp->SetCollisionEnabled(ECollisionEnabled:: QueryAndPhysics);

		//boxComp->SetCollisionObjectType(ECollisionChannel::ECC_EngineTraceChannel1);
		//boxComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		//boxComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
	
		// PseudoCode : //몸의 충돌체는 NoCollision 시키고 싶다.'
		MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);





	//Arrow컴포넌트를 만들고 
	firePositon = CreateDefaultSubobject<UArrowComponent>(TEXT("firePositon"));
	// Root에 붙이고싶다.
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
	////오른쪽 방향을 만들고     
	//FVector P0 = GetActorLocation();
	//	//그 방향으로 이동하고싶다.
	//FVector v = GetActorRightVector() * speed;                  //v 지역변수
	//FVector vt = v * DeltaTime; // DeltaTime = deltaSecond
	//FVector newLoc = P0 + vt;
	//SetActorLocation(newLoc);   //우측 이동

		//화살표 이동 ? // 좌우위아래이동
	{
		//Pseudo Code(의사코드)
		//사용자의 입력을 받고	
		//그 입력값으로 방향을 만들고
		FVector dir = FVector(0, h, v);
		dir.Normalize();
		//그 방향으로 이동하고 싶다.
		FVector P0 = GetActorLocation();
		//	FVector _v = dir * speed;                  //v 지역변수
		FVector vt = dir * speed * DeltaTime; // DeltaTime = deltaSecond
		//FVector newLoc = P0 + vt;
		SetActorLocation(P0 + vt);
	}


	/*
	만약 isAutoFIre ture 라면
	시간이 흐르다가 current Time += DeltaSec
	 만약 발사시간이 되면
	MakeBUllet 함수를 호출하고 싶다.
	currentTIme = 0;
	*/

	if (isAutoFIre) {  // 0이 아니면 트루
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

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ABP_player::OnMyAxisHorizontal);// 포인터 변수 , BindAxis - 오버로딩

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ABP_player::OnMyAxisVertical);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ABP_player::OnMyActionFirePressed);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &ABP_player::OnMyActionFireReleased);

}

void ABP_player::OnMyAxisHorizontal(float value)  //클래스가 가진 맴버 함수의 이름 은 풀네임 "ABP_player::OnMyAxisHorizontal"
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
		//PseudoCode :총소리를 내고 싶다,
		UGameplayStatics::PlaySound2D(GetWorld(), fireSound);

		FTransform t = firePositon->GetComponentToWorld();
		// 총알을 만들어서 총귀위치에 배치하고 싶다.
		//GetWorld()->SpawnActor(ABulletActor::GetClass()) // (ABulletActor::GetClass() _ Uclass를 가져옴 전부 다 C++로 할때
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

	//PseudoCode :총소리를 내고 싶다,
	UGameplayStatics::PlaySound2D(GetWorld(), fireSound);

	FTransform t = firePositon->GetComponentToWorld();
	//PseudoCode :총알을 만들어서 총구위치에 배치하고 싶다.
	GetWorld()->SpawnActor<ABulletActor>(bulletFactory, t);

}

