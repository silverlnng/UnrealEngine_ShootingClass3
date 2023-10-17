// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
//����� BoxComponent �� �������� �������ֱ� 
//����� ���� �ִ´ٰ� �������̴� �ȳ����� �����Ϸ����� ���̰� �� ! 


// ������ �ڸ� = �ʱ�ȭ �ϴ� �ڸ� 
// �����ڿ��� �ۼ��� ���� �ݿ� �Ȱ� ������ ���� �ݿ��Ȱ� ������ ����带 �ϱ� (=�����͸� ���ٰ� �ٽ� Ű�� ������ )
// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	//myBoxComp �� ���������Ʈ �����ϱ� �Լ�(�𸮾����� �Լ�)
	SetRootComponent(myBoxComp);
	//PlayerPawn�� �ֻ�� ������Ʈ ���ϴ� �Լ� 
	//�ֻ���� ������ mobility�� �����ϰ� �� ! 

	
	const FVector boxsize = FVector(32, 32, 50);
	myBoxComp->SetBoxExtent(boxsize);
	// �ڽ��ݶ��̴��� extent �� ����
	// const : ������ ���� �� = ������ �޸� �������� �� ������
	// ������ ���������� , �ٲٷ��� �ϸ� �ٷ� ���� �߻� 

	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));
	//���� : �÷��� �߿� ���빰�� �ٲ��� �ʴ´� = ��ǻ�Ͱ� �� �ʿ� ���� = �̸� ����
	//���� : �÷��� �߿� ���빰�� �ٲ�� = ��ǻ�Ͱ� �˰� �ְ� �ֽ��ؾ��� 
	

	myMeshComp-> SetupAttachment(myBoxComp);
	//SetupAttachment : myMeshComp�� �θ� myBoxComp���� ����   
	const FVector meshlocation = FVector(0, 0, -50);
	myMeshComp-> SetRelativeLocation(meshlocation);


	// �𸮾󿡼� �ּ� ���۷���(��� ����) �� ��õ���� �ʴ� ���
	// mesh�� static mesh �� �����ִ� ��
	// ConstructorHelpers : ���� , 
	//
	//�Ӻ��̵�� 
	//����� (�������� ���/ �ڵ����� ������ ��ο� ���� �ؾ��Ҷ�)
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	if (MeshRef.Succeeded() && MeshRef.Object != nullptr)
	{
		//myMeshComp �� �ּ��̴� �׷��� ->�� ���  
		myMeshComp->SetStaticMesh(MeshRef.Object);
	}

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

