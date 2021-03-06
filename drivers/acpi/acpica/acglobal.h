
/*
 * Copyright (C) 2000 - 2012, Intel Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 * 3. Neither the names of the above-listed copyright holders nor the names
 *    of any contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 */

#ifndef __ACGLOBAL_H__
#define __ACGLOBAL_H__

#ifdef DEFINE_ACPI_GLOBALS
#define ACPI_EXTERN
#define ACPI_INIT_GLOBAL(a,b) a=b
#else
#define ACPI_EXTERN extern
#define ACPI_INIT_GLOBAL(a,b) a
#endif

#ifdef DEFINE_ACPI_GLOBALS



u8 ACPI_INIT_GLOBAL(acpi_gbl_enable_interpreter_slack, FALSE);

/*
 * Automatically serialize ALL control methods? Default is FALSE, meaning
 * to use the Serialized/not_serialized method flags on a per method basis.
 * Only change this if the ASL code is poorly written and cannot handle
 * reentrancy even though methods are marked "NotSerialized".
 */
u8 ACPI_INIT_GLOBAL(acpi_gbl_all_methods_serialized, FALSE);

u8 ACPI_INIT_GLOBAL(acpi_gbl_create_osi_method, TRUE);

u8 ACPI_INIT_GLOBAL(acpi_gbl_use_default_register_widths, TRUE);

bool ACPI_INIT_GLOBAL(acpi_gbl_enable_aml_debug_object, FALSE);

u8 ACPI_INIT_GLOBAL(acpi_gbl_copy_dsdt_locally, FALSE);

u8 ACPI_INIT_GLOBAL(acpi_gbl_truncate_io_addresses, FALSE);

u8 ACPI_INIT_GLOBAL(acpi_gbl_disable_auto_repair, FALSE);


struct acpi_table_fadt acpi_gbl_FADT;
u32 acpi_current_gpe_count;
u32 acpi_gbl_trace_flags;
acpi_name acpi_gbl_trace_method_name;
u8 acpi_gbl_system_awake_and_running;

u8 acpi_gbl_reduced_hardware;

#endif				


ACPI_EXTERN u8 ACPI_INIT_GLOBAL(acpi_gbl_no_resource_disassembly, FALSE);



extern u32 acpi_gbl_nesting_level;

ACPI_EXTERN u32 acpi_gpe_count;
ACPI_EXTERN u32 acpi_fixed_event_count[ACPI_NUM_FIXED_EVENTS];


ACPI_EXTERN u32 acpi_gbl_original_dbg_level;
ACPI_EXTERN u32 acpi_gbl_original_dbg_layer;
ACPI_EXTERN u32 acpi_gbl_trace_dbg_level;
ACPI_EXTERN u32 acpi_gbl_trace_dbg_layer;


ACPI_EXTERN struct acpi_table_list acpi_gbl_root_table_list;

#if (!ACPI_REDUCED_HARDWARE)
ACPI_EXTERN struct acpi_table_facs *acpi_gbl_FACS;

#endif				


ACPI_EXTERN struct acpi_generic_address acpi_gbl_xpm1a_status;
ACPI_EXTERN struct acpi_generic_address acpi_gbl_xpm1a_enable;

ACPI_EXTERN struct acpi_generic_address acpi_gbl_xpm1b_status;
ACPI_EXTERN struct acpi_generic_address acpi_gbl_xpm1b_enable;


ACPI_EXTERN struct acpi_table_header *acpi_gbl_DSDT;
ACPI_EXTERN struct acpi_table_header acpi_gbl_original_dsdt_header;

ACPI_EXTERN u8 acpi_gbl_integer_bit_width;
ACPI_EXTERN u8 acpi_gbl_integer_byte_width;
ACPI_EXTERN u8 acpi_gbl_integer_nybble_width;


ACPI_EXTERN acpi_mutex acpi_gbl_osi_mutex;


ACPI_EXTERN struct acpi_rw_lock acpi_gbl_namespace_rw_lock;


ACPI_EXTERN struct acpi_mutex_info acpi_gbl_mutex_info[ACPI_NUM_MUTEX];

ACPI_EXTERN union acpi_operand_object *acpi_gbl_global_lock_mutex;
ACPI_EXTERN acpi_semaphore acpi_gbl_global_lock_semaphore;
ACPI_EXTERN acpi_spinlock acpi_gbl_global_lock_pending_lock;
ACPI_EXTERN u16 acpi_gbl_global_lock_handle;
ACPI_EXTERN u8 acpi_gbl_global_lock_acquired;
ACPI_EXTERN u8 acpi_gbl_global_lock_present;
ACPI_EXTERN u8 acpi_gbl_global_lock_pending;

