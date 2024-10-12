// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Public/Framework/GameWorld/SG_Grid.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSG_Grid() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Grid();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Grid_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References
	void ASG_Grid::StaticRegisterNativesASG_Grid()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASG_Grid);
	UClass* Z_Construct_UClass_ASG_Grid_NoRegister()
	{
		return ASG_Grid::StaticClass();
	}
	struct Z_Construct_UClass_ASG_Grid_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Origin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASG_Grid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SnakeGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Grid_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Grid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Framework/GameWorld/SG_Grid.h" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Grid.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Grid_Statics::NewProp_Origin_MetaData[] = {
		{ "Category", "SG_Grid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Grid.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASG_Grid_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Grid, Origin), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Grid_Statics::NewProp_Origin_MetaData), Z_Construct_UClass_ASG_Grid_Statics::NewProp_Origin_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMesh_MetaData[] = {
		{ "Category", "SG_Grid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Grid.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMesh = { "GridMesh", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Grid, GridMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMesh_MetaData), Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Grid.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMaterial = { "GridMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Grid, GridMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMaterial_MetaData), Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMaterial_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASG_Grid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Grid_Statics::NewProp_Origin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Grid_Statics::NewProp_GridMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASG_Grid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASG_Grid>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASG_Grid_Statics::ClassParams = {
		&ASG_Grid::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASG_Grid_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Grid_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Grid_Statics::Class_MetaDataParams), Z_Construct_UClass_ASG_Grid_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Grid_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASG_Grid()
	{
		if (!Z_Registration_Info_UClass_ASG_Grid.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASG_Grid.OuterSingleton, Z_Construct_UClass_ASG_Grid_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASG_Grid.OuterSingleton;
	}
	template<> SNAKEGAME_API UClass* StaticClass<ASG_Grid>()
	{
		return ASG_Grid::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASG_Grid);
	ASG_Grid::~ASG_Grid() {}
	struct Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Grid_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Grid_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASG_Grid, ASG_Grid::StaticClass, TEXT("ASG_Grid"), &Z_Registration_Info_UClass_ASG_Grid, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASG_Grid), 772253517U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Grid_h_2822970308(TEXT("/Script/SnakeGame"),
		Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Grid_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Grid_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
