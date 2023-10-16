// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
//����� BoxComponent �� �������� �������ֱ� 
//����� ���� �ִ´ٰ� �������̴� �ȳ����� �����Ϸ����� ���̰� �� ! 


//������ �ڸ� = �ʱ�ȭ �ϴ� �ڸ� 
// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	//myBoxComp �� ���������Ʈ �����ϱ� �Լ�(�𸮾����� �Լ�)
	SetRootComponent(myBoxComp);
	//PlayerPawn�� �ֻ�� ������Ʈ ���ϴ� �Լ� 
	//�ֻ���� ������ mobility�� �����ϰ� �� ! 

	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));
	myMeshComp-> SetupAttachment(myBoxComp);
	//SetupAttachment : myMeshComp�� �θ� myBoxComp���� ����   
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

