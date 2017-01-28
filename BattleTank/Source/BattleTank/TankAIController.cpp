// Copyright Igor Berus 2017

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ControlledTank = Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerTank)
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire();
	}
}
