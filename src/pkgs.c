#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <sqlite3.h>

unsigned int read_pkgs_file(const char *f_path, char *search_expr)
{
  // Open the pkgs database instead of run a new instance of the package manager.
  // and check for errors.
  FILE *f = fopen(f_path, "r");
  if (f == NULL)
    return -1;
  
  char buf[1024];
  unsigned int counter = 0;

  while (fgets(buf, sizeof buf, f) != NULL)
  {
    const char *ptr = buf;
    while ((ptr = strstr(ptr, search_expr)) != NULL)
    {
      counter++;
      ptr += strlen(search_expr);
    }
  }
  
  fclose(f);
  return counter;
}

int fetch_pkgs(char *os_name, int *pkgs)
{
  // Void.
  if (strcasecmp(os_name, "void") == 0)
    *pkgs = read_pkgs_file("/var/db/xbps/pkgdb-0.38.plist", "<string>installed</string>");
  
  // Debian based.
  if (strcmp(os_name, "debian") == 0 ||
      strcmp(os_name, "ubuntu") == 0 ||
      strcmp(os_name, "popos") == 0)
    *pkgs = read_pkgs_file("/var/lib/dpkg/status", "Package:");

  // Redhat based.
  if (strcmp(os_name, "rhel") == 0 ||
      strcmp(os_name, "fedora") == 0 ||
      strcmp(os_name, "almalinux") == 0)
  {
    sqlite3 *db;
    int status;

    // Connect to sqlite database and check for error.
    status = sqlite3_open("/var/lib/rpm/rpmdb.sqlite", &db);
    if (status != 0)
      return -1;

    // SQL query to find installed packages.
    const char *query = "SELECT COUNT(*) FROM Packages;";

    sqlite3_stmt *stmt;
    status = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (status != SQLITE_OK)
    {
      sqlite3_close(db);
      return -1;
    }

    status = sqlite3_step(stmt);
    if (status != SQLITE_ROW)
    {
      sqlite3_close(db);
      return -1;
    }

    *pkgs = sqlite3_column_int(stmt, 0);

    status = sqlite3_finalize(stmt);
    if (status != SQLITE_OK)
    {
      sqlite3_close(db);
      return -1;
    }

    status = sqlite3_close(db);
    if (status != SQLITE_OK)
    {
      sqlite3_close(db);
      return -1;
    }
  }

  return 0;
}

