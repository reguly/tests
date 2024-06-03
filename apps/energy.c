#include <unistd.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

//RAPL energy measurements
long long *energy_counters = NULL;
char **energy_paths = NULL;
int energy_paths_count = 0;

void initialize_rapl() {
//Initialize RAPL counters
	char default_paths[128];
	strcpy(&default_paths[0],"/sys/devices/virtual/powercap/intel-rapl/intel-rapl:0/energy_uj;/sys/devices/virtual/powercap/intel-rapl/intel-rapl:1/energy_uj");
	char* env_paths = getenv("RAPL_PATH");
	if (!env_paths) {
		env_paths = default_paths;
	}
	energy_paths_count = 0;
	if (env_paths) {
		// Count the number of paths
		int num_paths = 0;
		char* path = strtok(env_paths, ";");
		while (path != NULL) {
			num_paths++;
			path = strtok(NULL, ";");
		}

		// Read the paths and initial energies
		energy_paths_count = num_paths;
		energy_paths = (char**)malloc(sizeof(char*)*num_paths);
		energy_counters = (long long*)malloc(sizeof(long long)*num_paths);

		num_paths = 0;
		path = strtok(env_paths, ";");
		while (path != NULL) {
			energy_paths[num_paths] = strdup(path); // Duplicate the string for safekeeping
			//check if path exists
			if (access(path, R_OK) == -1) {
				if (env_paths != default_paths)
					printf("Error: RAPL path %s does not exist or does not have the right permissions. Skipping.\n", path);
				energy_paths[num_paths] = NULL;
			} else {
				// Read initial energy
				FILE* file = fopen(path, "r");
				if (file == NULL) {
					if (env_paths != default_paths)
						printf("Error: Could not open RAPL path %s. Skipping.\n", path);
				} else {
					fscanf(file, "%lld", &energy_counters[num_paths]);
					fclose(file);
				}
			}
			num_paths++;
			path = strtok(NULL, ";");
		}
	} 
}

void report_rapl() {
long long aggregate_energy = 0;
long long max_energy = 262143328850LL;
  for (int i = 0; i < energy_paths_count; i++) {
    if (energy_paths[i] != NULL) {
      FILE* file = fopen(energy_paths[i], "r");
      if (file == NULL) {
          printf("Error: Could not open RAPL path %s. Skipping.\n", energy_paths[i]);
      } else {
        long long energy;
        fscanf(file, "%lld", &energy);
		if (energy < energy_counters[i]) {
			// Energy counter has wrapped around.
			char max_energy_filename[128];
			strcpy(max_energy_filename, energy_paths[i]);
			char* substring = strstr(max_energy_filename, "energy_uj");
			if (substring != NULL) {
				strncpy(substring, "max_energy_range_uj", strlen("max_energy_range_uj"));
			}
			FILE *max_energy_file = fopen(max_energy_filename, "r");
			if (max_energy_file != NULL) {
				fscanf(max_energy_file, "%lld", &max_energy);
				fclose(max_energy_file);
			}
			aggregate_energy += (max_energy - energy_counters[i] + energy);
		} else
        	aggregate_energy += (energy - energy_counters[i]);
        fclose(file);
      }
    }
  }
  if (aggregate_energy > 0) {
    double aggregate_energy_d = (double)aggregate_energy/1000000.0;
    printf("Total CPU energy consumed (REPL): %g J\n", aggregate_energy_d);
  }
}
