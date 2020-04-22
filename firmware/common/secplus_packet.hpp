/*
 * Copyright (C) 2014 Jared Boone, ShareBrained Technology, Inc.
 *
 * This file is part of PortaPack.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __SECPLUS_PACKET_H__
#define __SECPLUS_PACKET_H__

#include "baseband_packet.hpp"
#include "field_reader.hpp"

#include <cstdint>
#include <cstddef>
#include <string>

namespace secplus {

/* Security+ demodulator and decoder is a gently-modified version of that published
 * by argilo: https://github.com/argilo/secplus
 */

class Packet {
public:
	constexpr Packet(
		const Timestamp timestamp,
		const int64_t rolling,
		const int64_t fixed
	) : timestamp_ { timestamp },
		rolling_ { rolling },
		fixed_ { fixed }
	{
	}

	Timestamp timestamp() const {
		return timestamp_;
	}

	int64_t rolling() const {
		return rolling_;
	}

	int64_t fixed() const {
		return fixed_;
	}

	static Packet decode(const Timestamp timestamp, const std::array<uint8_t, 40> code);
	
private:
	const Timestamp timestamp_;
	const int64_t rolling_;
	const int64_t fixed_;
};

} /* namespace secplus */

#endif/*__SECPLUS_PACKET_H__*/
