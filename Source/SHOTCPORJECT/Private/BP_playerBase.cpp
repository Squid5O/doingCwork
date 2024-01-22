// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_playerBase.h"
#include "ScoreWidget.h"

void ABP_playerBase::BeginPlay()
{
	// - PseudoCode : 태어날 때 점수 위젯을 나오게 하고 싶다. 
	scoreUI = CreateWidget<UScoreWidget>(GetWorld(), scoreUIFactory);
	// - PseudoCode : 그 녀석을 화면에 보이게 하고 싶다.
	scoreUI->AddToViewport();
	scoreUI->SetScoreText(0);
}

void ABP_playerBase::AddScore(int value)
{
	score += value;
	scoreUI->SetScoreText(score); // UI한테 값을 밀어넣기
}
