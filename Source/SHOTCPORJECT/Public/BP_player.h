// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BP_player.generated.h"

//class UStaticMeshComponent; // 전방선언_정식 약식이면 아래로

UCLASS()
class SHOTCPORJECT_API ABP_player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABP_player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVar")
	// EditAnywhere 암대나 쓸 수 있음 _detail,  BlueprintReadOnly 읽기만 가능, BlueprintReadWrite 쓰기도 간으. 
	//  category 로 언리얼내 구분 가능. 
	float speed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVar")
	float h ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVar")
	float v; //필드 변수

public : 
	// 입력에 대한 함수(콜백)를 선언하고 싶다.
	void OnMyAxisHorizontal(float value);
	void OnMyAxisVertical(float value);

public: 
	//전방선언(약식)
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;//정적 포인터 //스마트포인터?

		//전방선언(약식)
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;//정적 포인터 //스마트포인터?

	// 마우스 왼쪽 버튼을 누르면 
	// firePositon(Arrow)의 위치에 BulletAcotr를 생성해서 배치하고 싶음.

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePositon;

	void OnMyActionFirePressed();
	void OnMyActionFireReleased();

	UPROPERTY(EditAnywhere)
//	UClass* bulletFactory; // 자동생성해서 팩토리 _ 유클래스 포인터 // 근데 UClass 로 하면 모든 Uclass 상속 액터가 전부 튀어나옴
	TSubclassOf<class ABulletActor> bulletFactory;  // ABulletActor 상속한 놈만 불러들임

};
