// Fill out your copyright notice in the Description page of Project Settings.


#include "TemporaryActor.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Kismet/GameplayStatics.h" // 오디오 재생 등을 위해 필요
#include "GameFramework/Character.h" // 플레이어 확인을 위해 필요

// Sets default values
ATemporaryActor::ATemporaryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(50.f); // 충돌 반경 설정
	CollisionComponent->SetCollisionProfileName(TEXT("Trigger")); // 다른 객체와 오버랩되도록 설정
	RootComponent = CollisionComponent;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingComponent"));
	RotationRate = FRotator(0.f, 90.f, 0.f); // 초당 Y축으로 90도 회전 (기본값)
	RotatingComponent->RotationRate = RotationRate;

}

// Called when the game starts or when spawned
void ATemporaryActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Hello from Temporary Plugin!"));
	}
	
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATemporaryActor::OnPickupOverlap);
}

// Called every frame
void ATemporaryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATemporaryActor::OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
	
	if (OtherActor && (OtherActor != this) && PlayerCharacter)
	{
		
		UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
		
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Temporary 아이템을 획득했습니다!"));
		}
		
		Destroy();
	}
}

