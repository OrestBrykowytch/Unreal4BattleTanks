#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();
	if (!controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is possessing: %s"), *(controlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController BeginPlay"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}