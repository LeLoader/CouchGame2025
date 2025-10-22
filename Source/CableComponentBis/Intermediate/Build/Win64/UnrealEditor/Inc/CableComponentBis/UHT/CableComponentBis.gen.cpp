// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CableComponentBis/Classes/CableComponentBis.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCableComponentBis() {}

// Begin Cross Module References
CABLECOMPONENTBIS_API UClass* Z_Construct_UClass_UCableComponentBis();
CABLECOMPONENTBIS_API UClass* Z_Construct_UClass_UCableComponentBis_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMeshComponent();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentReference();
UPackage* Z_Construct_UPackage__Script_CableComponentBis();
// End Cross Module References

// Begin Class UCableComponentBis Function GetAttachedActor
struct Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics
{
	struct CableComponentBis_eventGetAttachedActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gets the Actor that the cable is attached to **/" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the Actor that the cable is attached to *" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventGetAttachedActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCableComponentBis, nullptr, "GetAttachedActor", nullptr, nullptr, Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::CableComponentBis_eventGetAttachedActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::CableComponentBis_eventGetAttachedActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCableComponentBis_GetAttachedActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCableComponentBis_GetAttachedActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCableComponentBis::execGetAttachedActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetAttachedActor();
	P_NATIVE_END;
}
// End Class UCableComponentBis Function GetAttachedActor

// Begin Class UCableComponentBis Function GetAttachedComponent
struct Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics
{
	struct CableComponentBis_eventGetAttachedComponent_Parms
	{
		USceneComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gets the specific USceneComponent that the cable is attached to **/" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the specific USceneComponent that the cable is attached to *" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventGetAttachedComponent_Parms, ReturnValue), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCableComponentBis, nullptr, "GetAttachedComponent", nullptr, nullptr, Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::CableComponentBis_eventGetAttachedComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::CableComponentBis_eventGetAttachedComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCableComponentBis::execGetAttachedComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USceneComponent**)Z_Param__Result=P_THIS->GetAttachedComponent();
	P_NATIVE_END;
}
// End Class UCableComponentBis Function GetAttachedComponent

