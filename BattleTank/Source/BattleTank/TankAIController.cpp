// Copyright Igor Berus 2017

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("AIController not posesing a tank."));
	}

	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find player tank."));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}