// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void elevateBarrel(float degreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 20; // Sensible default, I guess

	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevation = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevation = 0;

protected:

};
