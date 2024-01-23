// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UGameOverWidget::NativeConstruct()
{
	// 버튼을 누르면 동작하게 함수를 연결하고 싶다.
	Button_95->OnClicked.AddDynamic(this, &UGameOverWidget::OnMyRestart);

	Button->OnClicked.AddDynamic(this, &UGameOverWidget::onMyQuit);
}

void UGameOverWidget::OnMyRestart()
{
 // 현재 맵의 이름을 알고 싶다.
	FString mapName = UGameplayStatics::GetCurrentLevelName(GetWorld());
// 그 맵으로 다시 레벨을 재시작 하고 싶다.
	UGameplayStatics::OpenLevel(GetWorld(),FName(*mapName));
	
	/*
	this->RemoveFromParent();
	auto controller = GetWorld()->GetFirstPlayerController();
	controller->SetShowMouseCursor(false);
	controller->SetInputMode(FInputModeGameOnly());
	*/ //해도 되고 안해도됌
}

void UGameOverWidget::onMyQuit()
{
	auto controller = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), controller, EQuitPreference::Quit, false);
}
