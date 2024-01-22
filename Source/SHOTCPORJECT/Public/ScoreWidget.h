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
	// - PseudoCode :  ui에 존재하는 텍스트의 문자열을 Score로 하고싶다
	void SetScoreText(int score);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TextScore; //전방선언 - 이름 틀리면 아예 안됌 

	UPROPERTY()
	class ABP_playerBase* gm;
};
