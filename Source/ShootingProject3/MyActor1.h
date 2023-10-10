// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor1.generated.h"

UCLASS()
class SHOOTINGPROJECT3_API AMyActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	// ������
	AMyActor1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//������ ������ �� �ٸ�
	// ������ ������ �ǵ帲 => �θ� ���� �ǵ帮�� ��
	// �����Ǵ� ���� ������ �������� ������ ���� ���ִ� ��

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 number1 = 10;

	UPROPERTY(VisibleAnywhere);
	float number2 = 1.23456f;
	//UPROPERTY(EditinstanceOnly); : ������Ƽ â���� �����Ҽ�����, ������ �ƴ϶� �ν��Ͻ� ��
	UPROPERTY(EditinstanceOnly);
	FString myname = "Unreal";
	// string��  => const char[] 
	//

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	int32 Damage=10;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	int32 Damage2=10;

	void InitializeDamages();

};
