// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Public/Framework/GameWorld/SG_Pawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSG_Pawn() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Pawn();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Pawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References
	void ASG_Pawn::StaticRegisterNativesASG_Pawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASG_Pawn);
	UClass* Z_Construct_UClass_ASG_Pawn_NoRegister()
	{
		return ASG_Pawn::StaticClass();
	}
	struct Z_Construct_UClass_ASG_Pawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASG_Pawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_SnakeGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Pawn_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Pawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Framework/GameWorld/SG_Pawn.h" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Pawn.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Pawn_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "Category", "SG_Pawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Pawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASG_Pawn_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Pawn, CameraBoom), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Pawn_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_ASG_Pawn_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Pawn_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "SG_Pawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Pawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASG_Pawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Pawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Pawn_Statics::NewProp_Camera_MetaData), Z_Construct_UClass_ASG_Pawn_Statics::NewProp_Camera_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASG_Pawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Pawn_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Pawn_Statics::NewProp_Camera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASG_Pawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASG_Pawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASG_Pawn_Statics::ClassParams = {
		&ASG_Pawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASG_Pawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Pawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Pawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ASG_Pawn_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Pawn_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASG_Pawn()
	{
		if (!Z_Registration_Info_UClass_ASG_Pawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASG_Pawn.OuterSingleton, Z_Construct_UClass_ASG_Pawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASG_Pawn.OuterSingleton;
	}
	template<> SNAKEGAME_API UClass* StaticClass<ASG_Pawn>()
	{
		return ASG_Pawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASG_Pawn);
	ASG_Pawn::~ASG_Pawn() {}
	struct Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASG_Pawn, ASG_Pawn::StaticClass, TEXT("ASG_Pawn"), &Z_Registration_Info_UClass_ASG_Pawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASG_Pawn), 1854128123U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_1699342204(TEXT("/Script/SnakeGame"),
		Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
