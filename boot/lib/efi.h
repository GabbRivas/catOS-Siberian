//
// Made by Gab Rivas 30/01/25 22:28
//
// Library that compresses all headers into a single file
//

#ifndef EFI_H
#define EFI_H

#include "headers/core/efi_core.h"
#include "headers/boot/efi_load_option.h"
#include "headers/input/efi_boot_key_data.h"
#include "headers/input/efi_key_option.h"
#include "headers/protocols/efi_device_path_protocol.h"
#include "headers/protocols/efi_boot_manager_policy_protocol.h"
#include "headers/core/efi_table_header.h"
#include "headers/input/efi_input_key.h"
#include "headers/input/efi_key_state.h"
#include "headers/input/efi_key_data.h"
#include "headers/input/efi_key_notify_function.h"
#include "headers/protocols/efi_simple_text_input_ex_protocol.h"
#include "headers/protocols/efi_simple_text_input_protocol.h"
#include "headers/protocols/simple_text_output_mode.h"
#include "headers/protocols/efi_simple_text_output_protocol.h"
#include "headers/time/efi_time.h"
#include "headers/time/efi_time_capabilities.h"
#include "headers/memory/efi_memory_descriptor.h"
#include "headers/core/efi_reset_type.h"
#include "headers/capsule/efi_capsule_block_descriptor.h"
#include "headers/capsule/efi_capsule_header.h"
#include "headers/capsule/efi_capsule_table.h"
#include "headers/memory/efi_memory_range.h"
#include "headers/memory/efi_memory_range_capsule.h"
#include "headers/memory/efi_memory_range_capsule_result.h"
#include "headers/capsule/efi_capsule_result_variable_header.h"
#include "headers/capsule/efi_capsule_result_variable_fmp.h"
#include "headers/capsule/efi_capsule_variable_result_json.h"
#include "headers/services/efi_runtime_services.h"
#include "headers/services/efi_configuration_table.h"
#include "headers/services/efi_rt_properties_table.h"
#include "headers/services/efi_event_notify.h"
#include "headers/time/efi_timer_delay.h"
#include "headers/memory/efi_allocate_type.h"
#include "headers/memory/efi_memory_type.h"
#include "headers/core/efi_interface_type.h"
#include "headers/services/efi_locate_search_type.h"
#include "headers/protocols/efi_open_protocol_information_entry.h"
#include "headers/services/efi_boot_services.h"
#include "headers/services/efi_system_table.h"

#endif