// Begin Class UCableComponentBis Function GetCableParticleLocations
struct Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics
{
	struct CableComponentBis_eventGetCableParticleLocations_Parms
	{
		TArray<FVector> Locations;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get array of locations of particles (in world space) making up the cable simulation. */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get array of locations of particles (in world space) making up the cable simulation." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventGetCableParticleLocations_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::NewProp_Locations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::NewProp_Locations,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCableComponentBis, nullptr, "GetCableParticleLocations", nullptr, nullptr, Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::CableComponentBis_eventGetCableParticleLocations_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::CableComponentBis_eventGetCableParticleLocations_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCableComponentBis::execGetCableParticleLocations)
{
	P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetCableParticleLocations(Z_Param_Out_Locations);
	P_NATIVE_END;
}
// End Class UCableComponentBis Function GetCableParticleLocations

// Begin Class UCableComponentBis Function GetFullLength
struct Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics
{
	struct CableComponentBis_eventGetFullLength_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get the sum of the length of each segments */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the sum of the length of each segments" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventGetFullLength_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCableComponentBis, nullptr, "GetFullLength", nullptr, nullptr, Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::CableComponentBis_eventGetFullLength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::CableComponentBis_eventGetFullLength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCableComponentBis_GetFullLength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCableComponentBis_GetFullLength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCableComponentBis::execGetFullLength)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetFullLength();
	P_NATIVE_END;
}
// End Class UCableComponentBis Function GetFullLength

// Begin Class UCableComponentBis Function SetAttachEndTo
struct Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics
{
	struct CableComponentBis_eventSetAttachEndTo_Parms
	{
		AActor* Actor;
		FName ComponentProperty;
		FName SocketName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Attaches the end of the cable to a specific Component within an Actor **/" },
#endif
		{ "CPP_Default_SocketName", "None" },
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attaches the end of the cable to a specific Component within an Actor *" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ComponentProperty;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventSetAttachEndTo_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::NewProp_ComponentProperty = { "ComponentProperty", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventSetAttachEndTo_Parms, ComponentProperty), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventSetAttachEndTo_Parms, SocketName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::NewProp_ComponentProperty,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::NewProp_SocketName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCableComponentBis, nullptr, "SetAttachEndTo", nullptr, nullptr, Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::CableComponentBis_eventSetAttachEndTo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::CableComponentBis_eventSetAttachEndTo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCableComponentBis::execSetAttachEndTo)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_GET_PROPERTY(FNameProperty,Z_Param_ComponentProperty);
	P_GET_PROPERTY(FNameProperty,Z_Param_SocketName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAttachEndTo(Z_Param_Actor,Z_Param_ComponentProperty,Z_Param_SocketName);
	P_NATIVE_END;
}
// End Class UCableComponentBis Function SetAttachEndTo

// Begin Class UCableComponentBis Function SetAttachEndToComponent
struct Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics
{
	struct CableComponentBis_eventSetAttachEndToComponent_Parms
	{
		USceneComponent* Component;
		FName SocketName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Attaches the end of the cable to a specific Component **/" },
#endif
		{ "CPP_Default_SocketName", "None" },
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attaches the end of the cable to a specific Component *" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Component_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Component;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::NewProp_Component = { "Component", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventSetAttachEndToComponent_Parms, Component), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Component_MetaData), NewProp_Component_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CableComponentBis_eventSetAttachEndToComponent_Parms, SocketName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::NewProp_Component,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::NewProp_SocketName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCableComponentBis, nullptr, "SetAttachEndToComponent", nullptr, nullptr, Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::CableComponentBis_eventSetAttachEndToComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::CableComponentBis_eventSetAttachEndToComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCableComponentBis::execSetAttachEndToComponent)
{
	P_GET_OBJECT(USceneComponent,Z_Param_Component);
	P_GET_PROPERTY(FNameProperty,Z_Param_SocketName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAttachEndToComponent(Z_Param_Component,Z_Param_SocketName);
	P_NATIVE_END;
}
// End Class UCableComponentBis Function SetAttachEndToComponent

// Begin Class UCableComponentBis
void UCableComponentBis::StaticRegisterNativesUCableComponentBis()
{
	UClass* Class = UCableComponentBis::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAttachedActor", &UCableComponentBis::execGetAttachedActor },
		{ "GetAttachedComponent", &UCableComponentBis::execGetAttachedComponent },
		{ "GetCableParticleLocations", &UCableComponentBis::execGetCableParticleLocations },
		{ "GetFullLength", &UCableComponentBis::execGetFullLength },
		{ "SetAttachEndTo", &UCableComponentBis::execSetAttachEndTo },
		{ "SetAttachEndToComponent", &UCableComponentBis::execSetAttachEndToComponent },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCableComponentBis);
UClass* Z_Construct_UClass_UCableComponentBis_NoRegister()
{
	return UCableComponentBis::StaticClass();
}
struct Z_Construct_UClass_UCableComponentBis_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Rendering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Component that allows you to specify custom triangle mesh geometry */" },
#endif
		{ "HideCategories", "Object Physics Activation Components|Activation Mobility Trigger" },
		{ "IncludePath", "CableComponentBis.h" },
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component that allows you to specify custom triangle mesh geometry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAttachStart_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *\x09Should we fix the start to something, or leave it free.\n\x09 *\x09If false, component transform is just used for initial location of start of cable\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we fix the start to something, or leave it free.\nIf false, component transform is just used for initial location of start of cable" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAttachEnd_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 *\x09Should we fix the end to something (using AttachEndTo and EndLocation), or leave it free. \n\x09 *\x09If false, AttachEndTo and EndLocation are just used for initial location of end of cable\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we fix the end to something (using AttachEndTo and EndLocation), or leave it free.\nIf false, AttachEndTo and EndLocation are just used for initial location of end of cable" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttachEndTo_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Actor or Component that the defines the end position of the cable */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actor or Component that the defines the end position of the cable" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttachEndToSocketName_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Socket name on the AttachEndTo component to attach to */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Socket name on the AttachEndTo component to attach to" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndLocation_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** End location of cable, relative to AttachEndTo (or AttachEndToSocketName) if specified, otherwise relative to cable component. */" },
#endif
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "End location of cable, relative to AttachEndTo (or AttachEndToSocketName) if specified, otherwise relative to cable component." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CableLength_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rest length of the cable */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rest length of the cable" },
#endif
		{ "UIMax", "1000.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumSegments_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How many segments the cable has */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How many segments the cable has" },
#endif
		{ "UIMax", "1000" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubstepTime_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMin", "0.005" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Controls the simulation substep time for the cable */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Controls the simulation substep time for the cable" },
#endif
		{ "UIMax", "0.1" },
		{ "UIMin", "0.005" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolverIterations_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMax", "16" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The number of solver iterations controls how 'stiff' the cable is */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The number of solver iterations controls how 'stiff' the cable is" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebug_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show debug sphere on particle positions. */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show debug sphere on particle positions." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableStiffness_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Add stiffness constraints to cable. */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add stiffness constraints to cable." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseSubstepping_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When false, will still wait for SubstepTime to elapse before updating, but will only run the cable simulation once using all of accumulated simulation time */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When false, will still wait for SubstepTime to elapse before updating, but will only run the cable simulation once using all of accumulated simulation time" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipCableUpdateWhenNotVisible_MetaData[] = {
		{ "Category", "Cable" },
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered_MetaData[] = {
		{ "Category", "Cable" },
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableCollision_MetaData[] = {
		{ "Category", "Cable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 *\x09""EXPERIMENTAL. Perform sweeps for each cable particle, each substep, to avoid collisions with the world. \n\x09 *\x09Uses the Collision Preset on the component to determine what is collided with.\n\x09 *\x09This greatly increases the cost of the cable simulation.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EXPERIMENTAL. Perform sweeps for each cable particle, each substep, to avoid collisions with the world.\nUses the Collision Preset on the component to determine what is collided with.\nThis greatly increases the cost of the cable simulation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionFriction_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If collision is enabled, control how much sliding friction is applied when cable is in contact. */" },
#endif
		{ "EditCondition", "bEnableCollision" },
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If collision is enabled, control how much sliding friction is applied when cable is in contact." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CableForce_MetaData[] = {
		{ "Category", "Cable Forces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Force vector (world space) applied to all particles in cable. */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Force vector (world space) applied to all particles in cable." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CableGravityScale_MetaData[] = {
		{ "Category", "Cable Forces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scaling applied to world gravity affecting this cable. */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scaling applied to world gravity affecting this cable." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CableWidth_MetaData[] = {
		{ "Category", "Cable Rendering" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How wide the cable geometry is */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How wide the cable geometry is" },
#endif
		{ "UIMax", "50.0" },
		{ "UIMin", "0.01" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumSides_MetaData[] = {
		{ "Category", "Cable Rendering" },
		{ "ClampMax", "16" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of sides of the cable geometry */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of sides of the cable geometry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TileMaterial_MetaData[] = {
		{ "Category", "Cable Rendering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How many times to repeat the material along the length of the cable */" },
#endif
		{ "ModuleRelativePath", "Classes/CableComponentBis.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How many times to repeat the material along the length of the cable" },
#endif
		{ "UIMax", "8" },
		{ "UIMin", "0.1" },
	};
#endif // WITH_METADATA
	static void NewProp_bAttachStart_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttachStart;
	static void NewProp_bAttachEnd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttachEnd;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttachEndTo;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AttachEndToSocketName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EndLocation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CableLength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumSegments;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SubstepTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SolverIterations;
	static void NewProp_bShowDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebug;
	static void NewProp_bEnableStiffness_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableStiffness;
	static void NewProp_bUseSubstepping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseSubstepping;
	static void NewProp_bSkipCableUpdateWhenNotVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipCableUpdateWhenNotVisible;
	static void NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered;
	static void NewProp_bEnableCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableCollision;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CollisionFriction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CableForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CableGravityScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CableWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumSides;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCableComponentBis_GetAttachedActor, "GetAttachedActor" }, // 3975743658
		{ &Z_Construct_UFunction_UCableComponentBis_GetAttachedComponent, "GetAttachedComponent" }, // 3695328427
		{ &Z_Construct_UFunction_UCableComponentBis_GetCableParticleLocations, "GetCableParticleLocations" }, // 72936830
		{ &Z_Construct_UFunction_UCableComponentBis_GetFullLength, "GetFullLength" }, // 630289798
		{ &Z_Construct_UFunction_UCableComponentBis_SetAttachEndTo, "SetAttachEndTo" }, // 82733471
		{ &Z_Construct_UFunction_UCableComponentBis_SetAttachEndToComponent, "SetAttachEndToComponent" }, // 1263123618
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCableComponentBis>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachStart_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bAttachStart = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachStart = { "bAttachStart", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachStart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAttachStart_MetaData), NewProp_bAttachStart_MetaData) };
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachEnd_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bAttachEnd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachEnd = { "bAttachEnd", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachEnd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAttachEnd_MetaData), NewProp_bAttachEnd_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_AttachEndTo = { "AttachEndTo", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, AttachEndTo), Z_Construct_UScriptStruct_FComponentReference, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttachEndTo_MetaData), NewProp_AttachEndTo_MetaData) }; // 3869904073
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_AttachEndToSocketName = { "AttachEndToSocketName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, AttachEndToSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttachEndToSocketName_MetaData), NewProp_AttachEndToSocketName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_EndLocation = { "EndLocation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, EndLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndLocation_MetaData), NewProp_EndLocation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableLength = { "CableLength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, CableLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CableLength_MetaData), NewProp_CableLength_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_NumSegments = { "NumSegments", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, NumSegments), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumSegments_MetaData), NewProp_NumSegments_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_SubstepTime = { "SubstepTime", nullptr, (EPropertyFlags)0x0010040000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, SubstepTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubstepTime_MetaData), NewProp_SubstepTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_SolverIterations = { "SolverIterations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, SolverIterations), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolverIterations_MetaData), NewProp_SolverIterations_MetaData) };
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bShowDebug_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bShowDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bShowDebug = { "bShowDebug", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bShowDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebug_MetaData), NewProp_bShowDebug_MetaData) };
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableStiffness_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bEnableStiffness = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableStiffness = { "bEnableStiffness", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableStiffness_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableStiffness_MetaData), NewProp_bEnableStiffness_MetaData) };
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bUseSubstepping_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bUseSubstepping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bUseSubstepping = { "bUseSubstepping", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bUseSubstepping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseSubstepping_MetaData), NewProp_bUseSubstepping_MetaData) };
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotVisible_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bSkipCableUpdateWhenNotVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotVisible = { "bSkipCableUpdateWhenNotVisible", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipCableUpdateWhenNotVisible_MetaData), NewProp_bSkipCableUpdateWhenNotVisible_MetaData) };
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bSkipCableUpdateWhenNotOwnerRecentlyRendered = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered = { "bSkipCableUpdateWhenNotOwnerRecentlyRendered", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered_MetaData), NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered_MetaData) };
void Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableCollision_SetBit(void* Obj)
{
	((UCableComponentBis*)Obj)->bEnableCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableCollision = { "bEnableCollision", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCableComponentBis), &Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableCollision_MetaData), NewProp_bEnableCollision_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CollisionFriction = { "CollisionFriction", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, CollisionFriction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionFriction_MetaData), NewProp_CollisionFriction_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableForce = { "CableForce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, CableForce), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CableForce_MetaData), NewProp_CableForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableGravityScale = { "CableGravityScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, CableGravityScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CableGravityScale_MetaData), NewProp_CableGravityScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableWidth = { "CableWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, CableWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CableWidth_MetaData), NewProp_CableWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_NumSides = { "NumSides", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, NumSides), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumSides_MetaData), NewProp_NumSides_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCableComponentBis_Statics::NewProp_TileMaterial = { "TileMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCableComponentBis, TileMaterial), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TileMaterial_MetaData), NewProp_TileMaterial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCableComponentBis_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bAttachEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_AttachEndTo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_AttachEndToSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_EndLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_NumSegments,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_SubstepTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_SolverIterations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bShowDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableStiffness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bUseSubstepping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bSkipCableUpdateWhenNotOwnerRecentlyRendered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_bEnableCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CollisionFriction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableGravityScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_CableWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_NumSides,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCableComponentBis_Statics::NewProp_TileMaterial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCableComponentBis_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCableComponentBis_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMeshComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CableComponentBis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCableComponentBis_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCableComponentBis_Statics::ClassParams = {
	&UCableComponentBis::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCableComponentBis_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCableComponentBis_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCableComponentBis_Statics::Class_MetaDataParams), Z_Construct_UClass_UCableComponentBis_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCableComponentBis()
{
	if (!Z_Registration_Info_UClass_UCableComponentBis.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCableComponentBis.OuterSingleton, Z_Construct_UClass_UCableComponentBis_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCableComponentBis.OuterSingleton;
}
template<> CABLECOMPONENTBIS_API UClass* StaticClass<UCableComponentBis>()
{
	return UCableComponentBis::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCableComponentBis);
UCableComponentBis::~UCableComponentBis() {}
// End Class UCableComponentBis

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_somso_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCableComponentBis, UCableComponentBis::StaticClass, TEXT("UCableComponentBis"), &Z_Registration_Info_UClass_UCableComponentBis, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCableComponentBis), 3388968478U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_somso_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_2864378534(TEXT("/Script/CableComponentBis"),
	Z_CompiledInDeferFile_FID_Users_somso_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_somso_Documents_Unreal_Projects_CouchGame2025_Source_CableComponentBis_Source_CableComponentBis_Classes_CableComponentBis_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
