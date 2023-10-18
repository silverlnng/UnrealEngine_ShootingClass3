// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBullect.generated.h"



UCLASS()
class SHOOTINGPROJECT3_API AMyBullect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBullect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class USphereComponent* mySphereComp;
	//��ü player��  �ڽ� �浹ü (=�ݸ��� ) ������Ʈ�� �ּ� ����  
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* myMeshComp;
	//�ּҸ� ������ �� 

};
