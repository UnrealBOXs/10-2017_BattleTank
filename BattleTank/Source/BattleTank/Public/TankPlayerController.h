// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//Start the tank movinf the barrel so that a shoy would it where 
	// the crosshair intersects the world
	virtual void AimTowardsCrosshair();
	bool GetsightRayhitLocation(FVector& OutHitLocation) const;
			
};
