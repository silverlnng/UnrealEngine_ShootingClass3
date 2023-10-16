// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
//헤더에 BoxComponent 가 무엇인지 선언해주기 
//헤더에 많이 넣는다고 성능차이는 안나지만 컴파일러에서 차이가 남 ! 


//생성자 자리 = 초기화 하는 자리 
// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	//myBoxComp 를 서브오브젝트 생성하기 함수(언리얼제공 함수)
	SetRootComponent(myBoxComp);
	//PlayerPawn의 최상단 컴포넌트 정하는 함수 
	//최상단이 액터의 mobility를 결정하게 됨 ! 

	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));
	myMeshComp-> SetupAttachment(myBoxComp);
	//SetupAttachment : myMeshComp의 부모를 myBoxComp으로 정함   
	//
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

