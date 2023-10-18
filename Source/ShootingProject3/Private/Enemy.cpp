// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

//enemy�� �������� ������ �����̰ų� �÷��̾ ���� �����δ�

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	//myBoxComp �� ���������Ʈ �����ϱ� �Լ�(�𸮾����� �Լ�)
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

	//�����ɶ� �ѹ� �������� ���ؼ� ��� ���������� �����ϱ� 
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
		//�÷��̾ �����ϴ� �Լ� �۵�
	}
	else
	{
		//�׳� ������ �����̵��� �۵� 
		SetActorLocation(GetActorLocation() + GetActorForwardVector() * moveSpeed * DeltaTime);
	}
}

void AEnemy::TracePlayerMove()
{

}

