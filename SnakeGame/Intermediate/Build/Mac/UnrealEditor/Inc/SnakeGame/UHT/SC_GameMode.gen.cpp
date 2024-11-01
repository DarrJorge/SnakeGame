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
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FUint32Point();
	ENGINE_API UClass* Z_Construct_UClass_AExponentialHeightFog_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASC_GameMode();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASC_GameMode_NoRegister();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Grid_NoRegister();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Snake_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References
	DEFINE_FUNCTION(ASC_GameMode::execNextColor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NextColor();
		P_NATIVE_END;
	}
	void ASC_GameMode::StaticRegisterNativesASC_GameMode()
	{
		UClass* Class = ASC_GameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "NextColor", &ASC_GameMode::execNextColor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASC_GameMode_NextColor_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASC_GameMode_NextColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "SnakeGame|Console command" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASC_GameMode_NextColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASC_GameMode, nullptr, "NextColor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASC_GameMode_NextColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASC_GameMode_NextColor_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ASC_GameMode_NextColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASC_GameMode_NextColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASC_GameMode);
	UClass* Z_Construct_UClass_ASC_GameMode_NoRegister()
	{
		return ASC_GameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASC_GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
		static const UECodeGen_Private::FUInt32PropertyParams NewProp_CellSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridVisualClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_GridVisualClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SnakeVisualClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_SnakeVisualClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ColorsTable_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ColorsTable;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SnakeDefaultSize_MetaData[];
#endif
		static const UECodeGen_Private::FUInt32PropertyParams NewProp_SnakeDefaultSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GameSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GameSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveForwardInputAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_MoveForwardInputAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveRightInputAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_MoveRightInputAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_MappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridVisual_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridVisual;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SnakeVisual_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SnakeVisual;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Fog_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Fog;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASC_GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SnakeGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ASC_GameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASC_GameMode_NextColor, "NextColor" }, // 866533736
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::FuncInfo) < 2048);
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
		{ "Category", "TheSnake|SnakeGrid" },
		{ "ClampMax", "100" },
		{ "ClampMin", "10" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, GridSize), Z_Construct_UScriptStruct_FUint32Point, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize_MetaData[] = {
		{ "Category", "TheSnake|SnakeGrid" },
		{ "ClampMax", "100" },
		{ "ClampMin", "10" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass_MetaData[] = {
		{ "Category", "TheSnake|SnakeGrid" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass = { "GridVisualClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, GridVisualClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASG_Grid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisualClass_MetaData[] = {
		{ "Category", "TheSnake|Snake" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisualClass = { "SnakeVisualClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, SnakeVisualClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASG_Snake_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisualClass_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisualClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_ColorsTable_MetaData[] = {
		{ "Category", "TheSnake|SnakeGrid" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_ColorsTable = { "ColorsTable", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, ColorsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_ColorsTable_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_ColorsTable_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeDefaultSize_MetaData[] = {
		{ "Category", "TheSnake|Snake" },
		{ "ClampMax", "10" },
		{ "ClampMin", "4" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeDefaultSize = { "SnakeDefaultSize", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, SnakeDefaultSize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeDefaultSize_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeDefaultSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GameSpeed_MetaData[] = {
		{ "Category", "TheSnake|General" },
		{ "ClampMax", "10" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GameSpeed = { "GameSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, GameSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GameSpeed_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GameSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveForwardInputAction_MetaData[] = {
		{ "Category", "TheSnake|SnakeInput" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveForwardInputAction = { "MoveForwardInputAction", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, MoveForwardInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveForwardInputAction_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveForwardInputAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveRightInputAction_MetaData[] = {
		{ "Category", "TheSnake|SnakeInput" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveRightInputAction = { "MoveRightInputAction", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, MoveRightInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveRightInputAction_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveRightInputAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MappingContext_MetaData[] = {
		{ "Category", "TheSnake|SnakeInput" },
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MappingContext = { "MappingContext", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, MappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MappingContext_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual_MetaData[] = {
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual = { "GridVisual", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, GridVisual), Z_Construct_UClass_ASG_Grid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisual_MetaData[] = {
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisual = { "SnakeVisual", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, SnakeVisual), Z_Construct_UClass_ASG_Snake_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisual_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisual_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASC_GameMode_Statics::NewProp_Fog_MetaData[] = {
		{ "ModuleRelativePath", "Public/Framework/SC_GameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASC_GameMode_Statics::NewProp_Fog = { "Fog", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASC_GameMode, Fog), Z_Construct_UClass_AExponentialHeightFog_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASC_GameMode_Statics::NewProp_Fog_MetaData), Z_Construct_UClass_ASC_GameMode_Statics::NewProp_Fog_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASC_GameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_CellSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisualClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisualClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_ColorsTable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeDefaultSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GameSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveForwardInputAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MoveRightInputAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_MappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_GridVisual,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_SnakeVisual,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASC_GameMode_Statics::NewProp_Fog,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASC_GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASC_GameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASC_GameMode_Statics::ClassParams = {
		&ASC_GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASC_GameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASC_GameMode);
	ASC_GameMode::~ASC_GameMode() {}
	struct Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASC_GameMode, ASC_GameMode::StaticClass, TEXT("ASC_GameMode"), &Z_Registration_Info_UClass_ASC_GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASC_GameMode), 736813397U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_1312815703(TEXT("/Script/SnakeGame"),
		Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_SC_GameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
