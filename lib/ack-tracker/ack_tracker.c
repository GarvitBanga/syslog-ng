/*
 * Copyright (c) 2020 One Identity
 * Copyright (c) 2020 Laszlo Budai <laszlo.budai@outlook.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */

#include "ack_tracker.h"
#include "instant_ack_tracker.h"
#include "consecutive_ack_tracker.h"

AckTracker *
ack_tracker_new(LogSource *source, AckTrackerType type)
{
  switch (type)
    {
    case ACK_INSTANT:
      return instant_ack_tracker_new(source);
    case ACK_INSTANT_BOOKMARKLESS:
      return instant_ack_tracker_bookmarkless_new(source);
    case ACK_CONSECUTIVE:
      return consecutive_ack_tracker_new(source);
    default:
      g_assert_not_reached();
    }
}

