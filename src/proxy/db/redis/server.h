/*  Copyright (C) 2014-2018 FastoGT. All right reserved.

    This file is part of FastoNoSQL.

    FastoNoSQL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoNoSQL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoNoSQL.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "proxy/connection_settings/iconnection_settings.h"  // for IConnectionSettingsBaseSPtr
#include "proxy/server/iserver_remote.h"                     // for IServerRemote

#include <fastonosql/core/module_info.h>

namespace fastonosql {
namespace proxy {
namespace redis {

class Server : public IServerRemote {
  Q_OBJECT
 public:
  explicit Server(IConnectionSettingsBaseSPtr settings);
  virtual ~Server();

  virtual core::ServerTypes GetRole() const override;
  virtual core::ServerMode GetMode() const override;
  virtual core::ServerState GetState() const override;
  virtual common::net::HostAndPort GetHost() const override;
#if defined(PRO_VERSION)
 Q_SIGNALS:
  void ModuleLoaded(core::ModuleInfo module);
  void ModuleUnLoaded(core::ModuleInfo module);

 private Q_SLOTS:
  void LoadModule(core::ModuleInfo module);
  void UnLoadModule(core::ModuleInfo module);
#endif
 protected:
  virtual void HandleLoadServerInfoEvent(events::ServerInfoResponceEvent* ev) override;

 private:
  virtual IDatabaseSPtr CreateDatabase(core::IDataBaseInfoSPtr info) override;
  core::ServerTypes role_;
  core::ServerMode mode_;
};

}  // namespace redis
}  // namespace proxy
}  // namespace fastonosql
