// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "MyBullect.h"
#include "PlayerPawn.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"



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

	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowCompo"));
	firePosition->SetupAttachment(myMeshComp);
	//�ѱ�������Ű��

	currentTime = 0.0f;
	fireCoolTime = 3.0f;


	moveSpeed = 100.0f;
	traceRate = 0.5;
	tracePlayer = false;
	dir = FVector(0, 0, 0);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	//�����ɶ� �ѹ� �������� ���ؼ� ��� ���������� �����ϱ� 
	int32 randomResult = FMath::RandRange(0, 1);
	/*if (randomResult >= traceRate)
	{
		tracePlayer = true;
	}
	else
	{
		tracePlayer = false;
	}*/
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentTime >= fireCoolTime)
	{
		currentTime = 0;
		for (TActorIterator<APlayerPawn> player(GetWorld()); player; ++player)
		{
			if (player->GetName().Contains(TEXT("BP_MyPlayerPawn")))
			{
				dir = player->GetActorLocation() - firePosition->GetComponentLocation();
				dir.Normalize();
			}

		}
		Fire();
	}
	else
	{
		currentTime += DeltaTime;
	}

	//if (tracePlayer)
	//{
	//	//�÷��̾ �����ϴ� �Լ� �۵�

	//	//���忡 �ִ� �÷��̾� ã�� ��ȿ�ϴٸ� 
	//	// �÷��̾��� ��ġ - ������ġ �� ���� ���ؼ� �׹������� �����̵��� �����

	//}
	//else
	//{
	//	//�׳� ������ �����̵��� �۵� 
	//	SetActorLocation(GetActorLocation() + GetActorForwardVector() * moveSpeed * DeltaTime);
	//}
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * moveSpeed * DeltaTime);

	// �÷��̾� - �ѱ� �� �������ϱ�

	

}

void AEnemy::TracePlayerMove()
{

}

void AEnemy::Fire()
{
	const FRotator tempVector = dir.Rotation();

	AMyBullect* bullect = GetWorld()->SpawnActor<AMyBullect>(bullectFactory, firePosition->GetComponentLocation(), tempVector);
	//GetWorld �� �������� ������ �ǹ�

	//�Ѿ� �߻� �Ҹ� ����
	// ���� ( ������� , ���� , ���带 �� ��ġ ) 
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), firesound, firePosition->GetComponentLocation());
}

