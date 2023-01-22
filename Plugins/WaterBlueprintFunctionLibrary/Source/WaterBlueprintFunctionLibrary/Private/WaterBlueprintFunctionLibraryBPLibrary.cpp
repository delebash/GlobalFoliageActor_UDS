// Copyright Epic Games, Inc. All Rights Reserved.

#include "WaterBlueprintFunctionLibraryBPLibrary.h"
#include "WaterBlueprintFunctionLibrary.h"
#include "WaterBodyActor.h"
#include "WaterWaves.h"
#include "Kismet/GameplayStatics.h"

UWaterBlueprintFunctionLibraryBPLibrary::UWaterBlueprintFunctionLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UWaterBlueprintFunctionLibraryBPLibrary::ChangeWaterWaveAsset(UObject* WorldContextObject, AWaterBody* CurrentWaterBody, const FString& WaveAssetFolder,  const FString& WaveAssetName)
{
	FString FullPath = WaveAssetFolder + "/" + WaveAssetName;

	UWaterWavesAsset* WaterWavesRef = LoadObject<UWaterWavesAsset>(nullptr, const_cast<TCHAR*>(*FullPath));
	// UWaterWavesAsset* WaterWavesRef = LoadObject<UWaterWavesAsset>(nullptr, TEXT("/Water/Waves/Dan_GerstnerWaves_Lake.Dan_GerstnerWaves_Lake"));
	//AActor* FoundActor  = UGameplayStatics::GetActorOfClass(WorldContextObject,ActorClass);
	//AWaterBody* CurrentWaterBody = Cast<AWaterBody>(FoundActor);
	CurrentWaterBody->SetWaterWaves(WaterWavesRef->GetWaterWaves());
}

void UWaterBlueprintFunctionLibraryBPLibrary::RecalcWaveData(UObject* WorldContextObject, UGerstnerWaterWaves* GerstnerWaterWaves)
{
	GerstnerWaterWaves->RecomputeWaves(true);
}