#include "BattleTanks.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
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

void UTankAimingComponent::aimAt(FVector hitLocation)
{
	auto ourTankName = GetOwner()->GetName();
	FString barrelLocation = "";

	if (barrel)
	{
		barrelLocation = barrel->GetComponentLocation().ToString();
	}

	UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *ourTankName, *hitLocation.ToString(), *barrelLocation);
}

void UTankAimingComponent::setBarrelReference(UStaticMeshComponent* barrelToSet)
{
	barrel = barrelToSet;
}