// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TemporaryActor.generated.h"

class USphereComponent;
class URotatingMovementComponent;

UCLASS()
class TEMPORARY_API ATemporaryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATemporaryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Temporary|Pickup")
	USphereComponent* CollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Temporary|Pickup")
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Temporary|Pickup")
	URotatingMovementComponent* RotatingComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Temporary|Pickup")
	FRotator RotationRate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Temporary|Pickup")
	class USoundBase* PickupSound;
	
	UFUNCTION()
	void OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
