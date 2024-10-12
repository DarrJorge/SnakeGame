// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Public/Framework/GameWorld/SG_WorldTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSG_WorldTypes() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	SNAKEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeColors();
	UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References

static_assert(std::is_polymorphic<FSnakeColors>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FSnakeColors cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeColors;
class UScriptStruct* FSnakeColors::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeColors.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeColors.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeColors, (UObject*)Z_Construct_UPackage__Script_SnakeGame(), TEXT("SnakeColors"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeColors.OuterSingleton;
}
template<> SNAKEGAME_API UScriptStruct* StaticStruct<FSnakeColors>()
{
	return FSnakeColors::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSnakeColors_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridBackgroundColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GridBackgroundColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridWallColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GridWallColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridLineColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GridLineColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkyAtmosphereColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SkyAtmosphereColor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSnakeColors_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_WorldTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSnakeColors_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeColors>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridBackgroundColor_MetaData[] = {
		{ "Category", "SnakeColors" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_WorldTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridBackgroundColor = { "GridBackgroundColor", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeColors, GridBackgroundColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridBackgroundColor_MetaData), Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridBackgroundColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridWallColor_MetaData[] = {
		{ "Category", "SnakeColors" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_WorldTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridWallColor = { "GridWallColor", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeColors, GridWallColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridWallColor_MetaData), Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridWallColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridLineColor_MetaData[] = {
		{ "Category", "SnakeColors" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_WorldTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridLineColor = { "GridLineColor", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeColors, GridLineColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridLineColor_MetaData), Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridLineColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_SkyAtmosphereColor_MetaData[] = {
		{ "Category", "SnakeColors" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_WorldTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_SkyAtmosphereColor = { "SkyAtmosphereColor", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeColors, SkyAtmosphereColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_SkyAtmosphereColor_MetaData), Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_SkyAtmosphereColor_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeColors_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridBackgroundColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridWallColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_GridLineColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeColors_Statics::NewProp_SkyAtmosphereColor,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeColors_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SnakeGame,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"SnakeColors",
		Z_Construct_UScriptStruct_FSnakeColors_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeColors_Statics::PropPointers),
		sizeof(FSnakeColors),
		alignof(FSnakeColors),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeColors_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeColors_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeColors_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FSnakeColors()
	{
		if (!Z_Registration_Info_UScriptStruct_SnakeColors.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeColors.InnerSingleton, Z_Construct_UScriptStruct_FSnakeColors_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SnakeColors.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_WorldTypes_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_WorldTypes_h_Statics::ScriptStructInfo[] = {
		{ FSnakeColors::StaticStruct, Z_Construct_UScriptStruct_FSnakeColors_Statics::NewStructOps, TEXT("SnakeColors"), &Z_Registration_Info_UScriptStruct_SnakeColors, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeColors), 2522549138U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_WorldTypes_h_1291912832(TEXT("/Script/SnakeGame"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_WorldTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_WorldTypes_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
