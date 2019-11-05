#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto playerTank = GetPlayerTank();
	if (!playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find playerTank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found playerTank: %s"), *(playerTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController BeginPlay"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!playerPawn)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(playerPawn);
	}
}
