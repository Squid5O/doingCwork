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

	UE_LOG(LogTemp, Warning, TEXT("isOK : %d"), isOK); //false 0 아니면 다 true

	UE_LOG(LogTemp, Warning, TEXT("myName : %s"), *myName);  // 포인터 주소 값
	
	//조건문 반복문 FOR(;;){}
	//배열

	TArray<int> ta;
	ta.Add(0);
	ta.Add(10);
	
	if (false == ta.Contains(10))
	{
		ta.Add(10);
	}
	//ta.Remove(10);
	ta.RemoveAt(1);  //예도 10 지움 이건 순서
/*
	for (int i = 0; ta.Num(); i++) {
		ta[i] = i;
	}*/





	TMap<FString, int> userLevelInfo; //key 문자열, 값 정수
	userLevelInfo.Add(TEXT("홍길동"), 10);
	userLevelInfo.Add(TEXT("홍길동"), 50);

	userLevelInfo[TEXT("홍길동")] = 20;

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

