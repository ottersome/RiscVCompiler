#ifndef DEBUGHEADER_H
#define DEBUGHEADER_H
#ifdef DEBUG
#define Logg(s) printf("%s", s)
#else
#define Logg(s)
#endif
#endif
