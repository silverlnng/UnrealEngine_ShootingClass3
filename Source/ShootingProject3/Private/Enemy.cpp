// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "MyBullect.h"
#include "PlayerPawn.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"



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

	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowCompo"));
	firePosition->SetupAttachment(myMeshComp);
	//총구생성시키기

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

	//생성될때 한번 랜덤수를 정해서 어떻게 움직일지를 결정하기 
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
	//	//플레이어를 추적하는 함수 작동

	//	//월드에 있는 플레이어 찾고 유효하다면 
	//	// 플레이어의 위치 - 스폰위치 로 각도 구해서 그방향으로 움직이도록 만들기

	//}
	//else
	//{
	//	//그냥 앞으로 움직이도록 작동 
	//	SetActorLocation(GetActorLocation() + GetActorForwardVector() * moveSpeed * DeltaTime);
	//}
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * moveSpeed * DeltaTime);

	// 플레이어 - 총구 로 각도구하기

	

}

void AEnemy::TracePlayerMove()
{

}

void AEnemy::Fire()
{
	const FRotator tempVector = dir.Rotation();

	AMyBullect* bullect = GetWorld()->SpawnActor<AMyBullect>(bullectFactory, firePosition->GetComponentLocation(), tempVector);
	//GetWorld 는 레벨에서 세상을 의미

	//총알 발사 소리 내기
	// 월드 ( 어느월드 , 사운드 , 사운드를 낼 위치 ) 
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), firesound, firePosition->GetComponentLocation());
}