ACPI_EXTERN acpi_spinlock acpi_gbl_gpe_lock;	
ACPI_EXTERN acpi_spinlock acpi_gbl_hardware_lock;	


#ifdef ACPI_DBG_TRACK_ALLOCATIONS


ACPI_EXTERN struct acpi_memory_list *acpi_gbl_global_list;
ACPI_EXTERN struct acpi_memory_list *acpi_gbl_ns_node_list;
ACPI_EXTERN u8 acpi_gbl_display_final_mem_stats;
#endif


ACPI_EXTERN acpi_cache_t *acpi_gbl_namespace_cache;
ACPI_EXTERN acpi_cache_t *acpi_gbl_state_cache;
ACPI_EXTERN acpi_cache_t *acpi_gbl_ps_node_cache;
ACPI_EXTERN acpi_cache_t *acpi_gbl_ps_node_ext_cache;
ACPI_EXTERN acpi_cache_t *acpi_gbl_operand_cache;


ACPI_EXTERN struct acpi_object_notify_handler acpi_gbl_device_notify;
ACPI_EXTERN struct acpi_object_notify_handler acpi_gbl_system_notify;
ACPI_EXTERN acpi_exception_handler acpi_gbl_exception_handler;
ACPI_EXTERN acpi_init_handler acpi_gbl_init_handler;
ACPI_EXTERN acpi_tbl_handler acpi_gbl_table_handler;
ACPI_EXTERN void *acpi_gbl_table_handler_context;
ACPI_EXTERN struct acpi_walk_state *acpi_gbl_breakpoint_walk;
ACPI_EXTERN acpi_interface_handler acpi_gbl_interface_handler;


ACPI_EXTERN u32 acpi_gbl_owner_id_mask[ACPI_NUM_OWNERID_MASKS];
ACPI_EXTERN u8 acpi_gbl_last_owner_id_index;
ACPI_EXTERN u8 acpi_gbl_next_owner_id_offset;


ACPI_EXTERN u8 acpi_gbl_reg_methods_executed;


ACPI_EXTERN u32 acpi_gbl_original_mode;
ACPI_EXTERN u32 acpi_gbl_rsdp_original_location;
ACPI_EXTERN u32 acpi_gbl_ns_lookup_count;
ACPI_EXTERN u32 acpi_gbl_ps_find_count;
ACPI_EXTERN u16 acpi_gbl_pm1_enable_register_save;
ACPI_EXTERN u8 acpi_gbl_debugger_configuration;
ACPI_EXTERN u8 acpi_gbl_step_to_next_call;
ACPI_EXTERN u8 acpi_gbl_acpi_hardware_present;
ACPI_EXTERN u8 acpi_gbl_events_initialized;
ACPI_EXTERN u8 acpi_gbl_osi_data;
ACPI_EXTERN struct acpi_interface_info *acpi_gbl_supported_interfaces;
ACPI_EXTERN struct acpi_address_range
    *acpi_gbl_address_range_list[ACPI_ADDRESS_RANGE_MAX];

#ifndef DEFINE_ACPI_GLOBALS


extern u8 acpi_gbl_shutdown;
extern u32 acpi_gbl_startup_flags;
extern const char *acpi_gbl_sleep_state_names[ACPI_S_STATE_COUNT];
extern const char *acpi_gbl_lowest_dstate_names[ACPI_NUM_sx_w_METHODS];
extern const char *acpi_gbl_highest_dstate_names[ACPI_NUM_sx_d_METHODS];
extern const struct acpi_opcode_info acpi_gbl_aml_op_info[AML_NUM_OPCODES];
extern const char *acpi_gbl_region_types[ACPI_NUM_PREDEFINED_REGIONS];

#endif


extern char const *acpi_gbl_exception_names_env[];
extern char const *acpi_gbl_exception_names_pgm[];
extern char const *acpi_gbl_exception_names_tbl[];
extern char const *acpi_gbl_exception_names_aml[];
extern char const *acpi_gbl_exception_names_ctrl[];


#if !defined (ACPI_NO_METHOD_EXECUTION) || defined (ACPI_CONSTANT_EVAL_ONLY)
#define NUM_PREDEFINED_NAMES            10
#else
#define NUM_PREDEFINED_NAMES            9
#endif

ACPI_EXTERN struct acpi_namespace_node acpi_gbl_root_node_struct;
ACPI_EXTERN struct acpi_namespace_node *acpi_gbl_root_node;
ACPI_EXTERN struct acpi_namespace_node *acpi_gbl_fadt_gpe_device;
ACPI_EXTERN union acpi_operand_object *acpi_gbl_module_code_list;

