// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Components/TextBlock.h"
#include "BP_playerBase.h"

void UScoreWidget::NativeConstruct()
{
	//게임 모드를 가져와서 기억하고 싶다.
	auto gmb = GetWorld()->GetAuthGameMode();
	gm = Cast<ABP_playerBase>(gmb);
}

void UScoreWidget::SetScoreText(int score)
{
	TextScore->SetText(FText::AsNumber(score));
}
