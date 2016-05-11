#define SIZE_OF_INSTRUCTIONS_COUNTER 1024

typedef struct stats_s {
  int instructions_counter[SIZE_OF_INSTRUCTIONS_COUNTER];
} stats_t;

void stats_reset();
void stats_record_instruction(instruction* inst);
void stats_print();

extern bool show_stats;           /* => show execution stats */