extern const u8 acpi_gbl_ns_properties[ACPI_NUM_NS_TYPES];
extern const struct acpi_predefined_names
    acpi_gbl_pre_defined_names[NUM_PREDEFINED_NAMES];

#ifdef ACPI_DEBUG_OUTPUT
ACPI_EXTERN u32 acpi_gbl_current_node_count;
ACPI_EXTERN u32 acpi_gbl_current_node_size;
ACPI_EXTERN u32 acpi_gbl_max_concurrent_node_count;
ACPI_EXTERN acpi_size *acpi_gbl_entry_stack_pointer;
ACPI_EXTERN acpi_size *acpi_gbl_lowest_stack_pointer;
ACPI_EXTERN u32 acpi_gbl_deepest_nesting;
#endif


ACPI_EXTERN struct acpi_thread_state *acpi_gbl_current_walk_list;


ACPI_EXTERN u8 acpi_gbl_cm_single_step;


extern struct acpi_bit_register_info
    acpi_gbl_bit_register_info[ACPI_NUM_BITREG];
ACPI_EXTERN u8 acpi_gbl_sleep_type_a;
ACPI_EXTERN u8 acpi_gbl_sleep_type_b;


extern struct acpi_fixed_event_info
    acpi_gbl_fixed_event_info[ACPI_NUM_FIXED_EVENTS];
ACPI_EXTERN struct acpi_fixed_event_handler
    acpi_gbl_fixed_event_handlers[ACPI_NUM_FIXED_EVENTS];
ACPI_EXTERN struct acpi_gpe_xrupt_info *acpi_gbl_gpe_xrupt_list_head;
ACPI_EXTERN struct acpi_gpe_block_info
*acpi_gbl_gpe_fadt_blocks[ACPI_MAX_GPE_BLOCKS];

#if (!ACPI_REDUCED_HARDWARE)

ACPI_EXTERN u8 acpi_gbl_all_gpes_initialized;
ACPI_EXTERN ACPI_GBL_EVENT_HANDLER acpi_gbl_global_event_handler;
ACPI_EXTERN void *acpi_gbl_global_event_handler_context;

#endif				


ACPI_EXTERN u8 acpi_gbl_db_output_flags;

#ifdef ACPI_DISASSEMBLER

ACPI_EXTERN u8 acpi_gbl_db_opt_disasm;
ACPI_EXTERN u8 acpi_gbl_db_opt_verbose;
#endif

#ifdef ACPI_DEBUGGER

extern u8 acpi_gbl_method_executing;
extern u8 acpi_gbl_abort_method;
extern u8 acpi_gbl_db_terminate_threads;

ACPI_EXTERN u8 acpi_gbl_db_opt_tables;
ACPI_EXTERN u8 acpi_gbl_db_opt_stats;
ACPI_EXTERN u8 acpi_gbl_db_opt_ini_methods;

ACPI_EXTERN char *acpi_gbl_db_args[ACPI_DEBUGGER_MAX_ARGS];
ACPI_EXTERN char acpi_gbl_db_line_buf[80];
ACPI_EXTERN char acpi_gbl_db_parsed_buf[80];
ACPI_EXTERN char acpi_gbl_db_scope_buf[40];
ACPI_EXTERN char acpi_gbl_db_debug_filename[40];
ACPI_EXTERN u8 acpi_gbl_db_output_to_file;
ACPI_EXTERN char *acpi_gbl_db_buffer;
ACPI_EXTERN char *acpi_gbl_db_filename;
ACPI_EXTERN u32 acpi_gbl_db_debug_level;
ACPI_EXTERN u32 acpi_gbl_db_console_debug_level;
ACPI_EXTERN struct acpi_namespace_node *acpi_gbl_db_scope_node;

ACPI_EXTERN u16 acpi_gbl_obj_type_count[ACPI_TYPE_NS_NODE_MAX + 1];
ACPI_EXTERN u16 acpi_gbl_node_type_count[ACPI_TYPE_NS_NODE_MAX + 1];
ACPI_EXTERN u16 acpi_gbl_obj_type_count_misc;
ACPI_EXTERN u16 acpi_gbl_node_type_count_misc;
ACPI_EXTERN u32 acpi_gbl_num_nodes;
ACPI_EXTERN u32 acpi_gbl_num_objects;

ACPI_EXTERN u32 acpi_gbl_size_of_parse_tree;
ACPI_EXTERN u32 acpi_gbl_size_of_method_trees;
ACPI_EXTERN u32 acpi_gbl_size_of_node_entries;
ACPI_EXTERN u32 acpi_gbl_size_of_acpi_objects;

#endif				

#endif				
