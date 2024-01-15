// Fill out your copyright notice in the Description page of Project Settings.


#include "codingPawn.h"

// Sets default values
AcodingPawn::AcodingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcodingPawn::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello World!!"));

	UE_LOG(LogTemp, Warning, TEXT("number : %d, pi : %f"), number, pi);

	UE_LOG(LogTemp, Warning, TEXT("isOK : %d"), isOK); //false 0 �ƴϸ� �� true

	UE_LOG(LogTemp, Warning, TEXT("myName : %s"), *myName);  // ������ �ּ� ��
	
	//���ǹ� �ݺ��� FOR(;;){}
	//�迭

	TArray<int> ta;
	ta.Add(0);
	ta.Add(10);
	
	if (false == ta.Contains(10))
	{
		ta.Add(10);
	}
	//ta.Remove(10);
	ta.RemoveAt(1);  //���� 10 ���� �̰� ����
/*
	for (int i = 0; ta.Num(); i++) {
		ta[i] = i;
	}*/





	TMap<FString, int> userLevelInfo; //key ���ڿ�, �� ����
	userLevelInfo.Add(TEXT("ȫ�浿"), 10);
	userLevelInfo.Add(TEXT("ȫ�浿"), 50);

	userLevelInfo[TEXT("ȫ�浿")] = 20;

	for (auto item : userLevelInfo) {
		FString _Key = item.Key;
		auto _Value = item.Value;
	}
}

// Called every frame
void AcodingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AcodingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

