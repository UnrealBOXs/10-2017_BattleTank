// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController processing %s"), *ControlledTank ->GetName());
	}
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank())
	{
		return;
	}
	FVector Hitlocation;
	if (GetsightRayhitLocation(Hitlocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation : %s"), *Hitlocation.ToString());

		
		//if it hits the landscape 
		//Tell controlled tank to aim at this point 
	}
	
	
}
//Get world location if linetrace theough crosshair  
bool ATankPlayerController::GetsightRayhitLocation(FVector& OutHitLocation) const {
	OutHitLocation = FVector(1.0);
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX *CrosshairXLocation, ViewportSizeY *CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation : %s"), *ScreenLocation.ToString());
	//"De- project" the screen position of the crosshait to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Look direction : %s"), *LookDirection.ToString());
	}
	
	//line-trace along that look direction, and see what we hit (up to max range)
		return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}