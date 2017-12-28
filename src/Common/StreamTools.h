// Copyright (c) 2017-2018, The CryptoNote developers, The ByteCash developers
//
// This file is part of ByteCash.
//
// ByteCash is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// ByteCash is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with ByteCash.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>
#include <vector>
#include <string>

namespace Common {

class IInputStream;
class IOutputStream;

void read(IInputStream& in, void* data, size_t size);
void read(IInputStream& in, int8_t& value);
void read(IInputStream& in, int16_t& value);
void read(IInputStream& in, int32_t& value);
void read(IInputStream& in, int64_t& value);
void read(IInputStream& in, uint8_t& value);
void read(IInputStream& in, uint16_t& value);
void read(IInputStream& in, uint32_t& value);
void read(IInputStream& in, uint64_t& value);
void read(IInputStream& in, std::vector<uint8_t>& data, size_t size);
void read(IInputStream& in, std::string& data, size_t size);
void readVarint(IInputStream& in, uint8_t& value);
void readVarint(IInputStream& in, uint16_t& value);
void readVarint(IInputStream& in, uint32_t& value);
void readVarint(IInputStream& in, uint64_t& value);

void write(IOutputStream& out, const void* data, size_t size);
void write(IOutputStream& out, int8_t value);
void write(IOutputStream& out, int16_t value);
void write(IOutputStream& out, int32_t value);
void write(IOutputStream& out, int64_t value);
void write(IOutputStream& out, uint8_t value);
void write(IOutputStream& out, uint16_t value);
void write(IOutputStream& out, uint32_t value);
void write(IOutputStream& out, uint64_t value);
void write(IOutputStream& out, const std::vector<uint8_t>& data);
void write(IOutputStream& out, const std::string& data);
void writeVarint(IOutputStream& out, uint64_t value);

template<typename T> T read(IInputStream& in) {
  T value;
  read(in, value);
  return value;
}

template<typename T> T read(IInputStream& in, size_t size) {
  T value;
  read(in, value, size);
  return value;
}

template<typename T> T readVarint(IInputStream& in) {
  T value;
  readVarint(in, value);
  return value;
}

};