﻿/*!
* \file		register_types.cpp
* \author	CRI Middleware Co., Ltd.
*/
#include "register_types.h"

#ifdef GD_V4
#include "core/object/class_db.h"
#endif
#ifdef GD_V3
#include "core/class_db.h"
#endif

#include "gd_node_ssplayer.h"
#include "gd_resource_ssdocument.h"
#include "gd_resource_ssplayer.h"
#include "gd_resource_ssproject.h"
#include "gd_resource_ssanimepack.h"
#include "gd_resource_sscellmap.h"
#include "gd_resource_sseffect.h"
#include "gd_loader_ssproject.h"
#include "gd_loader_ssanimepack.h"
#include "gd_loader_sscellmap.h"
#include "gd_loader_sseffect.h"
#include "gd_loader_bssproject.h"
#include "gd_loader_bssanimepack.h"
#include "gd_loader_bsscellmap.h"
#include "gd_loader_bsseffect.h"
#include "gd_saver_bssproject.h"
#include "gd_saver_bssanimepack.h"
#include "gd_saver_bsscellmap.h"
#include "gd_saver_bsseffect.h"

static Ref<GdLoaderSsProject>		s_LoaderSsProject;
static Ref<GdLoaderSsAnimePack>		s_LoaderSsAnimePack;
static Ref<GdLoaderSsCellMap>		s_LoaderSsCellMap;
static Ref<GdLoaderSsEffect>		s_LoaderSsEffect;
static Ref<GdLoaderBssProject>		s_LoaderBssProject;
static Ref<GdLoaderBssAnimePack>	s_LoaderBssAnimePack;
static Ref<GdLoaderBssCellMap>		s_LoaderBssCellMap;
static Ref<GdLoaderBssEffect>		s_LoaderBssEffect;
static Ref<GdSaverBssProject>		s_SaverBssProject;
static Ref<GdSaverBssAnimePack>		s_SaverBssAnimePack;
static Ref<GdSaverBssCellMap>		s_SaverBssCellMap;
static Ref<GdSaverBssEffect>		s_SaverBssEffect;

void register_gd_spritestudio_types()
{
	ClassDB::register_class<GdNodeSsPlayer>();

	ClassDB::register_class<GdResourceSsDocument>();
	ClassDB::register_class<GdResourceSsPlayer>();
	ClassDB::register_class<GdResourceSsProject>();
	ClassDB::register_class<GdResourceSsAnimePack>();
	ClassDB::register_class<GdResourceSsCellMap>();
	ClassDB::register_class<GdResourceSsEffect>();

#ifdef GD_V4
	s_LoaderSsProject.instantiate();
	s_LoaderSsAnimePack.instantiate();
	s_LoaderSsCellMap.instantiate();
	s_LoaderSsEffect.instantiate();
	s_LoaderBssProject.instantiate();
	s_LoaderBssAnimePack.instantiate();
	s_LoaderBssCellMap.instantiate();
	s_LoaderBssEffect.instantiate();
	s_SaverBssProject.instantiate();
	s_SaverBssAnimePack.instantiate();
	s_SaverBssCellMap.instantiate();
	s_SaverBssEffect.instantiate();
#endif
#ifdef GD_V3
	s_LoaderSsProject.instance();
	s_LoaderSsAnimePack.instance();
	s_LoaderSsCellMap.instance();
	s_LoaderSsEffect.instance();
	s_LoaderBssProject.instance();
	s_LoaderBssAnimePack.instance();
	s_LoaderBssCellMap.instance();
	s_LoaderBssEffect.instance();
	s_SaverBssProject.instance();
	s_SaverBssAnimePack.instance();
	s_SaverBssCellMap.instance();
	s_SaverBssEffect.instance();
#endif

	ResourceLoader::add_resource_format_loader( s_LoaderSsProject );
	ResourceLoader::add_resource_format_loader( s_LoaderSsAnimePack );
	ResourceLoader::add_resource_format_loader( s_LoaderSsCellMap );
	ResourceLoader::add_resource_format_loader( s_LoaderSsEffect );
	ResourceLoader::add_resource_format_loader( s_LoaderBssProject );
	ResourceLoader::add_resource_format_loader( s_LoaderBssAnimePack );
	ResourceLoader::add_resource_format_loader( s_LoaderBssCellMap );
	ResourceLoader::add_resource_format_loader( s_LoaderBssEffect );
	ResourceSaver::add_resource_format_saver( s_SaverBssProject );
	ResourceSaver::add_resource_format_saver( s_SaverBssAnimePack );
	ResourceSaver::add_resource_format_saver( s_SaverBssCellMap );
	ResourceSaver::add_resource_format_saver( s_SaverBssEffect );
}

void unregister_gd_spritestudio_types()
{
	ResourceSaver::remove_resource_format_saver( s_SaverBssEffect );
	ResourceSaver::remove_resource_format_saver( s_SaverBssCellMap );
	ResourceSaver::remove_resource_format_saver( s_SaverBssAnimePack );
	ResourceSaver::remove_resource_format_saver( s_SaverBssProject );
	ResourceLoader::remove_resource_format_loader( s_LoaderBssEffect );
	ResourceLoader::remove_resource_format_loader( s_LoaderBssCellMap );
	ResourceLoader::remove_resource_format_loader( s_LoaderBssAnimePack );
	ResourceLoader::remove_resource_format_loader( s_LoaderBssProject );
	ResourceLoader::remove_resource_format_loader( s_LoaderSsEffect );
	ResourceLoader::remove_resource_format_loader( s_LoaderSsCellMap );
	ResourceLoader::remove_resource_format_loader( s_LoaderSsAnimePack );
	ResourceLoader::remove_resource_format_loader( s_LoaderSsProject );

	s_SaverBssEffect.unref();
	s_SaverBssCellMap.unref();
	s_SaverBssAnimePack.unref();
	s_SaverBssProject.unref();
	s_LoaderBssEffect.unref();
	s_LoaderBssCellMap.unref();
	s_LoaderBssAnimePack.unref();
	s_LoaderBssProject.unref();
	s_LoaderSsEffect.unref();
	s_LoaderSsCellMap.unref();
	s_LoaderSsAnimePack.unref();
	s_LoaderSsProject.unref();
}

#ifdef GD_V4
void initialize_gd_spritestudio_module( ModuleInitializationLevel p_level )
{
	if ( p_level != MODULE_INITIALIZATION_LEVEL_SCENE ) {
		return;
	}

	register_gd_spritestudio_types();
}

void uninitialize_gd_spritestudio_module( ModuleInitializationLevel p_level )
{
	if ( p_level != MODULE_INITIALIZATION_LEVEL_SCENE ) {
		return;
	}

	unregister_gd_spritestudio_types();
}
#endif
