/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _XF_ARITHM_CONFIG_H_
#define _XF_ARITHM_CONFIG_H_

#include "hls_stream.h"
#include <ap_int.h>
#include "xf_config_params.h"
#include "common/xf_common.hpp"
#include "common/xf_utility.hpp"

#include "core/xf_arithm.hpp"

/* set the height and width */
#define HEIGHT 128
#define WIDTH 128
#if NO
#define NPC1 XF_NPPC1
#endif
#if RO
#define NPC1 XF_NPPC8
#endif

#if GRAY
#if T_8U
#define TYPE XF_8UC1
#endif
#if T_16S
#define TYPE XF_16SC1
#endif
#else
#if T_8U
#define TYPE XF_8UC3
#endif
#if T_16S
#define TYPE XF_16SC3
#endif
#endif

#if ARRAY
void arithm_accel(xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1>& imgInput1,
                  xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1>& imgInput2,
                  xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1>& imgOutput);
#endif
#if SCALAR
void arithm_accel(xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1>& imgInput1,
                  unsigned char scl[XF_CHANNELS(TYPE, NPC1)],
                  xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1>& imgOutput);
#endif
#endif // end of _XF_ARITHM_CONFIG_H_
