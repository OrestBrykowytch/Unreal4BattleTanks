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

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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

	if (UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, startLocation, hitLocation, launchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace)) // Calculate the outLaunchVelocity
	{
		auto aimDirection = outLaunchVelocity.GetSafeNormal();

		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *ourTankName, *aimDirection.ToString(), *barrelLocation);
	}
	else
	{
		// No solution
	}

}

void UTankAimingComponent::setBarrelReference(UStaticMeshComponent* barrelToSet)
{
	barrel = barrelToSet;
}