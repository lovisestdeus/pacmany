#include "../h/main.h"

#if defined(__linux__)
#include <unistd.h>

static int file_check(char file_name[25]){
  if (access(file_name, F_OK) != -1)
    return TRUE;
  else
    return FALSE;
  return 0;
}

static char *check_distro(){
  if (file_check("/etc/SuSe-release") == TRUE)
    return "suse";
  if (file_check("/etc/fedora-release") == TRUE)
    return "fedora";
  if (file_check("/etc/redhat-release") == TRUE)
    return "redhat";
  if (file_check("/etc/slackware-release") == TRUE)
    return "slackware";
  if (file_check("/etc/os-release") == TRUE)
    return "debian";
  if (file_check("/etc/debian_release") == TRUE)
    return "fedora";
  if (file_check("/etc/mandrake-release") == TRUE)
    return "mandrake";
  if (file_check("/etc/yellowdog-release") == TRUE)
    return "yellowdog";
  if (file_check("/etc/sun-release") == TRUE)
    return "sun";
  if (file_check("/etc/release") == TRUE)
    return "solaris";
  if (file_check("/etc/gentoo-release") == TRUE)
    return "gentoo";
  else
    return "other";
}

int main(int c, char *v[]){
  printf("==> it's not stable yet!\n");
  printf("==> your distro is: %s\n", check_distro());
  if (c == 0)
    return 1;
  for (int i=1; i<c; i++){
    if (check_distro() != "other"){
      if (strcmp(v[i], "-S") == 0){ // install command
	if (strcmp(check_distro(), "fedora") == 0 ||
	    strcmp(check_distro(), "redhat") == 0){
	  char cmd[25] = "sudo dnf in ";
	  strcat(cmd, v[i+1]);
	  system(cmd);
	}
	if (strcmp(check_distro(), "debian") == 0){
	  char cmd[25] = "sudo apt install ";
	  strcat(cmd, v[i+1]);
	  system(cmd);
	}
	if (strcmp(check_distro(), "suse") == 0){
	  char cmd[25] = "sudo zypper in ";
	  strcat(cmd, v[i+1]);
	  system(cmd);
	}
      }
      if (strcmp(v[i], "-Syu") == 0){ // update command
	if (strcmp(check_distro(), "fedora") == 0 ||
	    strcmp(check_distro(), "redhat") == 0){
	  char cmd[25] = "sudo dnf update";
	  system(cmd);
	}
	if (strcmp(check_distro(), "debian") == 0){
	  char cmd[25] = "sudo apt update";
	  system(cmd);
	}
	if (strcmp(check_distro(), "suse") == 0){
	  char cmd[25] = "sudo zypper up";
	  system(cmd);
	}
      }
      if (strcmp(v[i], "-Runs") == 0){ // remove command
	if (strcmp(check_distro(), "fedora") == 0 ||
	    strcmp(check_distro(), "redhat") == 0){
	  char cmd[25] = "sudo dnf erase ";
	  strcat(cmd, v[i+1]);
	  system(cmd);
	}
	if (strcmp(check_distro(), "debian") == 0){
	  char cmd[25] = "sudo apt purge ";
	  strcat(cmd, v[i+1]);
	  system(cmd);
	}
	if (strcmp(check_distro(), "suse") == 0){
	  char cmd[25] = "sudo zypper remove ";
	  strcat(cmd, v[i+1]);
	  system(cmd);
	}
      }
    } else {
      printf("couldn't detect distro\n");
    }
  }
  return 0;
}
#endif // linux

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
#include <conio.h>

int main(void){
  printf("windows is unsupported\n");
  getch();
  return 0;
}
#endif // windows
