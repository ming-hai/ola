/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * EuroliteProOutputPort.h
 * The output port for a EurolitePro device.
 * Copyright (C) 2011 Simon Newton & Harry F
 * Eurolite Pro USB DMX ArtNo. 51860120
 */

#ifndef PLUGINS_USBDMX_EUROLITEPROOUTPUTPORT_H_
#define PLUGINS_USBDMX_EUROLITEPROOUTPUTPORT_H_

#include <string>
#include "ola/base/Macro.h"
#include "ola/DmxBuffer.h"
#include "olad/Port.h"

namespace ola {
namespace plugin {
namespace usbdmx {

class EuroliteProDevice;

class EuroliteProOutputPort: public BasicOutputPort {
 public:
  /**
   * @brief Create a new AnymaOutputPort.
   */
  EuroliteProOutputPort(class EuroliteProDevice *parent,
                        unsigned int id,
                        class EuroliteProWidget *widget);

  /**
   * @brief Cleanup.
   */
  ~EuroliteProOutputPort();

  bool WriteDMX(const DmxBuffer &buffer, uint8_t priority);
  std::string Description() const { return ""; }

 private:
  class EuroliteProWidget* const m_widget;

  DISALLOW_COPY_AND_ASSIGN(EuroliteProOutputPort);
};
}  // namespace usbdmx
}  // namespace plugin
}  // namespace ola
#endif  // PLUGINS_USBDMX_EUROLITEPROOUTPUTPORT_H_
