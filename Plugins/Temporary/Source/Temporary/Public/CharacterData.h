// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterData.generated.h"

/**
 * 
 */
UCLASS()
class TEMPORARY_API UCharacterData : public UObject
{
	GENERATED_BODY()
	
public:
	UCharacterData();

	// 캐릭터의 기본 능력치 데이터 속성 정의
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	int32 MaxHp;
	
};
