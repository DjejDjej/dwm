/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";


static const char *colorname[NUMCOLS] = {
    [INIT] = "/home/jiri/dwm/slock/images/lock.png",
    [INPUT] =  "/home/jiri/dwm/slock/images/unlock.png",
    [FAILED] =  "/home/jiri/dwm/slock/images/wrong.png",
};



/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
