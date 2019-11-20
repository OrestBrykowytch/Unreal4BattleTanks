#include "BattleTanks.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::aimAt(FVector hitLocation, float launchSpeed)
{
	auto ourTankName = GetOwner()->GetName();
	FString barrelLocation = "";

	if (barrel)
	{
		barrelLocation = barrel->GetComponentLocation().ToString();
	}
	else
	{
		return;
	}

	FVector outLaunchVelocity, startLocation = barrel->GetSocketLocation(FName("Projectile"));
	bool aimingSolution = UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, startLocation, hitLocation, launchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace); // Calculate the outLaunchVelocity

	if (aimingSolution)
	{
		auto aimDirection = outLaunchVelocity.GetSafeNormal();

		// UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *ourTankName, *aimDirection.ToString(), *barrelLocation);

		// Move barrel and rotate turret
		moveBarrelTowards(aimDirection);
	}
	else
	{
	}
}

void UTankAimingComponent::setBarrelReference(UStaticMeshComponent* barrelToSet)
{
	barrel = barrelToSet;
}

void UTankAimingComponent::moveBarrelTowards(FVector aimDirection)
{
	// Work out difference between current barrel direction and aimDirection
	auto barrelRotation = barrel->GetForwardVector().Rotation(), aimAsRotator = aimDirection.Rotation(), deltaRotation = aimAsRotator - barrelRotation;

	UE_LOG(LogTemp, Warning, TEXT("aimAsRotator: %s"), *deltaRotation.ToString())

	// Move barrel towards aimDirection using max rotation/elevation speed and frametime
}