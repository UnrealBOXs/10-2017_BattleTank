// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIConTroller can't find playertank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIConTroller found player : %s"), *(PlayerTank->GetName()));

	}
	

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn =	GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}
 void ATankAIController::Tick(float DeltaTime) {
	 Super::Tick(DeltaTime);
	 if (GetPlayerTank()) {
		 //ToDO Move Towards the player 
		 //Aim Towards the player 
		 GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	 }

}
