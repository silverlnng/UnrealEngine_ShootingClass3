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
	//역참조
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//주소 값을 인자로 받아주기 
	Swap(&number1, &number2);

	UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//*number1Pointer = 5678;
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
}

//매개변수를 포인터로 설정해서 , 레퍼런스 그자체 값을 인수로 받을수 있게 되었음
void APointerTest::Swap(int* pa, int* pb)
{
	// 포인터 pb가 역참조로 가르키는 곳을 먼저 temp 에 저장해두기 
	int temp = *pb;
	//pb가 역참조로 가르키는 곳과 pa가 가르키는 곳을 변경 = swap
	*pb = *pa;
	//미리 저장 해둔 pb가 가르키는 곳 temp값을 pa가 가르키는 곳에 대입 
	*pa = temp;
	//결과 적으로 인수그 자체의 원본 값을 서로 교체 
}


// Called every frame
void APointerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

