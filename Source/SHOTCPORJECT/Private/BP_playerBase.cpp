// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_playerBase.h"
#include "ScoreWidget.h"

void ABP_playerBase::BeginPlay()
{
	// - PseudoCode : �¾ �� ���� ������ ������ �ϰ� �ʹ�. 
	scoreUI = CreateWidget<UScoreWidget>(GetWorld(), scoreUIFactory);
	// - PseudoCode : �� �༮�� ȭ�鿡 ���̰� �ϰ� �ʹ�.
	scoreUI->AddToViewport();
	scoreUI->SetScoreText(0);
}

void ABP_playerBase::AddScore(int value)
{
	score += value;
	scoreUI->SetScoreText(score); // UI���� ���� �о�ֱ�
}
