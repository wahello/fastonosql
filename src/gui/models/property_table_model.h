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

#include <common/qt/gui/base/table_model.h>  // for TableModel

#include <fastonosql/core/server_property_info.h>  // for property_t

namespace fastonosql {
namespace gui {

class PropertyTableModel : public common::qt::gui::TableModel {
  Q_OBJECT

 public:
  enum Columns : uint8_t { kKey = 0, kValue = 1, kColumnsCount = 2 };
  typedef common::qt::gui::TableModel base_class;
  explicit PropertyTableModel(QObject* parent = Q_NULLPTR);

  QVariant data(const QModelIndex& index, int role) const override;
  bool setData(const QModelIndex& index, const QVariant& value, int role) override;
  Qt::ItemFlags flags(const QModelIndex& index) const override;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

  int columnCount(const QModelIndex& parent) const override;

 public Q_SLOTS:
  void changeProperty(const core::property_t& pr);
  void insertProperty(const core::property_t& property);

 Q_SIGNALS:
  void propertyChanged(const core::property_t& pr);
};

}  // namespace gui
}  // namespace fastonosql