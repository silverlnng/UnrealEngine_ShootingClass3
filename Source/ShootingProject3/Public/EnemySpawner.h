// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SHOOTINGPROJECT3_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void spawnEnemy();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* myBoxComp;
	//��ü player��  �ڽ� �浹ü (=�ݸ��� ) ������Ʈ�� �ּ� ����  
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* myMeshComp;
	//�ּҸ� ������ �� 

	UPROPERTY(EditAnywhere)
	class UArrowComponent* spawnPosition;

	UPROPERTY(EditAnywhere)
	float currentTime;

	UPROPERTY(EditAnywhere)
	float spawnCoolTime;

	bool spawnCoolTimePassed;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemy> enemyFactory;


};
