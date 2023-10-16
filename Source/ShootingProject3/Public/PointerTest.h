// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointerTest.generated.h"

UCLASS()
class SHOOTINGPROJECT3_API APointerTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointerTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 number1;
	int32* number1Pointer;

	int32 number2;
	int32* number2Pointer;
	//포인터의 타입을 정해주는 이유는 역참조로 포인터가 가르키는 값이 메모리를 얼마나 쓸지 모르기 째문에
	int32 number3;
	int32* number3Pointer;
	int* tempPtr;
	//int32* temp=NULL;

	void Swap(int* pa, int* pb); //매개변수를 포인터로 설정해서 , 레퍼런스 그자체 값을 인수로 받을수 있게 되었음
	void Swap(int pa, int pb);	//매개변수의 타입을 다르게 해줘서 Swap함수에 override , 값으로 전달 
	void Swap(int* pa, int* pb , int* pc);
};
