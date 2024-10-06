#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <X11/Xlib.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>  // Include this header for sleep function

/*
 *  Put this in your .xinitrc file: 
 *
 *  barM&
 *  
 */

#define VERSION "0.12"
#define TIME_FORMAT "%A %d-%m-%Y %H:%M:%S "
#define MAXSTR  1024

static const char * date(void);
static const char * battery_status(void);
static void XSetRoot(const char *name);
/* Append here your functions */
static const char*(*const functab[])(void) = {
    battery_status,
    date
};

int main(void) {
    char status[MAXSTR];
    char* off = status;

    if (off >= (status + MAXSTR)) {
        XSetRoot(status);
        return 1; /* This should not happen */
    }

    for (;;) {
        int left = sizeof(status), i;
        char* sta = off;
        for (i = 0; i < sizeof(functab) / sizeof(functab[0]); ++i) {
            int ret = snprintf(sta, left, "%s", functab[i]());
            sta += ret;
            left -= ret;
            if (sta >= (status + MAXSTR)) /* When snprintf has to resort to truncating a string it will return the length as if it were not truncated. */
                break;
            if (i < sizeof(functab) / sizeof(functab[0]) - 1) {
                ret = snprintf(sta, left, " ┃ ");
                sta += ret;
                left -= ret;
            }
        }
        XSetRoot(status);
        sleep(1);
    }
    return 0;
}

/* Returns the date */
static const char * date(void) {
    static char date[MAXSTR];
    time_t now = time(0);

    strftime(date, MAXSTR, TIME_FORMAT, localtime(&now));
    return date;
}

/* Returns the battery status */
static const char * battery_status(void) {
    static char status[MAXSTR];
    FILE *fp;
    int percentage;
    char state[32];
    char ac_online[2];

    /* Check if the battery capacity file exists */
    if (access("/sys/class/power_supply/BAT0/capacity", F_OK) == -1) {
        return "";
    }

    /* Read the battery percentage */
    fp = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    if (fp == NULL) {
        perror("Failed to read battery capacity");
        return "";
    }
    fscanf(fp, "%d", &percentage);
    fclose(fp);

    /* Check if the battery status file exists */
    if (access("/sys/class/power_supply/BAT0/status", F_OK) == -1) {
        return "";
    }

    /* Read the battery status */
    fp = fopen("/sys/class/power_supply/BAT0/status", "r");
    if (fp == NULL) {
        perror("Failed to read battery status");
        return "";
    }
    fscanf(fp, "%s", state);
    fclose(fp);

    /* Check if the AC online file exists and read its value */
    if (access("/sys/class/power_supply/AC/online", F_OK) == 0) {
        fp = fopen("/sys/class/power_supply/AC/online", "r");
        if (fp != NULL) {
            fscanf(fp, "%1s", ac_online);
            fclose(fp);
        }
    }

    if (strcmp(ac_online, "1") == 0) {
        snprintf(status, MAXSTR, "Battery: %d%% (⚡)", percentage);
    } else {
        snprintf(status, MAXSTR, "Battery: %d%%", percentage);
    }

    return status;
}

static void XSetRoot(const char *name) {
    Display *display;

    if (( display = XOpenDisplay(0x0)) == NULL ) {
        fprintf(stderr, "[barM] cannot open display!\n");
        exit(1);
    }

    XStoreName(display, DefaultRootWindow(display), name);
    XSync(display, 0);

    XCloseDisplay(display);
}

