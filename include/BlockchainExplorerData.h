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

#include <array>
#include <string>
#include <vector>

#include "CryptoTypes.h"

#include <boost/variant.hpp>

namespace CryptoNote {

enum class TransactionRemoveReason : uint8_t 
{ 
  INCLUDED_IN_BLOCK = 0, 
  TIMEOUT = 1
};

struct TransactionOutputToKeyDetails {
  Crypto::PublicKey txOutKey;
};

struct TransactionOutputMultisignatureDetails {
  std::vector<Crypto::PublicKey> keys;
  uint32_t requiredSignatures;
};

struct TransactionOutputDetails {
  uint64_t amount;
  uint32_t globalIndex;

  boost::variant<
    TransactionOutputToKeyDetails,
    TransactionOutputMultisignatureDetails> output;
};

struct TransactionOutputReferenceDetails {
  Crypto::Hash transactionHash;
  size_t number;
};

struct TransactionInputGenerateDetails {
  uint32_t height;
};

struct TransactionInputToKeyDetails {
  std::vector<uint32_t> outputIndexes;
  Crypto::KeyImage keyImage;
  uint64_t mixin;
  TransactionOutputReferenceDetails output;
};

struct TransactionInputMultisignatureDetails {
  uint32_t signatures;
  TransactionOutputReferenceDetails output;
};

struct TransactionInputDetails {
  uint64_t amount;

  boost::variant<
    TransactionInputGenerateDetails,
    TransactionInputToKeyDetails,
    TransactionInputMultisignatureDetails> input;
};

struct TransactionExtraDetails {
  std::vector<size_t> padding;
  std::vector<Crypto::PublicKey> publicKey; 
  std::vector<std::string> nonce;
  std::vector<uint8_t> raw;
};

struct TransactionDetails {
  Crypto::Hash hash;
  uint64_t size;
  uint64_t fee;
  uint64_t totalInputsAmount;
  uint64_t totalOutputsAmount;
  uint64_t mixin;
  uint64_t unlockTime;
  uint64_t timestamp;
  Crypto::Hash paymentId;
  bool inBlockchain;
  Crypto::Hash blockHash;
  uint32_t blockHeight;
  TransactionExtraDetails extra;
  std::vector<std::vector<Crypto::Signature>> signatures;
  std::vector<TransactionInputDetails> inputs;
  std::vector<TransactionOutputDetails> outputs;
};

struct BlockDetails {
  uint8_t majorVersion;
  uint8_t minorVersion;
  uint64_t timestamp;
  Crypto::Hash prevBlockHash;
  uint32_t nonce;
  bool isOrphaned;
  uint32_t height;
  Crypto::Hash hash;
  uint64_t difficulty;
  uint64_t reward;
  uint64_t baseReward;
  uint64_t blockSize;
  uint64_t transactionsCumulativeSize;
  uint64_t alreadyGeneratedCoins;
  uint64_t alreadyGeneratedTransactions;
  uint64_t sizeMedian;
  double penalty;
  uint64_t totalFeeAmount;
  std::vector<TransactionDetails> transactions;
};

}
