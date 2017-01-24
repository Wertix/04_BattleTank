// Copyright Igor Berus 2017

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	// TODO set turret reference

private:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
};
