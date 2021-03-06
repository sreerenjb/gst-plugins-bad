/*
 * Copyright (C) 2008 Ole André Vadla Ravnås <ole.andre.ravnas@tandberg.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_WASAPI_UTIL_H__
#define __GST_WASAPI_UTIL_H__

#include <gst/gst.h>
#include <gst/audio/audio.h>
#include <gst/audio/gstaudiosrc.h>
#include <gst/audio/gstaudiosink.h>

#include <audioclient.h>

/* Device role enum property */
typedef enum
{
  GST_WASAPI_DEVICE_ROLE_CONSOLE,
  GST_WASAPI_DEVICE_ROLE_MULTIMEDIA,
  GST_WASAPI_DEVICE_ROLE_COMMS
} GstWasapiDeviceRole;
#define GST_WASAPI_DEVICE_TYPE_ROLE (gst_wasapi_device_role_get_type())
GType gst_wasapi_device_role_get_type (void);

/* Utilities */

gint gst_wasapi_device_role_to_erole (gint role);

gint gst_wasapi_erole_to_device_role (gint erole);

const gchar *gst_wasapi_util_hresult_to_string (HRESULT hr);

gboolean
gst_wasapi_util_get_device_client (GstElement * element,
    gboolean capture,
    gint role, const wchar_t * device_name, IAudioClient ** ret_client);

gboolean gst_wasapi_util_get_render_client (GstElement * element,
    IAudioClient * client, IAudioRenderClient ** ret_render_client);

gboolean gst_wasapi_util_get_capture_client (GstElement * element,
    IAudioClient * client, IAudioCaptureClient ** ret_capture_client);

gboolean gst_wasapi_util_get_clock (GstElement * element,
    IAudioClient * client, IAudioClock ** ret_clock);

GstCaps *gst_wasapi_util_waveformatex_to_caps (WAVEFORMATEXTENSIBLE * format,
    GstCaps * template_caps);

#endif /* __GST_WASAPI_UTIL_H__ */
