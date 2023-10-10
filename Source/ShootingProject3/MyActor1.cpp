// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//생성자
	//초기화 작업

	InitializeDamages();

}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	//super (나에게 상속 한 부모의 원본)
	Super::BeginPlay();
	//
	UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	UE_LOG(LogTemp, Warning, TEXT("%f"), number2);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *myname);

	//* 포인터의 개념 
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//초기화 하는 함수를 만들기
void AMyActor1::InitializeDamages()
{
	Damage = 10;
	Damage2 = 20;
}
