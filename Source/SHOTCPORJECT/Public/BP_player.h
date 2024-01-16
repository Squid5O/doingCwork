// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BP_player.generated.h"

//class UStaticMeshComponent; // ���漱��_���� ����̸� �Ʒ���

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
	// EditAnywhere �ϴ볪 �� �� ���� _detail,  BlueprintReadOnly �б⸸ ����, BlueprintReadWrite ���⵵ ����. 
	//  category �� �𸮾� ���� ����. 
	float speed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVar")
	float h ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVar")
	float v; //�ʵ� ����

public : 
	// �Է¿� ���� �Լ�(�ݹ�)�� �����ϰ� �ʹ�.
	void OnMyAxisHorizontal(float value);
	void OnMyAxisVertical(float value);

public: 
	//���漱��(���)
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;//���� ������ //����Ʈ������?

		//���漱��(���)
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;//���� ������ //����Ʈ������?

	// ���콺 ���� ��ư�� ������ 
	// firePositon(Arrow)�� ��ġ�� BulletAcotr�� �����ؼ� ��ġ�ϰ� ����.

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePositon;

	void OnMyActionFirePressed();
	void OnMyActionFireReleased();

	UPROPERTY(EditAnywhere)
//	UClass* bulletFactory; // �ڵ������ؼ� ���丮 _ ��Ŭ���� ������ // �ٵ� UClass �� �ϸ� ��� Uclass ��� ���Ͱ� ���� Ƣ���
	TSubclassOf<class ABulletActor> bulletFactory;  // ABulletActor ����� �� �ҷ�����

};
