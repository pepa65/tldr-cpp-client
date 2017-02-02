/*
 * tldr.h
 *
 * Copyright (C) 2016 Arvid Gerstmann
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#ifndef TLDR_H
#define TLDR_H

#include <stdlib.h>

#define STRBUFSIZ 512
#define URLBUFSIZ 1024

#define BASE_URL "https://raw.github.com/tldr-pages/tldr/master/pages"
#define BASE_URL_LEN (sizeof(BASE_URL) - 1)

#define ZIP_URL "https://github.com/tldr-pages/tldr/archive/master.zip"
#define ZIP_URL_LEN (sizeof(ZIP_URL_LEN) - 1)

#define TMP_DIR "/tmp/tldrXXXXXX"
#define TMP_DIR_LEN (sizeof(TMP_DIR) - 1)

#define TMP_FILE "/master.zip"
#define TMP_FILE_LEN (sizeof(TMP_FILE) - 1)

#define TLDR_DIR "/tldr-master"
#define TLDR_DIR_LEN (sizeof(TLDR_DIR) - 1)

#define TLDR_HOME "/.tldrc"
#define TLDR_HOME_LEN (sizeof(TLDR_HOME) - 1)

#define TLDR_DATE "/.tldrc/date"
#define TLDR_DATE_LEN (sizeof(TLDR_DATE) - 1)

/* #define TLDR_EXT "/.tldrc/tldr-master/pages/" */
#define TLDR_EXT "/.tldr/cache/pages/"
#define TLDR_EXT_LEN (sizeof(TLDR_EXT) - 1)

/* Character colors */
#define BLACK                                   "\x1b[30m"
#define RED                                     "\x1b[31m"
#define GREEN                                   "\x1b[32m"
#define YELLOW                                  "\x1b[33m"
#define BLUE                                    "\x1b[34m"
#define MAGENTA                                 "\x1b[35m"
#define CYAN                                    "\x1b[36m"
#define WHITE                                   "\x1b[37m"
#define DEFAULT                                 "\x1b[39m"

/* Background colors */
#define BLACK_B                                 "\x1b[40m"
#define RED_B                                   "\x1b[41m"
#define GREEN_B                                 "\x1b[42m"
#define YELLOW_B                                "\x1b[43m"
#define BLUE_B                                  "\x1b[44m"
#define MAGENTA_B                               "\x1b[45m"
#define CYAN_B                                  "\x1b[46m"
#define WHITE_B                                 "\x1b[47m"

/* Style elements */
#define B                   /*  BOLD       */   "\x1b[1m"
#define DIM                                     "\x1b[2m"
#define U                   /*  UNDERLINE  */   "\x1b[4m"
#define BLINK                                   "\x1b[5m"
#define REVERSE                                 "\x1b[7m"

/* Reset all styles */
#define X_S                 /*  RESET      */   "\x1b[0m"

/* Document styles */
#define TITLE_S             /*   # ____    */   B YELLOW
#define DESCRIPTION_S       /*   > ____.   */   YELLOW
#define EXAMPLE_S           /*   - ____:   */   B GREEN
#define COMMAND_S           /*   `____`    */   B BLUE
#define VALUE_S             /*   {{____}}  */   BLACK_B B BLUE

/* Output styles */
#define MSG_S                                   B GREEN
#define ERR_S                                   B RED
#define URL_S                                   B YELLOW
#define B_S                                     B WHITE
#define I_S                                     B CYAN

/* local.c */
long        check_localdate         (void);
int         update_localdate        (void);
int         has_localdb             (void);
int         update_localdb          (int verbose);
int         clear_localdb           (int verbose);
int         get_file_content        (char const *path, char **out, int verbose);

/* net.c */
int         download_file           (char const *url, char const *outfile,
                                     int verbose);
int         download_content        (char const *url, char **out, int verbose);

/* parser.c */
int         construct_url           (char *buf, size_t buflen,
                                     char const *input,
                                     char const *platform);
int         construct_path          (char *buf, size_t buflen, char const *home,
                                     char const *input, char const *platform);
int         parse_tldrpage          (char const *input);
int         print_tldrpage          (char const *input, char const *platform);
int         print_localpage         (char const *path);

/* utils.c */
#define RMOPT_IGNORE_NOFILE     (0x1)

double      rround              (double arg);
int         rm                  (char const *path, int options);
int         unzip               (char const *path, char const *outpath);
char const *gethome             (void);
int         sstrncat            (char *dest, size_t *pos, size_t max,
                                 char const *src, size_t len);
#endif /* TLDR_H */
