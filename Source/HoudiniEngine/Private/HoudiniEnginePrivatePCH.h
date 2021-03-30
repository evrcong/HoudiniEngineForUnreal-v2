/*
* Copyright (c) <2021> Side Effects Software Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. The name of Side Effects Software may not be used to endorse or
*    promote products derived from this software without specific prior
*    written permission.
*
* THIS SOFTWARE IS PROVIDED BY SIDE EFFECTS SOFTWARE "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
* NO EVENT SHALL SIDE EFFECTS SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

// Indicate we're in the HoudiniEngine module
#define HOUDINI_ENGINE
#include "HoudiniEngineRuntimePrivatePCH.h"

// HFS path definition coming from UBT/build.cs files.
#ifndef HOUDINI_ENGINE_HFS_PATH_DEFINE
	#define HOUDINI_ENGINE_HFS_PATH ""
#else
	#define HOUDINI_ENGINE_STRINGIFY_HELPER(X) #X
	#define HOUDINI_ENGINE_STRINGIFY(X) HOUDINI_ENGINE_STRINGIFY_HELPER(X)
	#define HOUDINI_ENGINE_HFS_PATH HOUDINI_ENGINE_STRINGIFY(HOUDINI_ENGINE_HFS_PATH_DEFINE)
#endif

// HFS subfolder containing HAPI lib.
#define HAPI_HFS_SUBFOLDER_WINDOWS      TEXT( "bin" )
#define HAPI_HFS_SUBFOLDER_MAC          TEXT( "dsolib" )
#define HAPI_HFS_SUBFOLDER_LINUX        TEXT( "dsolib" )

// Unreal HAPI Resources.
#define HAPI_UNREAL_RESOURCE_HOUDINI_LOGO				TEXT( "/HoudiniEngine/houdini_logo.houdini_logo" )
#define HAPI_UNREAL_RESOURCE_HOUDINI_MATERIAL			TEXT( "/HoudiniEngine/houdini_default_material.houdini_default_material" )
#define HAPI_UNREAL_RESOURCE_HOUDINI_TEMPLATE_MATERIAL	TEXT( "/HoudiniEngine/houdini_templated_material.houdini_templated_material")
#define HAPI_UNREAL_RESOURCE_BGEO_IMPORT				TEXT( "/HoudiniEngine/houdini_bgeo_import.houdini_bgeo_import" )

#define HAPI_UNREAL_RESOURCE_HOUDINI_DEFAULT_REFERENCE_MESH             TEXT("/HoudiniEngine/default_reference_static_mesh.default_reference_static_mesh")
#define HAPI_UNREAL_RESOURCE_HOUDINI_DEFAULT_REFERENCE_MESH_MATERIAL    TEXT("/HoudiniEngine/default_reference_static_mesh_material.default_reference_static_mesh_material")

// Client name so HAPI knows we're running inside unreal
#define HAPI_UNREAL_CLIENT_NAME         "unreal"

// Error checking - this macro will check the status and return specified parameter.
#define HOUDINI_CHECK_ERROR_RETURN_HELPER( HAPI_PARAM_CALL, HAPI_PARAM_RETURN, HAPI_LOG_ROUTINE ) \
    do \
    { \
        HAPI_Result ResultVariable = HAPI_PARAM_CALL; \
        if ( ResultVariable != HAPI_RESULT_SUCCESS ) \
        { \
            HAPI_LOG_ROUTINE( TEXT( "Hapi failed: %s" ), *FHoudiniEngineUtils::GetErrorDescription() ); \
            return HAPI_PARAM_RETURN; \
        } \
    } \
    while ( 0 )

#define HOUDINI_CHECK_ERROR_RETURN( HAPI_PARAM_CALL, HAPI_PARAM_RETURN ) \
    HOUDINI_CHECK_ERROR_RETURN_HELPER( HAPI_PARAM_CALL, HAPI_PARAM_RETURN, HOUDINI_LOG_ERROR )

// Simple Error checking - this macro will check the status.
#define HOUDINI_CHECK_ERROR_HELPER( HAPI_PARAM_CALL, HAPI_LOG_ROUTINE ) \
    do \
    { \
        HAPI_Result ResultVariable = HAPI_PARAM_CALL; \
        if ( ResultVariable != HAPI_RESULT_SUCCESS ) \
        { \
            HAPI_LOG_ROUTINE( TEXT( "Hapi failed: %s" ), *FHoudiniEngineUtils::GetErrorDescription() ); \
        } \
    } \
    while ( 0 )

#define HOUDINI_CHECK_ERROR( HAPI_PARAM_CALL ) \
    HOUDINI_CHECK_ERROR_HELPER( HAPI_PARAM_CALL, HOUDINI_LOG_ERROR )

// Error checking - this macro will check the status and returns it.
#define HOUDINI_CHECK_ERROR_GET_HELPER( HAPI_PARAM_RESULT, HAPI_PARAM_CALL, HAPI_LOG_ROUTINE ) \
    do \
    { \
        *HAPI_PARAM_RESULT = HAPI_PARAM_CALL; \
        if ( *HAPI_PARAM_RESULT != HAPI_RESULT_SUCCESS ) \
        { \
            HAPI_LOG_ROUTINE( TEXT( "Hapi failed: %s" ), *FHoudiniEngineUtils::GetErrorDescription() ); \
        } \
    } \
    while ( 0 )

#define HOUDINI_CHECK_ERROR_GET( HAPI_PARAM_RESULT, HAPI_PARAM_CALL ) \
    HOUDINI_CHECK_ERROR_GET_HELPER( HAPI_PARAM_RESULT, HAPI_PARAM_CALL, HOUDINI_LOG_ERROR )

// For Transform conversion between UE4 / Houdini
// Set to 0 to stop converting Houdini's coordinate space to unreal's
#define HAPI_UNREAL_CONVERT_COORDINATE_SYSTEM				1

#define HAPI_UNREAL_SCALE_FACTOR_POSITION                   100.0f
#define HAPI_UNREAL_SCALE_FACTOR_TRANSLATION                100.0f
#define HAPI_UNREAL_SCALE_FACTOR_SCALE						100.0f

#define HAPI_UNREAL_SCALE_SMALL_VALUE						KINDA_SMALL_NUMBER * 2.0f

#define HAPI_UNREAL_DEFAULT_MATERIAL_NAME                   TEXT( "default_material" )

// Attributes
#define HAPI_UNREAL_ATTRIB_POSITION							HAPI_ATTRIB_POSITION
#define HAPI_UNREAL_ATTRIB_ROTATION							"rot"
#define HAPI_UNREAL_ATTRIB_SCALE							"scale"
#define HAPI_UNREAL_ATTRIB_UNIFORM_SCALE					"pscale"
#define HAPI_UNREAL_ATTRIB_COLOR							HAPI_ATTRIB_COLOR
#define HAPI_UNREAL_ATTRIB_LIGHTMAP_COLOR					"unreal_lightmap_color"
#define HAPI_UNREAL_ATTRIB_ALPHA							"Alpha"
#define HAPI_UNREAL_ATTRIB_UV								HAPI_ATTRIB_UV
#define HAPI_UNREAL_ATTRIB_NORMAL							HAPI_ATTRIB_NORMAL
#define HAPI_UNREAL_ATTRIB_TANGENTU							HAPI_ATTRIB_TANGENT
#define HAPI_UNREAL_ATTRIB_TANGENTV							HAPI_ATTRIB_TANGENT2

#define HAPI_UNREAL_ATTRIB_LANDSCAPE_TILE					"tile"
// Always the name of the main landscape actor. 
// Names for landscape tile actors will be taken from 'unreal_output_name'.
#define HAPI_UNREAL_ATTRIB_LANDSCAPE_SHARED_ACTOR_NAME		"unreal_landscape_shared_actor_name"
// This tile_actor_type succeeds the 'unreal_landscape_streaming_proxy' (v1) attribute.
#define HAPI_UNREAL_ATTRIB_LANDSCAPE_TILE_ACTOR_TYPE		"unreal_landscape_tile_actor_type"
// This attribute is for backwards compatibility only.
#define HAPI_UNREAL_ATTRIB_LANDSCAPE_STREAMING_PROXY		"unreal_landscape_streaming_proxy"

#define HAPI_UNREAL_ATTRIB_LANDSCAPE_LAYER_MIN				"unreal_landscape_layer_min"
#define HAPI_UNREAL_ATTRIB_LANDSCAPE_LAYER_MAX				"unreal_landscape_layer_max"

// Path to the level in which an actor should be generated or which contained the input data
// "." - (Default) Generate geometry in the the current persistent world
// "Junk/Background" - Path to a Map that is relative to the current persistent world's Map.
// "/Game/Maps/Level01/Junk/Background" - Absolute path to the map in which the primitive should be output
#define HAPI_UNREAL_ATTRIB_LEVEL_PATH						"unreal_level_path"

// Path to the actor that contained the input data/should be generated
#define HAPI_UNREAL_ATTRIB_ACTOR_PATH						"unreal_actor_path"

// Path to the object plugged in a geo in
#define HAPI_UNREAL_ATTRIB_OBJECT_PATH						"unreal_object_path"

// Attributes used for data exchange between UE4 and Houdini
#define HAPI_UNREAL_ATTRIB_MATERIAL							"unreal_material"
#define HAPI_UNREAL_ATTRIB_MATERIAL_FALLBACK				"unreal_face_material"
#define HAPI_UNREAL_ATTRIB_MATERIAL_INSTANCE				"unreal_material_instance"
#define HAPI_UNREAL_ATTRIB_MATERIAL_HOLE					"unreal_material_hole"
#define HAPI_UNREAL_ATTRIB_MATERIAL_HOLE_INSTANCE			"unreal_material_hole_instance"
#define HAPI_UNREAL_ATTRIB_PHYSICAL_MATERIAL				"unreal_physical_material"
#define HAPI_UNREAL_ATTRIB_FACE_SMOOTHING_MASK				"unreal_face_smoothing_mask"
#define HAPI_UNREAL_ATTRIB_LIGHTMAP_RESOLUTION				"unreal_lightmap_resolution"
#define HAPI_UNREAL_ATTRIB_LOD_SCREENSIZE					"lod_screensize"
#define HAPI_UNREAL_ATTRIB_LOD_SCREENSIZE_PREFIX			"lod"
#define HAPI_UNREAL_ATTRIB_LOD_SCREENSIZE_POSTFIX			"_screensize"
#define HAPI_UNREAL_ATTRIB_TAG_PREFIX						"unreal_tag_"

#define HAPI_UNREAL_ATTRIB_MESH_SOCKET_PREFIX				"mesh_socket"
#define HAPI_UNREAL_ATTRIB_MESH_SOCKET_NAME					"mesh_socket_name"
#define HAPI_UNREAL_ATTRIB_MESH_SOCKET_NAME_OLD				"unreal_mesh_socket_name"
#define HAPI_UNREAL_ATTRIB_MESH_SOCKET_ACTOR				"mesh_socket_actor"
#define HAPI_UNREAL_ATTRIB_MESH_SOCKET_ACTOR_OLD			"unreal_mesh_socket_actor"
#define HAPI_UNREAL_ATTRIB_MESH_SOCKET_TAG					"mesh_socket_tag"
#define HAPI_UNREAL_ATTRIB_MESH_SOCKET_TAG_OLD				"unreal_mesh_socket_tag"

#define HAPI_UNREAL_ATTRIB_INPUT_MESH_NAME					"unreal_input_mesh_name"
#define HAPI_UNREAL_ATTRIB_INPUT_SOURCE_FILE				"unreal_input_source_file"

#define HAPI_UNREAL_ATTRIB_INSTANCE							"instance"
#define HAPI_UNREAL_ATTRIB_INSTANCE_OVERRIDE				"unreal_instance"
#define HAPI_UNREAL_ATTRIB_SPLIT_INSTANCES					"unreal_split_instances"
#define HAPI_UNREAL_ATTRIB_FOLIAGE_INSTANCER				"unreal_foliage"
#define HAPI_UNREAL_ATTRIB_INSTANCE_ROTATION				"rot"
#define HAPI_UNREAL_ATTRIB_INSTANCE_SCALE					"scale"
#define HAPI_UNREAL_ATTRIB_INSTANCE_POSITION				HAPI_ATTRIB_POSITION
#define HAPI_UNREAL_ATTRIB_INSTANCE_COLOR					"unreal_instance_color"
#define HAPI_UNREAL_ATTRIB_SPLIT_ATTR						"unreal_split_attr"
#define HAPI_UNREAL_ATTRIB_HIERARCHICAL_INSTANCED_SM		"unreal_hierarchical_instancer"
#define HAPI_UNREAL_ATTRIB_INSTANCE_NUM_CUSTOM_FLOATS		"unreal_num_custom_floats"
#define HAPI_UNREAL_ATTRIB_INSTANCE_CUSTOM_DATA_PREFIX		"unreal_per_instance_custom_data"


#define HAPI_UNREAL_ATTRIB_LANDSCAPE_TILE_NAME				 HAPI_ATTRIB_NAME
#define HAPI_UNREAL_ATTRIB_LANDSCAPE_VERTEX_INDEX		    "unreal_vertex_index"
#define HAPI_UNREAL_ATTRIB_UNIT_LANDSCAPE_LAYER				"unreal_unit_landscape_layer"
#define HAPI_UNREAL_ATTRIB_NONWEIGHTBLENDED_LAYERS			"unreal_landscape_layer_nonweightblended"
#define HAPI_UNREAL_ATTRIB_LANDSCAPE_STREAMING_PROXY		"unreal_landscape_streaming_proxy"
#define HAPI_UNREAL_ATTRIB_LANDSCAPE_LAYER_INFO				"unreal_landscape_layer_info"

#define HAPI_UNREAL_ATTRIB_GENERIC_UPROP_PREFIX				"unreal_uproperty_"
#define HAPI_UNREAL_ATTRIB_GENERIC_MAT_PARAM_PREFIX			"unreal_material_parameter_"

#define HAPI_UNREAL_ATTRIB_BAKE_FOLDER						"unreal_bake_folder"
#define HAPI_UNREAL_ATTRIB_TEMP_FOLDER						"unreal_temp_folder"
#define HAPI_UNREAL_ATTRIB_CUSTOM_OUTPUT_NAME_V1			"unreal_generated_mesh_name"
#define HAPI_UNREAL_ATTRIB_CUSTOM_OUTPUT_NAME_V2			"unreal_output_name"
#define HAPI_UNREAL_ATTRIB_BAKE_ACTOR                       "unreal_bake_actor"
#define HAPI_UNREAL_ATTRIB_BAKE_OUTLINER_FOLDER             "unreal_bake_outliner_folder"

// data tables
#define HAPI_UNREAL_ATTRIB_DATA_TABLE_PREFIX				"unreal_data_table_"
#define HAPI_UNREAL_ATTRIB_DATA_TABLE_ROWSTRUCT				"unreal_datatable_rowstruct"

// Attributes for Curve Outputs
#define HAPI_UNREAL_ATTRIB_OUTPUT_UNREAL_CURVE				"unreal_output_curve"
#define HAPI_UNREAL_ATTRIB_OUTPUT_UNREAL_CURVE_LINEAR		"unreal_output_curve_linear"
#define HAPI_UNREAL_ATTRIB_OUTPUT_UNREAL_CURVE_CLOSED		"unreal_output_curve_closed"
// We only support Unreal spline outputs for now
//#define HAPI_UNREAL_ATTRIB_OUTPUT_HOUDINI_CURVE				"houdini_output_curve"

// Geometry Node
#define HAPI_UNREAL_PARAM_TRANSLATE							"t"
#define HAPI_UNREAL_PARAM_ROTATE							"r"
#define HAPI_UNREAL_PARAM_SCALE								"s"
#define HAPI_UNREAL_PARAM_PIVOT								"p"
#define HAPI_UNREAL_PARAM_UNIFORMSCALE						"scale"

// Houdini Curve
#define HAPI_UNREAL_PARAM_CURVE_TYPE						"type"
#define HAPI_UNREAL_PARAM_CURVE_METHOD						"method"
#define HAPI_UNREAL_PARAM_CURVE_COORDS						"coords"
#define HAPI_UNREAL_PARAM_CURVE_CLOSED						"close"
#define HAPI_UNREAL_PARAM_CURVE_REVERSED					"reverse"

#define HAPI_UNREAL_PARAM_INPUT_CURVE_COORDS_DEFAULT		"0.0, 0.0, 3.0 3.0, 0.0, 3.0"

// String Params tags
#define HOUDINI_PARAMETER_STRING_REF_TAG					TEXT("unreal_ref")
#define HOUDINI_PARAMETER_STRING_REF_CLASS_TAG              TEXT("unreal_ref_class")
#define HOUDINI_PARAMETER_STRING_MULTILINE_TAG				TEXT("editor")

// Parameter tags
#define HAPI_PARAM_TAG_NOSWAP								"hengine_noswap"
#define HAPI_PARAM_TAG_FILE_READONLY						"filechooser_mode"
#define HAPI_PARAM_TAG_UNITS								"units"

// TODO: unused, remove!
#define HAPI_PARAM_TAG_ASSET_REF							"asset_ref"

// Groups
#define HAPI_UNREAL_GROUP_LOD_PREFIX						TEXT("lod")
#define HAPI_UNREAL_GROUP_SOCKET_PREFIX						TEXT("mesh_socket")
#define HAPI_UNREAL_GROUP_SOCKET_PREFIX_OLD					TEXT("socket")
//#define HAPI_UNREAL_GROUP_USER_SPLIT_PREFIX				TEXT("unreal_split")

#define HAPI_UNREAL_GROUP_GEOMETRY_NOT_COLLISION			TEXT("main_geo")

#define HAPI_UNREAL_GROUP_INVISIBLE_COLLISION_PREFIX		TEXT("collision_geo")
#define HAPI_UNREAL_GROUP_RENDERED_COLLISION_PREFIX			TEXT("rendered_collision_geo")

#define HAPI_UNREAL_GROUP_INVISIBLE_UCX_COLLISION_PREFIX	TEXT("collision_geo_ucx")
#define HAPI_UNREAL_GROUP_RENDERED_UCX_COLLISION_PREFIX		TEXT("rendered_collision_geo_ucx")

#define HAPI_UNREAL_GROUP_INVISIBLE_SIMPLE_COLLISION_PREFIX	TEXT("collision_geo_simple")
#define HAPI_UNREAL_GROUP_RENDERED_SIMPLE_COLLISION_PREFIX	TEXT("rendered_collision_geo_simple")

// Default material name.
#define HAPI_UNREAL_DEFAULT_MATERIAL_NAME                   TEXT( "default_material" )

// Various variable names used to store meta information in generated packages.
#define HAPI_UNREAL_PACKAGE_META_GENERATED_OBJECT               TEXT( "HoudiniGeneratedObject" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_NAME                 TEXT( "HoudiniGeneratedName" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_TYPE         TEXT( "HoudiniGeneratedTextureType" )
#define HAPI_UNREAL_PACKAGE_META_NODE_PATH                      TEXT( "HoudiniNodePath" )
#define HAPI_UNREAL_PACKAGE_META_BAKE_COUNTER                   TEXT( "HoudiniPackageBakeCounter" )
#define HAPI_UNREAL_PACKAGE_META_TEMP_GUID                      TEXT( "HoudiniPackageTempGUID" )

#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_NORMAL       TEXT( "N" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_DIFFUSE      TEXT( "C_A" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_SPECULAR     TEXT( "S" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_ROUGHNESS    TEXT( "R" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_METALLIC     TEXT( "M" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_EMISSIVE     TEXT( "E" )
#define HAPI_UNREAL_PACKAGE_META_GENERATED_TEXTURE_OPACITY_MASK TEXT( "O" )

// Texture planes.
#define HAPI_UNREAL_MATERIAL_TEXTURE_COLOR_ALPHA        "C A"
#define HAPI_UNREAL_MATERIAL_TEXTURE_COLOR              "C"
#define HAPI_UNREAL_MATERIAL_TEXTURE_ALPHA              "A"
#define HAPI_UNREAL_MATERIAL_TEXTURE_NORMAL             "N"

// Materials Diffuse.
#define HAPI_UNREAL_PARAM_TEXTURE_LAYERS_NUM            "ogl_numtex"

#define HAPI_UNREAL_PARAM_MAP_DIFFUSE_0                 "ogl_tex1"
#define HAPI_UNREAL_PARAM_MAP_DIFFUSE_1                 "basecolor_texture"

#define HAPI_UNREAL_PARAM_COLOR_DIFFUSE_0               "ogl_diff"
#define HAPI_UNREAL_PARAM_COLOR_DIFFUSE_1               "basecolor"

#define HAPI_UNREAL_PARAM_MAP_DIFFUSE_COLOR_SPACE       "basecolor_textureColorSpace"

// Materials Normal.
#define HAPI_UNREAL_PARAM_MAP_NORMAL_0                  "ogl_normalmap"
#define HAPI_UNREAL_PARAM_MAP_NORMAL_1                  "normalTexture"

#define HAPI_UNREAL_PARAM_MAP_NORMAL_TYPE               "ogl_normalmap_type"
#define HAPI_UNREAL_PARAM_MAP_NORMAL_TYPE_TANGENT       "Tangent Space"
#define HAPI_UNREAL_PARAM_MAP_NORMAL_TYPE_WORLD         "World Space"

#define HAPI_UNREAL_PARAM_MAP_NORMAL_COLOR_SPACE        "normalTexColorSpace"

// Materials Specular.
#define HAPI_UNREAL_PARAM_MAP_SPECULAR_0                "ogl_specmap"
#define HAPI_UNREAL_PARAM_MAP_SPECULAR_1                "reflect_texture"

#define HAPI_UNREAL_PARAM_COLOR_SPECULAR_0              "ogl_spec"
#define HAPI_UNREAL_PARAM_COLOR_SPECULAR_1              "reflect"

#define HAPI_UNREAL_PARAM_MAP_SPECULAR_COLOR_SPACE      "reflect_textureColorSpace"

// Materials Roughness.
#define HAPI_UNREAL_PARAM_MAP_ROUGHNESS_0               "ogl_roughmap"
#define HAPI_UNREAL_PARAM_MAP_ROUGHNESS_1               "rough_texture"

#define HAPI_UNREAL_PARAM_VALUE_ROUGHNESS_0             "ogl_rough"
#define HAPI_UNREAL_PARAM_VALUE_ROUGHNESS_1             "rough"

#define HAPI_UNREAL_PARAM_MAP_ROUGHNESS_COLOR_SPACE     "rough_textureColorSpace"

// Materials Metallic.
#define HAPI_UNREAL_PARAM_MAP_METALLIC                  "metallic_texture"
#define HAPI_UNREAL_PARAM_VALUE_METALLIC                "metallic"
#define HAPI_UNREAL_PARAM_MAP_METALLIC_COLOR_SPACE      "metallic_textureColorSpace"

// Materials Emissive.
#define HAPI_UNREAL_PARAM_MAP_EMISSIVE                  "emitcolor_texture"
#define HAPI_UNREAL_PARAM_MAP_EMISSIVE_COLOR_SPACE      "emitcolor_textureColorSpace"

#define HAPI_UNREAL_PARAM_VALUE_EMISSIVE_0              "ogl_emit"
#define HAPI_UNREAL_PARAM_VALUE_EMISSIVE_1              "emitcolor"

// Materials Opacity.
#define HAPI_UNREAL_PARAM_ALPHA_0                       "ogl_alpha"
#define HAPI_UNREAL_PARAM_ALPHA_1                       "opac"

#define HAPI_UNREAL_PARAM_MAP_OPACITY_0                 "ogl_opacitymap"
#define HAPI_UNREAL_PARAM_MAP_OPACITY_1                 "opaccolor_texture"

// Number of GUID characters to keep for packages
#define PACKAGE_GUID_LENGTH								8
#define PACKAGE_GUID_COMPONENT_LENGTH					12

/** Ramp related defines. **/
#define HAPI_UNREAL_RAMP_FLOAT_AXIS_X                   "position"
#define HAPI_UNREAL_RAMP_FLOAT_AXIS_Y                   "value"
#define HAPI_UNREAL_RAMP_COLOR_AXIS_X                   "position"
#define HAPI_UNREAL_RAMP_COLOR_AXIS_Y                   "color"

/** Handle types. **/
#define HAPI_UNREAL_HANDLE_TRANSFORM                    "xform"
#define HAPI_UNREAL_HANDLE_BOUNDER                      "bound"

#define HAPI_UNREAL_LANDSCAPE_HEIGHT_VOLUME_NAME		"height"

#define HAPI_UNREAL_NOTIFICATION_FADEOUT				2.0f
#define HAPI_UNREAL_NOTIFICATION_EXPIRE					2.0f

