// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//������
	//�ʱ�ȭ �۾�

	InitializeDamages();

}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	//super (������ ��� �� �θ��� ����)
	Super::BeginPlay();
	//
	UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	UE_LOG(LogTemp, Warning, TEXT("%f"), number2);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *myname);

	//* �������� ���� 
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//�ʱ�ȭ �ϴ� �Լ��� �����
void AMyActor1::InitializeDamages()
{
	Damage = 10;
	Damage2 = 20;
}
