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
	//주체 player의  박스 충돌체 (=콜리전 ) 컴포넌트를 주소 선언  
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* myMeshComp;
	//주소를 선언한 것 

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
