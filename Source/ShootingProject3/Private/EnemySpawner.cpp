// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Enemy.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	SetRootComponent(myBoxComp);


	const FVector boxsize = FVector(55, 55, 50);
	myBoxComp->SetBoxExtent(boxsize);	
	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));

	myMeshComp->SetupAttachment(myBoxComp);
	const FVector meshlocation = FVector(0, 0, -50);
	myMeshComp->SetRelativeLocation(meshlocation);


	spawnPosition = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowCompo"));
	spawnPosition->SetupAttachment(myMeshComp);

	currentTime = 0.0f;
	spawnCoolTime = 4.5f;
	spawnCoolTimePassed = false;


}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentTime >= spawnCoolTime)
	{
		currentTime = 0;
		spawnEnemy();
		//생성함수 작동
	}
	else
	{
		currentTime += DeltaTime;
	}

}

void AEnemySpawner::spawnEnemy()
{
	GetWorld()->SpawnActor<AEnemy>(enemyFactory, spawnPosition->GetComponentLocation(), spawnPosition->GetComponentRotation());
}
