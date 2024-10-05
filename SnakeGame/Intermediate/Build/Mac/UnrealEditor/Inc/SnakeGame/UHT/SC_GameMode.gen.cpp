// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Public/Framework/SC_GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSC_GameMode() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASC_GameMode();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASC_GameMode_NoRegister();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Grid_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References
	void ASC_GameMode::StaticRegisterNativesASC_GameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASC_GameMode);
	UClass* Z_Construct_UClass_ASC_GameMode_NoRegister()
	{
		return ASC_GameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASC_GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GridSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CellSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridVisualClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_GridVisualClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridVisual_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridVisual;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASC_GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SnakeGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Framework/SC_GameMode.h" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize_MetaData[] = {
		{ "Category", "SnakeGrid" },
		{ "ClampMax", "100" },
		{ "ClampMin", "10" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, GridSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize_MetaData[] = {
		{ "Category", "SnakeGrid" },
		{ "ClampMax", "100" },
		{ "ClampMin", "10" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass_MetaData[] = {
		{ "Category", "SnakeGrid" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass = { "GridVisualClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, GridVisualClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASG_Grid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual_MetaData[] = {
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual = { "GridVisual", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, GridVisual), Z_Construct_UClass_ASG_Grid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASC_GameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASC_GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASC_GameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASC_GameMode_Statics::ClassParams = {
		&ASC_GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASC_GameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASC_GameMode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASC_GameMode()
	{
		if (!Z_Registration_Info_UClass_ASC_GameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASC_GameMode.OuterSingleton, Z_Construct_UClass_ASC_GameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASC_GameMode.OuterSingleton;
	}
	template<> SNAKEGAME_API UClass* StaticClass<ASC_GameMode>()
	{
		return ASC_GameMode::StaticClass();
	}
	ASC_GameMode::ASC_GameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASC_GameMode);
	ASC_GameMode::~ASC_GameMode() {}
	struct Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASC_GameMode, ASC_GameMode::StaticClass, TEXT("ASC_GameMode"), &Z_Registration_Info_UClass_ASC_GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASC_GameMode), 3809610764U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_883795538(TEXT("/Script/SnakeGame"),
		Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
