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
	//역참조
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//number1, number2 와 swap함수 내에 있는 pa 와 pb 는 다른 메모리 공간을 차지하고 있는 다른 변수
	//Swap(number1, number2);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number1Pointer);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), *number2Pointer);

	//주소 값을 인자로 받아주기 
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
// 매개변수를 포인터로 설정해서 , 레퍼런스 그자체 값을 인수로 받을수 있게 되었음
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

// call by value
// 복사 
void APointerTest::Swap(int pa, int pb)
{
	int temp = pb;
	pb = pa;
	pa = temp;
}

//숫자 세개의 값 변경하기
void APointerTest::Swap(int* pa, int* pb, int* pc)
{
	int _temp ;
	//임시 변수 선언
	tempPtr = &_temp;
	// tempPtr 이 임시변수의 주소를 포인트하도록 대입
	*tempPtr = *pa;
	//tempPtr이 포인트하고 있는 _temp의 값이 pa 가 포인트하고 있는 1로 변경. 
	// _temp=1
	*pa = *pc;
	//pa가 포인트 하고있는 곳은 pc가 가르키고 있는 3으로 변경
	//*pa=3
	*pc = *pb;
	//pc가 포인트 하고 있는곳은 pb가 포인트하고있는 2로 변경
	//*pc=2
	*pb = *tempPtr;
	//*pb=1
}

// 수학을 이용해서 숫자 세개를 스왑하는 또 다른방법
void APointerTest::SwapThree(int &pa, int &pb, int &pc)
{
	pa = pa + pb + pc;
	pb = pa - (pb + pc);
	pc = pa - (pb + pc);
	pa = pa - (pb + pc);
}


// Called every frame
void APointerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

