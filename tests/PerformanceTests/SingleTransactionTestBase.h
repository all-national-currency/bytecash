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

#include "CryptoNoteCore/Account.h"
#include "CryptoNoteCore/CryptoNoteBasic.h"
#include "CryptoNoteCore/CryptoNoteFormatUtils.h"

#include <Logging/LoggerGroup.h>

class single_tx_test_base
{
public:
  bool init()
  {
    using namespace CryptoNote;

    Currency currency = CurrencyBuilder(m_nullLog).currency();
    m_bob.generate();

    if (!currency.constructMinerTx(0, 0, 0, 2, 0, m_bob.getAccountKeys().address, m_tx))
      return false;

    m_tx_pub_key = getTransactionPublicKeyFromExtra(m_tx.extra);
    return true;
  }

protected:

  Logging::LoggerGroup m_nullLog;
  CryptoNote::AccountBase m_bob;
  CryptoNote::Transaction m_tx;
  Crypto::PublicKey m_tx_pub_key;
};