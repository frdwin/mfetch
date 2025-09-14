#include <stdio.h>
#include <string.h>

int fetch_uptime(char *uptime)
{
  // Open /proc/uptime and check for errors.
	FILE *f = fopen("/proc/uptime", "r");
	if (f == NULL)
	  return -1;

	// Extract the content of f into an array.
	double content[2];
	if (fscanf(f, "%lf %lf", &content[0], &content[1]) != 2)
	{
	  fclose(f);
	  return -1;
	}

	// Convert seconds to hours and minutes.
	int hours = content[0] / 3600;
  content[0] -= (hours * 3600);
	int minutes = content[0] / 60;
  int seconds = content[0] - (minutes * 60);

	if (sprintf(uptime, "%dh %dm %ds", hours, minutes, seconds) == 0)
	{
	  fclose(f);
	  return -1;
	}

	fclose(f);
	return 0;
}
