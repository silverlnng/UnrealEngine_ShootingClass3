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
	//�������� Ÿ���� �����ִ� ������ �������� �����Ͱ� ����Ű�� ���� �޸𸮸� �󸶳� ���� �𸣱� °����
	int32 number3;
	int32* number3Pointer;
	int* tempPtr;
	//int32* temp=NULL;

	void Swap(int* pa, int* pb); //�Ű������� �����ͷ� �����ؼ� , ���۷��� ����ü ���� �μ��� ������ �ְ� �Ǿ���
	void Swap(int pa, int pb);	//�Ű������� Ÿ���� �ٸ��� ���༭ Swap�Լ��� override , ������ ���� 
	void Swap(int* pa, int* pb , int* pc);
};
