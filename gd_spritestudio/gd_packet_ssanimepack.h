﻿/*!
* \file		gd_packet_ssanimepack.h
* \author	CRI Middleware Co., Ltd.
*/
#ifndef GD_PACKET_SSANIMEPACK_H
#define GD_PACKET_SSANIMEPACK_H

#include "gd_macros.h"

#ifdef GD_V4
#include "core/io/stream_peer.h"
#define	PoolByteArray	PackedByteArray
#endif
#ifdef GD_V3
#include "core/io/stream_peer.h"
#endif

#include "SpriteStudio6-SDK/Common/Loader/ssloader_ssae.h"

#include "ss_macros.h"

SsSdkUsing

class GdPacketSsAnimePack : public StreamPeerBuffer
{
public :
	GdPacketSsAnimePack();
	virtual ~GdPacketSsAnimePack();

	bool write( const String& strRaw );

	bool read( SsAnimePack* pAnimePack, const PoolByteArray& bytes );

	PoolByteArray getBytes() const;
};

#endif // GD_PACKET_SSANIMEPACK_H
