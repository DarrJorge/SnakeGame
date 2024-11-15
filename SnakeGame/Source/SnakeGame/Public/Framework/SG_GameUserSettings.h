// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "SnakeGame/Core/Types.h"
#include "SG_GameUserSettings.generated.h"

UENUM()
enum class EGameSpeed : uint8
{
	Worm = 0,
	Snake,
	Python
};

UENUM()
enum class EGridSize : uint8
{
	Size_30x10 = 0,
	Size_50x15,
	Size_80x20
};

UCLASS()
class SNAKEGAME_API USG_GameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	USG_GameUserSettings();
	
	static USG_GameUserSettings* Get();
	
	TArray<FString> GameSpeedOptions() const { return OptionNames(GameSpeeds); }
	TArray<FString> GridSizesOptions() const { return OptionNames(GridSizes); }

	void SaveSnakeSettings(EGameSpeed GameSpeed, EGridSize GridSize);

	FORCEINLINE FString GetCurrentGameSpeedOption() const { return CurrentSpeed.Name; }
	FORCEINLINE FString GetCurrentGridSizeOption() const { return CurrentGridSize.Name; }
	FORCEINLINE bool GetUseTraps() const { return bUseTraps; }
	FORCEINLINE float GameSpeed() const { return CurrentSpeed.Value; }
	FORCEINLINE SnakeGame::Dimension GridSize() const { return CurrentGridSize.Value; }

	EGameSpeed GameSpeedByName(const FString& Name) const
	{
		return FindOptionByNameOrDefault(GameSpeeds, Name, EGameSpeed::Snake);
	}
	
	EGridSize GridSizeByName(const FString& Name) const
	{
		return FindOptionByNameOrDefault(GridSizes, Name, EGridSize::Size_50x15);
	}

private:
	struct FSpeedData
	{
		FString Name;
		float Value;
	};

	const TMap<EGameSpeed, FSpeedData> GameSpeeds
	{
		{ EGameSpeed::Worm, {"Worm", 0.3f}},
		{ EGameSpeed::Snake, {"Snake", 0.1f}},
		{ EGameSpeed::Python, {"Python", 0.05f}}
	};

	struct FGridData
	{
		FString Name;
		SnakeGame::Dimension Value;
	};

	const TMap<EGridSize, FGridData> GridSizes
	{
		{ EGridSize::Size_30x10, {"30x10", SnakeGame::Dimension{30, 10}}},
		{ EGridSize::Size_50x15, {"50x15", SnakeGame::Dimension{50, 15}}},
		{ EGridSize::Size_80x20, {"80x20", SnakeGame::Dimension{80, 20}}}
	};

	FSpeedData CurrentSpeed{GameSpeeds[EGameSpeed::Snake]};
	FGridData CurrentGridSize{GridSizes[EGridSize::Size_50x15]};
	bool bUseTraps{false};

	template<typename MapType, typename EnumType>
	EnumType FindOptionByNameOrDefault(const MapType& Map, const FString& Name, EnumType Default) const;

	template<typename MapType>
	TArray<FString> OptionNames(const MapType& Map) const;
	
};

template <typename MapType, typename EnumType>
EnumType USG_GameUserSettings::FindOptionByNameOrDefault(const MapType& Map, const FString& Name, EnumType Default) const
{
	const auto* Founded = Algo::FindByPredicate(Map,[Name](const auto& Pair)
		{ return Pair.Value.Name.Equals(Name); });
	return Founded ? Founded->Key : Default;
}

template <typename MapType>
TArray<FString> USG_GameUserSettings::OptionNames(const MapType& Map) const
{
	TArray<FString> Names;

	Algo::Transform(Map, Names, [](const auto& Pair)
		{ return Pair.Value.Name; });

	return Names;
}
