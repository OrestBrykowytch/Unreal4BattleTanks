#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	UStaticMeshComponent* barrel = nullptr;

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void aimAt(FVector hitLocation, float launchSpeed);

	// Setter for barrel reference
	void setBarrelReference(UStaticMeshComponent* barrelToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
