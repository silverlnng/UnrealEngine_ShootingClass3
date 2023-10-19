// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "MyBullect.h"

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
	//static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	//if (MeshRef.Succeeded() && MeshRef.Object != nullptr)
	//{
	//	//myMeshComp �� �ּ��̴� �׷��� ->�� ���  
	//	myMeshComp->SetStaticMesh(MeshRef.Object);
	//}
	
	
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowCompo"));
	firePosition->SetupAttachment(myMeshComp);
	//�ѱ�������Ű��

	currentTime = 0.0f;
	delayTime = 3.0f;
	timePassed = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
		
	}

}

void APlayerPawn::Move(const FInputActionValue& value)
{
	const FVector CurrentValue = value.Get<FVector>();
	//���⼭ value���� IA_Move�� Axis���� �������־ 0~1 ���� �޴´�

	//���Ӹ���� ����Ʈ pawn ���� Ȯ���ϴ� �� 
	if (Controller)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentValue.X);
		//UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentValue.Y);

		SetActorLocation(GetActorLocation() + CurrentValue * 100.0f * GetWorld()->GetDeltaSeconds());
	}

}

void APlayerPawn::Fire(const FInputActionValue& value)
{
	//���⼭ �Ѿ� �������Ʈ��  fire position �� ������Ű��
	// fireInputAsset ���� ���� value���� �´� .
	// fireInputAsset �� digital���� �������� value���� 0 �Ǵ� 1 �̴�.

	if (Controller && value.Get<bool>() == true && timePassed)
	{
		//���⼭ ��Ÿ���� �����Ҽ����� !!
		//����ִ� ���°� �ȴٸ� �Ѿ��� �߻� 
		//�Ѿ��� ��¼��� Ÿ�̸Ӹ� �۵���Ŵ 
		//Ÿ�̸Ӱ� �����ð��� ������ �Ѿ��� ��°� ����
		AMyBullect* bullect = GetWorld()->SpawnActor<AMyBullect>(bullectFactory, firePosition->GetComponentLocation(), firePosition->GetComponentRotation());
		//GetWorld �� �������� ������ �ǹ�

		bullectTimerStarted = true;
		currentTime = 0;
	}

}


// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bullectTimerStarted)
	{
		if (currentTime >= delayTime)
		{
			timePassed = true;
		}
		else
		{
			timePassed = false;
			currentTime += DeltaTime;
		}
	}
}


// ��ǲ �� ���ε� �ϴ� ����
// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked< UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAxis, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
		EnhancedInputComponent->BindAction(fireInputAsset, ETriggerEvent::Started, this, &APlayerPawn::Fire);

		// ETriggerEvent::Started,Completed ,,�� �� �����ؼ� ���ε� �׼��� �����Ҽ��ִ�
		

	}

}

