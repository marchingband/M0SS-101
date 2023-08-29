
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/startup/riscv_fpu.S" "C:/Users/youth/bouffalo_sdk/examples/peripherals/andy/audac_play_from_mem/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/riscv_fpu.S.obj"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/startup/start.S" "C:/Users/youth/bouffalo_sdk/examples/peripherals/andy/audac_play_from_mem/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start.S.obj"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/startup/vector.S" "C:/Users/youth/bouffalo_sdk/examples/peripherals/andy/audac_play_from_mem/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/vector.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "ARCH_RISCV"
  "BFLB_TIMESTAMP_TIMEZONE=8"
  "BFLB_USE_HAL_DRIVER"
  "BFLB_USE_ROM_DRIVER"
  "BL616"
  "CONFIG_IRQ_NUM=80"
  "CONFIG_LIBC_FLOAT=1"
  "CONFIG_LIBC_FLOAT_EX=1"
  "CONFIG_LIBC_LONG_LONG=1"
  "CONFIG_LOG_LEVEL=3"
  "CONFIG_TLSF"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "C:/Users/youth/bouffalo_sdk/bsp/board/bl616dk/."
  "C:/Users/youth/bouffalo_sdk/components/libc/newlib/."
  "C:/Users/youth/bouffalo_sdk/components/libc/."
  "C:/Users/youth/bouffalo_sdk/components/mm/."
  "C:/Users/youth/bouffalo_sdk/components/mm/tlsf/."
  "C:/Users/youth/bouffalo_sdk/components/utils/log"
  "C:/Users/youth/bouffalo_sdk/components/utils/ring_buffer"
  "C:/Users/youth/bouffalo_sdk/components/utils/bflb_block_pool"
  "C:/Users/youth/bouffalo_sdk/components/utils/bflb_timestamp"
  "C:/Users/youth/bouffalo_sdk/components/utils/getopt"
  "C:/Users/youth/bouffalo_sdk/drivers/lhal/include"
  "C:/Users/youth/bouffalo_sdk/drivers/lhal/include/arch"
  "C:/Users/youth/bouffalo_sdk/drivers/lhal/include/arch/risc-v/t-head"
  "C:/Users/youth/bouffalo_sdk/drivers/lhal/include/arch/risc-v/t-head/Core/Include"
  "C:/Users/youth/bouffalo_sdk/drivers/lhal/config/bl616"
  "C:/Users/youth/bouffalo_sdk/drivers/lhal/src/flash"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/include"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/include/hardware"
  "C:/Users/youth/bouffalo_sdk/examples/peripherals/andy/audac_play_from_mem/."
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/port/bl616_clock.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/port/bl616_clock.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/port/bl616_clock.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_aon.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_aon.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_aon.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_common.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_common.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_common.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_ef_cfg.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_ef_cfg.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_ef_cfg.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_pm.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_pm.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_pm.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_psram.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_psram.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_psram.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_romapi_e907.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_e907.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_e907.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_romapi_patch.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_patch.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_patch.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_sdh.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_sdh.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_sdh.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/src/bl616_tzc_sec.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_tzc_sec.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_tzc_sec.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/startup/interrupt.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/interrupt.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/interrupt.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/startup/start_load.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start_load.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start_load.c.obj.d"
  "C:/Users/youth/bouffalo_sdk/drivers/soc/bl616/std/startup/system_bl616.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/system_bl616.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/system_bl616.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
