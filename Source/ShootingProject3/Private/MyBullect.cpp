// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBullect.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyBullect::AMyBullect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mySphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("MySphereComponent"));
	//myBoxComp 를 서브오브젝트 생성하기 함수(언리얼제공 함수)
	SetRootComponent(mySphereComp);
	const float Radius = 6.0f;
	mySphereComp->SetSphereRadius(Radius);


	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));
	
	myMeshComp->SetupAttachment(mySphereComp);
	const FVector Position = FVector(0, 0, -5.0f);
	const float Scale = 0.1f;
	myMeshComp->SetRelativeLocation(Position);
	myMeshComp->SetAllMassScale(Scale);


}

// Called when the game starts or when spawned
void AMyBullect::BeginPlay()
{
	Super::BeginPlay();
	
}

//총알은 플레이어에 의해  원하는 위치에 생성되고 앞으로 날라가기만 하면됨 
// Called every frame
void AMyBullect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//tick에 정의를 해서 생성하자마자 + 계속 움직이도록 만듬
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * 100 * GetWorld()->GetDeltaSeconds());
}

//enemy 와 충돌을 감지 

