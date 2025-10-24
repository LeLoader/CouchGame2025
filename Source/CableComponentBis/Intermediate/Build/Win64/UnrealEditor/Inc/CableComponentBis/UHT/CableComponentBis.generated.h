// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CableComponentBis.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class USceneComponent;
#ifdef CABLECOMPONENTBIS_CableComponentBis_generated_h
#error "CableComponentBis.generated.h already included, missing '#pragma once' in CableComponentBis.h"
#endif
#define CABLECOMPONENTBIS_CableComponentBis_generated_h

#define FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_35_RPC_WRAPPERS \
	DECLARE_FUNCTION(execGetFullLength); \
	DECLARE_FUNCTION(execGetCableParticleLocations); \
	DECLARE_FUNCTION(execGetAttachedComponent); \
	DECLARE_FUNCTION(execGetAttachedActor); \
	DECLARE_FUNCTION(execSetAttachEndTo); \
	DECLARE_FUNCTION(execSetAttachEndToComponent);


#define FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_35_INCLASS \
private: \
	static void StaticRegisterNativesUCableComponentBis(); \
	friend struct Z_Construct_UClass_UCableComponentBis_Statics; \
public: \
	DECLARE_CLASS(UCableComponentBis, UMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CableComponentBis"), NO_API) \
	DECLARE_SERIALIZER(UCableComponentBis)


#define FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_35_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCableComponentBis(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCableComponentBis) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCableComponentBis); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCableComponentBis); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCableComponentBis(UCableComponentBis&&); \
	UCableComponentBis(const UCableComponentBis&); \
public: \
	NO_API virtual ~UCableComponentBis();


#define FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_32_PROLOG
#define FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_35_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_35_RPC_WRAPPERS \
	FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_35_INCLASS \
	FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_35_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CABLECOMPONENTBIS_API UClass* StaticClass<class UCableComponentBis>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Alexandre_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
