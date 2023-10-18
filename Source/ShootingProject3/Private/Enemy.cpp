// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

//enemy는 랜덤으로 앞으로 움직이거나 플레이어를 향해 움직인다

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	//myBoxComp 를 서브오브젝트 생성하기 함수(언리얼제공 함수)
	SetRootComponent(myBoxComp);
	const FVector boxsize = FVector(40, 40, 60);
	myBoxComp->SetBoxExtent(boxsize);


	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));

	myMeshComp->SetupAttachment(myBoxComp);
	const FVector Position = FVector(0, 0, -40.0f);
	const FVector Scale = FVector(1, 1, 1);

	myMeshComp->SetRelativeLocation(Position);
	myMeshComp->SetRelativeScale3D(Scale);

	moveSpeed = 100.0f;
	traceRate = 0.5;
	tracePlayer = false;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	//생성될때 한번 랜덤수를 정해서 어떻게 움직일지를 결정하기 
	int32 randomResult = FMath::RandRange(0, 1);
	if (randomResult >= traceRate)
	{
		tracePlayer = true;
	}
	else
	{
		tracePlayer = false;
	}
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (tracePlayer)
	{
		//플레이어를 추적하는 함수 작동
	}
	else
	{
		//그냥 앞으로 움직이도록 작동 
		SetActorLocation(GetActorLocation() + GetActorForwardVector() * moveSpeed * DeltaTime);
	}
}

void AEnemy::TracePlayerMove()
{

}

