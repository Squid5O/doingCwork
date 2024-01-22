// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOTCPORJECT_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	// - PseudoCode :  ui�� �����ϴ� �ؽ�Ʈ�� ���ڿ��� Score�� �ϰ�ʹ�
	void SetScoreText(int score);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TextScore; //���漱�� - �̸� Ʋ���� �ƿ� �ȉ� 

	UPROPERTY()
	class ABP_playerBase* gm;
};
