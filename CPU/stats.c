#include "spim.h"
#include "stats.h"

stats_t stats;

void stats_reset() {
  stats.instructions_counter = 0;
}

void stats_record_instruction(mem_addr addr) {
  (void)addr;
  stats.instructions_counter += 1;
  return;
}

void stats_print() {
  char message[32];
	sprintf(message, "\n# of executed instructions: %d\n", stats.instructions_counter);
	write_output(message_out, message);
}
