// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Public/Framework/GameWorld/SG_Snake.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSG_Snake() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Snake();
	SNAKEGAME_API UClass* Z_Construct_UClass_ASG_Snake_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References
	void ASG_Snake::StaticRegisterNativesASG_Snake()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASG_Snake);
	UClass* Z_Construct_UClass_ASG_Snake_NoRegister()
	{
		return ASG_Snake::StaticClass();
	}
	struct Z_Construct_UClass_ASG_Snake_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SnakeHeadClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_SnakeHeadClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SnakeBodyClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_SnakeBodyClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SnakeLinks_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SnakeLinks_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SnakeLinks;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASG_Snake_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SnakeGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Snake_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Snake_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Framework/GameWorld/SG_Snake.h" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Snake.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeHeadClass_MetaData[] = {
		{ "Category", "SG_Snake" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Snake.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeHeadClass = { "SnakeHeadClass", nullptr, (EPropertyFlags)0x0024080000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Snake, SnakeHeadClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeHeadClass_MetaData), Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeHeadClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeBodyClass_MetaData[] = {
		{ "Category", "SG_Snake" },
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Snake.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeBodyClass = { "SnakeBodyClass", nullptr, (EPropertyFlags)0x0024080000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Snake, SnakeBodyClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeBodyClass_MetaData), Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeBodyClass_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeLinks_Inner = { "SnakeLinks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeLinks_MetaData[] = {
		{ "ModuleRelativePath", "Public/Framework/GameWorld/SG_Snake.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeLinks = { "SnakeLinks", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASG_Snake, SnakeLinks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeLinks_MetaData), Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeLinks_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASG_Snake_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeHeadClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeBodyClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeLinks_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASG_Snake_Statics::NewProp_SnakeLinks,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASG_Snake_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASG_Snake>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASG_Snake_Statics::ClassParams = {
		&ASG_Snake::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASG_Snake_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Snake_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Snake_Statics::Class_MetaDataParams), Z_Construct_UClass_ASG_Snake_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASG_Snake_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASG_Snake()
	{
		if (!Z_Registration_Info_UClass_ASG_Snake.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASG_Snake.OuterSingleton, Z_Construct_UClass_ASG_Snake_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASG_Snake.OuterSingleton;
	}
	template<> SNAKEGAME_API UClass* StaticClass<ASG_Snake>()
	{
		return ASG_Snake::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASG_Snake);
	ASG_Snake::~ASG_Snake() {}
	struct Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Snake_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Snake_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASG_Snake, ASG_Snake::StaticClass, TEXT("ASG_Snake"), &Z_Registration_Info_UClass_ASG_Snake, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASG_Snake), 3071736558U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Snake_h_678324016(TEXT("/Script/SnakeGame"),
		Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Snake_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_darr_jorge_Projects_Unreal_SnakeGame_SnakeGame_Source_SnakeGame_Public_Framework_GameWorld_SG_Snake_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
