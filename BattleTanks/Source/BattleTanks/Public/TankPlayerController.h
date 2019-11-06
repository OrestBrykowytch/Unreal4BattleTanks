// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// Variables
	UPROPERTY(EditAnywhere)
	float crosshairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
	float crosshairYLocation = 0.33333;


	// Functions
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool getSightRayHitLocation(FVector& outHitLocation) const; // Return out parameter, true if terrain is hit
	bool getLookDirection(FVector2D screenLocation, FVector& lookDirection) const;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
