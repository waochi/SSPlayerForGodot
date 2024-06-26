﻿/*!
* \file		gd_packet_sseffect.h
* \author	CRI Middleware Co., Ltd.
*/
#ifndef GD_PACKET_SSEFFECT_H
#define GD_PACKET_SSEFFECT_H

#include "gd_macros.h"

#ifdef GD_V4
#include "core/io/stream_peer.h"
#define	PoolByteArray	PackedByteArray
#endif
#ifdef GD_V3
#include "core/io/stream_peer.h"
#endif

#include "SpriteStudio6-SDK/Common/Loader/ssloader_ssee.h"

#include "ss_macros.h"

SsSdkUsing

class GdPacketSsEffect : public StreamPeerBuffer
{
public :
	GdPacketSsEffect();
	virtual ~GdPacketSsEffect();

	bool write( const String& strRaw );

	bool read( SsEffectFile* pEffect, const PoolByteArray& bytes );

	PoolByteArray getBytes() const;
};

#endif // GD_PACKET_SSEFFECT_H
