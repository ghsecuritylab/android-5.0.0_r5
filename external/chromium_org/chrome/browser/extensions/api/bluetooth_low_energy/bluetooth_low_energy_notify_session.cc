// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/extensions/api/bluetooth_low_energy/bluetooth_low_energy_notify_session.h"

namespace extensions {

static base::LazyInstance<BrowserContextKeyedAPIFactory<
    ApiResourceManager<BluetoothLowEnergyNotifySession> > > g_factory =
    LAZY_INSTANCE_INITIALIZER;

template <>
BrowserContextKeyedAPIFactory<
    ApiResourceManager<BluetoothLowEnergyNotifySession> >*
ApiResourceManager<BluetoothLowEnergyNotifySession>::GetFactoryInstance() {
  return g_factory.Pointer();
}

BluetoothLowEnergyNotifySession::BluetoothLowEnergyNotifySession(
    bool persistent,
    const std::string& owner_extension_id,
    scoped_ptr<device::BluetoothGattNotifySession> session)
    : ApiResource(owner_extension_id),
      persistent_(persistent),
      session_(session.release()) {
}

BluetoothLowEnergyNotifySession::~BluetoothLowEnergyNotifySession() {
}

device::BluetoothGattNotifySession*
BluetoothLowEnergyNotifySession::GetSession() const {
  return session_.get();
}

bool BluetoothLowEnergyNotifySession::IsPersistent() const {
  return persistent_;
}

}  // namespace extensions
