#include "spim.h"
#include "string-stream.h"
#include "inst.h"
#include "spim-utils.h"
#include "stats.h"
#include "parser_yacc.h"

stats_t stats;

void stats_reset() {
  for (int i = 0; i < SIZE_OF_INSTRUCTIONS_COUNTER; i++) {
    stats.instructions_counter[i] = 0;
  }
}

void stats_record_instruction(instruction* inst) {
  stats.instructions_counter[OPCODE(inst)]++;
  return;
}

void stats_print() {
  int all_instructions_counter;
  int memory_instructions_counter = 0;
  int other_instructions_counter = 0;

  char message[64];

  for (int i = 0; i < SIZE_OF_INSTRUCTIONS_COUNTER; i++) {
    int count = stats.instructions_counter[i];
    if (count == 0) continue;
    switch (i) {
    case Y_LB_OP:
    case Y_LBU_OP:
    case Y_LD_POP:
    case Y_LH_OP:
    case Y_LHU_OP:
    case Y_LL_OP:
    case Y_LW_OP:
    case Y_LWC1_OP:
    case Y_LWL_OP:
    case Y_LWR_OP:
    case Y_SB_OP:
    case Y_SC_OP:
    case Y_SD_POP:
    case Y_SH_OP:
    case Y_SW_OP:
    case Y_SWC1_OP:
    case Y_SDC1_OP:
    case Y_SWL_OP:
    case Y_SWR_OP:
    case Y_ULH_POP:
    case Y_ULHU_POP:
    case Y_ULW_POP:
    case Y_USH_POP:
    case Y_USW_POP:
      memory_instructions_counter += count;
      break;
    default:
      other_instructions_counter += count;
    }
  }

  all_instructions_counter = memory_instructions_counter + other_instructions_counter;

  write_output(message_out, "\n--- Summary ---\n");
  write_output(message_out, "# of executed instructions\n");
  snprintf(message, sizeof(message), "- Total:  %4d\n", all_instructions_counter);
  write_output(message_out, message);
  snprintf(message, sizeof(message), "- Memory: %4d\n", memory_instructions_counter);
  write_output(message_out, message);
  snprintf(message, sizeof(message), "- Others: %4d\n", other_instructions_counter);
  write_output(message_out, message);

  write_output(message_out, "\n--- Details ---\n");
  for (int i = 0; i < SIZE_OF_INSTRUCTIONS_COUNTER; i++) {
    if (stats.instructions_counter[i] == 0) continue;
    name_val_val *entry = get_entry_for_opcode(i);
    if (entry == NULL) continue;
    snprintf(message, sizeof(message), "%10s\t%8d\n", entry->name, stats.instructions_counter[i]);
    write_output(message_out, message);
  }
}
