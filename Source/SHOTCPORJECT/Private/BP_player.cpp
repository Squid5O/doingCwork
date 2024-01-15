// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_player.h"

// Sets default values
ABP_player::ABP_player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

		//화살표 이동 
	FVector P0 = GetActorLocation();
		//사용자의 입력 방향을 기억하고 싶다.
	FVector dir = FVector(0, h, v);
	dir.Normalize();

	FVector _v = dir * speed;                  //v 지역변수
	FVector vt = _v * DeltaTime; // DeltaTime = deltaSecond
	FVector newLoc = P0 + vt;
	SetActorLocation(newLoc);
	}

// Called to bind functionality to input
void ABP_player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ABP_player::OnMyAxisHorizontal);// 포인터 변수 , BindAxis - 오버로딩

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ABP_player::OnMyAxisVertical);


}

void ABP_player::OnMyAxisHorizontal(float value)  //클래스가 가진 맴버 함수의 이름 은 풀네임 "ABP_player::OnMyAxisHorizontal"
{
	h = value;
}

void ABP_player::OnMyAxisVertical(float value)
{
	v = value;
}

