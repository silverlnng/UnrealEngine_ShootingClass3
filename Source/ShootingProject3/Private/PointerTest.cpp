// Fill out your copyright notice in the Description page of Project Settings.


#include "PointerTest.h"

// Sets default values
APointerTest::APointerTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APointerTest::BeginPlay()
{
	Super::BeginPlay();
	
	number1 = 1234;
	number1Pointer = &number1;
	number2 = 5678;
	number2Pointer = &number2;

	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1Pointer);
	//������
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//�ּ� ���� ���ڷ� �޾��ֱ� 
	Swap(&number1, &number2);

	UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//*number1Pointer = 5678;
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
}

//�Ű������� �����ͷ� �����ؼ� , ���۷��� ����ü ���� �μ��� ������ �ְ� �Ǿ���
void APointerTest::Swap(int* pa, int* pb)
{
	// ������ pb�� �������� ����Ű�� ���� ���� temp �� �����صα� 
	int temp = *pb;
	//pb�� �������� ����Ű�� ���� pa�� ����Ű�� ���� ���� = swap
	*pb = *pa;
	//�̸� ���� �ص� pb�� ����Ű�� �� temp���� pa�� ����Ű�� ���� ���� 
	*pa = temp;
	//��� ������ �μ��� ��ü�� ���� ���� ���� ��ü 
}


// Called every frame
void APointerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

