typedef struct stats_s {
  int instructions_counter;
} stats_t;

void stats_reset();
void stats_record_instruction(mem_addr addr);
void stats_print();

extern bool show_stats;           /* => show execution stats */
