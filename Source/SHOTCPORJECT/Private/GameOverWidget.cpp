// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UGameOverWidget::NativeConstruct()
{
	// ��ư�� ������ �����ϰ� �Լ��� �����ϰ� �ʹ�.
	Button_95->OnClicked.AddDynamic(this, &UGameOverWidget::OnMyRestart);

	Button->OnClicked.AddDynamic(this, &UGameOverWidget::onMyQuit);
}

void UGameOverWidget::OnMyRestart()
{
 // ���� ���� �̸��� �˰� �ʹ�.
	FString mapName = UGameplayStatics::GetCurrentLevelName(GetWorld());
// �� ������ �ٽ� ������ ����� �ϰ� �ʹ�.
	UGameplayStatics::OpenLevel(GetWorld(),FName(*mapName));
	
	/*
	this->RemoveFromParent();
	auto controller = GetWorld()->GetFirstPlayerController();
	controller->SetShowMouseCursor(false);
	controller->SetInputMode(FInputModeGameOnly());
	*/ //�ص� �ǰ� ���ص���
}

void UGameOverWidget::onMyQuit()
{
	auto controller = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), controller, EQuitPreference::Quit, false);
}
