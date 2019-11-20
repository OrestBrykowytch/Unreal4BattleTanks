#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


class UTankBarrel; // Forward Declaration


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	UTankBarrel* barrel = nullptr;

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Aim location finder function
	void aimAt(FVector hitLocation, float launchSpeed);

	// Turret and Barrel rotator and elevator
	void moveBarrelTowards(FVector aimDirection);

	// Setter for barrel reference
	void setBarrelReference(UTankBarrel* barrelToSet);

	// TODO add setTurretReference

protected:
};
