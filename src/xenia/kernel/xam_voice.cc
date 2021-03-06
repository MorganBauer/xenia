/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/base/logging.h"
#include "xenia/emulator.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/util/shim_utils.h"
#include "xenia/kernel/xam_private.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {

dword_result_t XamVoiceIsActiveProcess() {
  // Returning 0 here will short-circuit a bunch of voice stuff.
  return 0;
}
DECLARE_XAM_EXPORT(XamVoiceIsActiveProcess, ExportTag::kStub);

dword_result_t XamVoiceCreate(unknown_t unk1,  // 0
                              unknown_t unk2,  // 0xF
                              lpdword_t out_voice_ptr) {
  // Null out the ptr.
  out_voice_ptr.Zero();
  return X_ERROR_ACCESS_DENIED;
}
DECLARE_XAM_EXPORT(XamVoiceCreate, ExportTag::kStub);

dword_result_t XamVoiceClose(lpunknown_t voice_ptr) { return 0; }
DECLARE_XAM_EXPORT(XamVoiceClose, ExportTag::kStub);

dword_result_t XamVoiceHeadsetPresent(lpunknown_t voice_ptr) { return 0; }
DECLARE_XAM_EXPORT(XamVoiceHeadsetPresent, ExportTag::kStub);

}  // namespace kernel
}  // namespace xe

void xe::kernel::xam::RegisterVoiceExports(
    xe::cpu::ExportResolver* export_resolver, KernelState* kernel_state) {}
