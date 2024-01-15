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
	////������ ������ �����     
	//FVector P0 = GetActorLocation();
	//	//�� �������� �̵��ϰ�ʹ�.
	//FVector v = GetActorRightVector() * speed;                  //v ��������
	//FVector vt = v * DeltaTime; // DeltaTime = deltaSecond
	//FVector newLoc = P0 + vt;
	//SetActorLocation(newLoc);   //���� �̵�

		//ȭ��ǥ �̵� 
	FVector P0 = GetActorLocation();
		//������� �Է� ������ ����ϰ� �ʹ�.
	FVector dir = FVector(0, h, v);
	dir.Normalize();

	FVector _v = dir * speed;                  //v ��������
	FVector vt = _v * DeltaTime; // DeltaTime = deltaSecond
	FVector newLoc = P0 + vt;
	SetActorLocation(newLoc);
	}

// Called to bind functionality to input
void ABP_player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ABP_player::OnMyAxisHorizontal);// ������ ���� , BindAxis - �����ε�

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ABP_player::OnMyAxisVertical);


}

void ABP_player::OnMyAxisHorizontal(float value)  //Ŭ������ ���� �ɹ� �Լ��� �̸� �� Ǯ���� "ABP_player::OnMyAxisHorizontal"
{
	h = value;
}

void ABP_player::OnMyAxisVertical(float value)
{
	v = value;
}

