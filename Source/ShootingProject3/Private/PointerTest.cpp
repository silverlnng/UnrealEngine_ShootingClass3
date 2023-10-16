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
	
	number1 = 1;
	number1Pointer = &number1;
	number2 = 2;
	number2Pointer = &number2;
	number3 = 3;
	number3Pointer = &number3;
	tempPtr = NULL;
	//temp = &number1;
	//temp = 0;

	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1Pointer);
	//������
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//number1, number2 �� swap�Լ� ���� �ִ� pa �� pb �� �ٸ� �޸� ������ �����ϰ� �ִ� �ٸ� ����
	//Swap(number1, number2);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//�ּ� ���� ���ڷ� �޾��ֱ� 
	/*Swap(&number1, &number2);

	UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);*/

	//*number1Pointer = 5678;
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	
	Swap(&number1, &number2, &number3);

	UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number3Pointer);
}

// call by reference
// �Ű������� �����ͷ� �����ؼ� , ���۷��� ����ü ���� �μ��� ������ �ְ� �Ǿ���
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

// call by value
// ���� 
void APointerTest::Swap(int pa, int pb)
{
	int temp = pb;
	pb = pa;
	pa = temp;
}

//���� ������ �� �����ϱ�
void APointerTest::Swap(int* pa, int* pb, int* pc)
{
	int _temp ;
	tempPtr = &_temp;
	*tempPtr = *pa;
	*pa = *pc;
	*pc = *pb;
	*pb = *tempPtr;

}



// Called every frame
void APointerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

