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
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASG_Pawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASG_Pawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASG_Pawn_Statics::ClassParams = {
		&ASG_Pawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Pawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ASG_Pawn_Statics::Class_MetaDataParams)
	};
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
		{ Z_Construct_UClass_ASG_Pawn, ASG_Pawn::StaticClass, TEXT("ASG_Pawn"), &Z_Registration_Info_UClass_ASG_Pawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASG_Pawn), 1070923367U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_3355396148(TEXT("/Script/SnakeGame"),
		Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Pawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
