// Fill out your copyright notice in the Description page of Project Settings.


#include "CreateStaticMesh.h"

// Sets default values
ACreateStaticMesh::ACreateStaticMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SUPER MESH"));
}

// Called when the game starts or when spawned
void ACreateStaticMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreateStaticMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

